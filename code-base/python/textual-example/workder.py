import asyncio
import random

from textual import work
from textual.app import App, ComposeResult
from textual.containers import Horizontal
from textual.widgets import Button, ProgressBar, Static


class MyApp(App):
    CSS_PATH = "css/worker.css"

    def compose(self) -> ComposeResult:
        yield ProgressBar(total=100, show_eta=False, show_percentage=False)
        with Horizontal(classes="horizontal"):
            yield Button("Click me!")
        yield Static(id="text")

    def on_mount(self) -> None:
        self.timer = self.set_interval(1 / 10, self.update_progress, pause=True)

    def update_progress(self) -> None:
        progress_bar = self.query_one(ProgressBar)
        n = random.randint(1, 20)
        progress_bar.advance(n)

    async def on_button_pressed(self) -> None:
        self.long_work()
        self.query_one(ProgressBar).update(progress=0)
        widget = self.query_one("#text", Static)
        widget.update("Processing...")
        self.timer.resume()

    @work(exclusive=True)
    async def long_work(self):
        await asyncio.sleep(1)
        widget = self.query_one("#text", Static)
        widget.update("Done!")


if __name__ == "__main__":
    app = MyApp()
    app.run()
