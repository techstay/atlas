from textual.app import App
from textual.widgets import Button, Static


class MyApp(App):
    CSS_PATH = "css/buttons.css"

    def compose(self):
        yield Static(id="box")
        yield Button("Animate", id="animate")

    def on_mount(self):
        box = self.query_one("#box")
        box.styles.background = "#ff0000"
        box.styles.height = 4

    def on_button_pressed(self, event: Button.Pressed) -> None:
        box = self.query_one("#box")
        box.styles.animate("background", "green", duration=1)


if __name__ == "__main__":
    app = MyApp()
    app.run()
