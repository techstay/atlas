import asyncio
from pathlib import Path

import hrequests
import rich
from httpx import AsyncClient, HTTPError
from loguru import logger
from rich.progress import Progress

url = r"https://everia.club/2023/12/08/yeha-%EC%98%88%ED%95%98-pure-media-vol-265-hungry-bitch-in-the-stairwell-set-01/"


def extract_image_links(url: str):
    with hrequests.chrome.Session(os="win") as session:
        resp = session.get(url)
        html = resp.html
        title = html.find(".single-post-title.entry-title").text.strip()
        images = html.find_all("figure.wp-block-image.size-large>img")
        image_urls = [i.attrs["src"] for i in images]

        print(f"{title}")
        # rich.print(image_urls)
        return image_urls


async def download_images(image_urls: list[str]):
    save_dir = Path("./images")
    save_dir.mkdir(exist_ok=True)
    async with AsyncClient(follow_redirects=True) as client:
        tasks = []
        with Progress(transient=True) as progress:
            for url in image_urls:
                filename = url.split("/")[-1]
                save_path = save_dir / filename
                if not save_path.exists():
                    tasks.append(
                        download_image(
                            url,
                            save_path,
                            client,
                            progress,
                        )
                    )
            results = await asyncio.gather(*tasks, return_exceptions=True)
            exceptions = [result for result in results if isinstance(result, HTTPError)]
            if exceptions:
                logger.error(f"Here are {len(exceptions)} exceptions:")
                rich.print(exceptions)


async def download_image(
    url: str,
    save_path: Path,
    client: AsyncClient,
    progress: Progress,
):
    try:
        async with client.stream("GET", url) as resp:
            resp.raise_for_status()
            download_task = progress.add_task(
                f"Downloading {save_path.name}...",
                total=int(resp.headers["Content-Length"]),
            )
            with save_path.open("wb") as file:
                async for chunk in resp.aiter_bytes():
                    file.write(chunk)
                    progress.update(download_task, completed=resp.num_bytes_downloaded)
    except Exception as e:
        raise HTTPError(f"Failed to download {url}\n\n{e}")


async def main():
    links = extract_image_links(url)
    await download_images(links)


if __name__ == "__main__":
    asyncio.run(main())
