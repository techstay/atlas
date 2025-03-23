from textual.app import App
from textual.widgets import Static


class MyApp(App):
    CSS_PATH = "css/helloworld.css"

    def compose(self):
        yield Static("Hello, World!")


if __name__ == "__main__":
    app = MyApp()
    app.run()
