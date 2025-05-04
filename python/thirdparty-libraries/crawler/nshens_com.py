from pathlib import Path

import hrequests
from httpx import Client
from loguru import logger
from rich.progress import Progress

url = r"https://nshens.com/web/2025/04/21/xiurenno-10133%E6%9E%97%E8%8B%A5%E5%87%A1f"
if url.endswith("/"):
    url = url[:-1]

title: str = ""


def extract_image_links(url: str):
    with hrequests.firefox().Session(os="win") as session:
        resp = session.get(url)
        with resp.render(mock_human=True, headless=True, block_images=True) as page:
            container = page.find("div.v-card.v-sheet")
            global title
            title = container.find("h3").text.strip()
            logger.info(title)

            # Getting total pages
            div_outer = container.find("div.text-center")
            div_inner = div_outer.find_all("div.item")
            total_pages = len(div_inner) - 1
            logger.info("Total Pages : {}", total_pages)

            image_links = []
            # Finding out how to extract image links really sucks
            for i in range(1, total_pages + 1):
                logger.debug(f"Fetching Page {i}...")
                page.goto(f"{url}/{i}")
                page.awaitNavigation()
                page.awaitSelector("div.v-card.v-sheet a")
                container = page.find("div.v-card.v-sheet")
                links = [a.attrs["href"] for a in container.find_all("a")]
                links = [
                    link for link in links if link.startswith("https://s.lovestatic")
                ]
                image_links.extend(links)

            return image_links


def download_images(image_urls: list[str]):
    global title
    save_dir = Path(f"./images/{title}")
    save_dir.mkdir(exist_ok=True, parents=True)
    with Client(follow_redirects=True) as client:
        with Progress(transient=True) as progress:
            for url in image_urls:
                filename = url.split("/")[-1]
                save_path = save_dir / filename
                if not save_path.exists():
                    download_image(url, save_path, client, progress)


def download_image(
    url: str,
    save_path: Path,
    client: Client,
    progress: Progress,
):
    try:
        with client.stream("GET", url) as resp:
            resp.raise_for_status()
            download_task = progress.add_task(
                f"Downloading {save_path.name}...",
                total=int(resp.headers["Content-Length"]),
            )
            with save_path.open("wb") as file:
                for chunk in resp.iter_bytes():
                    file.write(chunk)
                    progress.update(download_task, completed=resp.num_bytes_downloaded)
    except Exception as e:
        logger.error(e)
        raise


def main():
    images = extract_image_links(url)
    download_images(images)


if __name__ == "__main__":
    main()
