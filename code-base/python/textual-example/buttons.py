from textual.app import App
from textual.containers import HorizontalScroll, Vertical
from textual.widgets import (
    Button,
)


class MyApp(App):
    CSS_PATH = "css/buttons.css"

    def compose(self):
        yield Vertical(
            HorizontalScroll(
                Button("Button 1"),
                Button("Button 2", variant="primary"),
                Button.success("Button 3"),
                Button.warning("Button 4"),
                Button.error("Button 5"),
            )
        )

    def on_button_pressed(self, event: Button.Pressed) -> None:
        n = int(str(event.button.label)[-1])
        if n == 1 or n == 2:
            self.notify(f"{event.button.label} Clicked!", title="Notification")
        elif n == 3:
            self.notify(f"{event.button.label} Clicked!", severity="information")
        elif n == 4:
            self.notify(f"{event.button.label} Clicked!", severity="warning")
        elif n == 5:
            self.notify(f"{event.button.label} Clicked!", severity="error")


if __name__ == "__main__":
    app = MyApp()
    app.run()
