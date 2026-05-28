from textual.app import App, ComposeResult
from textual.screen import Screen
from textual.widgets import Footer, Static


class Screen1(Screen):
    BINDINGS = [("escape", "app.pop_screen", "Pop screen")]

    def compose(self) -> ComposeResult:
        yield Static("Screen 1")
        yield Footer()


class Screen2(Screen):
    BINDINGS = [("escape", "app.pop_screen", "Pop screen")]

    def compose(self) -> ComposeResult:
        yield Static("Screen 2")
        yield Footer()


class MyApp(App):
    CSS_PATH = "css/helloworld.css"
    SCREENS = {"screen1": Screen1, "screen2": Screen2}
    BINDINGS = [
        ("1", "switch_screen('screen1')", "Screen1"),
        ("2", 'switch_screen("screen2")', "Screen2"),
    ]

    def compose(self) -> ComposeResult:
        yield Static("Main Screen")
        yield Footer()


if __name__ == "__main__":
    app = MyApp()
    app.run()
