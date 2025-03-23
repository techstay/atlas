from datetime import datetime

from textual.app import App
from textual.reactive import reactive
from textual.widgets import Digits


class MyApp(App):
    CSS_PATH = "css/reactive.css"
    time: reactive[datetime] = reactive(
        datetime.now(),
        recompose=True,
    )

    def compose(self):
        yield Digits(f"{self.time:%X}")

    def on_mount(self):
        self.set_interval(1, self.update_time)

    def update_time(self):
        self.time = datetime.now()


if __name__ == "__main__":
    app = MyApp()
    app.run()
