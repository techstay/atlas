import hrequests
import rich
from loguru import logger


# Extracting gamersky anime introductions
def extract_anime_names() -> list[str]:
    with hrequests.chrome.Session(os="win") as session:
        url = "https://www.gamersky.com/news/201307/285819.shtml"
        names = []
        logger.info("Start to extract anime names...")
        while True:
            resp = session.get(url)
            html = resp.html

            article = html.find("div.Mid2_L")
            names.extend([i.text.strip() for i in article.find_all("strong")])

            next_page = html.find_all("div.page_css a")[-1]
            if next_page and next_page.text.strip() == "下一页":
                url = next_page.href
                logger.info("Next page: {}", url)
            else:
                logger.info("Extract finished.")
                break

        logger.info("Extracted {} anime names.", len(names))
        return names


if __name__ == "__main__":
    names = extract_anime_names()
    rich.print(names)
