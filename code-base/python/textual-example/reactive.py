from textual.app import App, ComposeResult
from textual.reactive import reactive
from textual.widget import Widget
from textual.widgets import Input, Rule


class Name(Widget):

    my_name = reactive("User", layout=True)

    def render(self):
        return f"Hello {self.my_name}"


class MyApp(App):
    CSS_PATH = "css/reactive.css"

    def compose(self) -> ComposeResult:
        yield Input(placeholder="Enter your name")
        yield Rule()
        yield Name()

    def on_input_changed(self, event: Input.Changed) -> None:
        self.query_one(Name).my_name = event.value


if __name__ == "__main__":
    app = MyApp()
    app.run()
