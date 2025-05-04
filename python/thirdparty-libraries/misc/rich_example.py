import time

from rich.progress import Progress, track

for i in track(
    range(10),
    description="Processing...",
    transient=True,
):
    time.sleep(0.2)


with Progress(transient=True) as progress:
    task1 = progress.add_task("Downloading...", total=10)

    while not progress.finished:
        progress.update(task1, advance=2)
        time.sleep(0.3)
