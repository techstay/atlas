from pathlib import Path
from pprint import pprint

import feedparser
import httpx

rss_url = "https://feeds.washingtonpost.com/rss/world"
save_path = Path("rss.xml")

if not save_path.exists():
    response = httpx.get(url=rss_url, follow_redirects=True)
    save_path.write_text(data=response.text)


d = feedparser.parse(save_path)

# print(type(d.etag), d.etag)
# print(type(d.modified), d.modified)

for item in d.entries[:1]:
    pprint(item)

    pprint(item.title)
    pprint(item.summary)
    pprint(item.link)
    pprint(item.published)
