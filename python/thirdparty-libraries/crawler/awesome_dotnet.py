import asyncio
import csv
import os
import re
from typing import TypedDict

import httpx
import rich
from httpx import ConnectError, ConnectTimeout
from loguru import logger
from rich import print as pprint
from rich.progress import Progress, TaskID

#
# This script will fetch all projects from awesome-dotnet and find the 10 most popular ones
#

GITHUB_TOKEN = os.getenv("GITHUB_TOKEN", "")

if not GITHUB_TOKEN:
    raise ValueError("Please set the environment variable GITHUB_TOKEN.")

awesome_dotnet_url = (
    "https://raw.githubusercontent.com/quozd/awesome-dotnet/master/README.md"
)


class RepoInfo(TypedDict):
    name: str
    url: str
    stars: int
    category: str


headers = {
    "Accept": "application/vnd.github+json",
    "Authorization": f"Bearer {GITHUB_TOKEN}",
}

async_client = httpx.AsyncClient(
    headers=headers,
    follow_redirects=True,
    timeout=30,
)


def extract_repos():
    resp = httpx.get(awesome_dotnet_url)
    markdown_text = resp.text

    # Just split markdown contents brutely

    # Extracting sections between two level 2 headers
    pattern = r"##\s+(.+?)\n(.*?)(?=\n##|\Z)"
    sections = re.findall(pattern, markdown_text, re.DOTALL)
    github_prefix = "https://github.com/"
    repo_infos: list[RepoInfo] = []
    for section in sections:
        section_name = section[0]
        contents = section[1]

        # match markdown links, like: `* [name](https://github.com/quozd/awesome-dotnet)`
        pattern = re.compile(r"\* \[(\S*)\]\((\S*)\)")
        matches = pattern.finditer(contents)
        links = (m.group(2) for m in matches)
        for link in links:
            # Filter all repos with full names: owner/repo
            if link.startswith(github_prefix):
                repo_name = link[len(github_prefix) :]
                if repo_name.endswith("/"):
                    repo_name = repo_name[:-1]
                group = repo_name.split("/")
                if len(group) == 2 and len(group[0]) > 0 and len(group[1]) > 0:
                    repo_infos.append(
                        RepoInfo(
                            name=repo_name,
                            category=section_name,
                            url="",
                            stars=0,
                        )
                    )
    return repo_infos


async def get_repo_info(repo: RepoInfo, progress: Progress, task: TaskID):
    try:
        url = f"https://api.github.com/repos/{repo['name']}"
        resp = await async_client.get(url)
        resp.raise_for_status()
        json = resp.json()
        return RepoInfo(
            name=json["full_name"],
            url=json["html_url"],
            stars=json["stargazers_count"],
            category=repo["category"],
        )
    except ConnectError:
        message = f"Failed to fetch info of {repo['name']}"
        raise ConnectError(message)
    except ConnectTimeout:
        message = f"Failed to fetch info of {repo['name']}"
        raise ConnectTimeout(message)
    finally:
        progress.update(task, advance=1)


def save_to_file(repo_infos: list[RepoInfo]):
    with open("awesome-dotnet.csv", "w+", encoding="utf-8") as file:
        writer = csv.DictWriter(
            file,
            fieldnames=RepoInfo.__annotations__.keys(),
            lineterminator="\n",
        )
        writer.writeheader()
        writer.writerows((i for i in repo_infos))


async def main():
    repos = extract_repos()
    logger.info(f"Found {len(repos)} repos.")
    with Progress(transient=True) as progress:
        task = progress.add_task("Fetching data...", total=len(repos))
        results = await asyncio.gather(
            *[get_repo_info(repo, progress, task) for repo in repos],
            return_exceptions=True,
        )
    logger.info("Done fetching data...")

    repo_infos = []
    exceptions = []

    for result in results:
        if isinstance(result, dict):
            repo_infos.append(result)
        else:
            exceptions.append(result)

    logger.info(f"Found {len(repo_infos)} repos with information.")

    sorted_repo_infos = sorted(repo_infos, key=lambda x: x["stars"], reverse=True)
    save_to_file(sorted_repo_infos)
    pprint(sorted_repo_infos[:10])

    if exceptions:
        logger.error(f"Here are {len(exceptions)} exceptions:")
        rich.print(exceptions)


if __name__ == "__main__":
    asyncio.run(main())
