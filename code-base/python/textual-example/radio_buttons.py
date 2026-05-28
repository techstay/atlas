from textual.app import App
from textual.containers import Container
from textual.widgets import RadioButton, RadioSet


class MyApp(App):
    CSS_PATH = "./css/radio_buttons.css"

    def compose(self):
        yield Container(
            RadioSet(
                RadioButton("One"),
                RadioButton("Two", id="radio2"),
                RadioButton("Three"),
            ),
            classes="container",
        )

    def on_mount(self):
        self.query_one("#radio2", RadioButton).value = True

    def on_radio_set_changed(self, event: RadioSet.Changed):
        self.notify(f"{event.pressed.label} was selected!", severity="information")


if __name__ == "__main__":
    app = MyApp()
    app.run()
