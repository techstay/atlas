import logging

import flet
from flet import IconButton, Page, Row, TextField, icons

logging.basicConfig(level=logging.INFO)
logger = logging.getLogger("flet")
logger.setLevel(logging.INFO)


def main(page: Page):
    page.title = "Flet counter example"
    page.vertical_alignment = flet.MainAxisAlignment.CENTER
    page.window_center()
    page.window_width = 300
    page.window_height = 200

    txt_number = TextField(
        value="0",
        text_align=flet.TextAlign.RIGHT,
        width=100,
    )

    def minus_click(e):
        txt_number.value = str(int(txt_number.value) - 1)
        logger.info(f"minus_click: {txt_number.value}")
        page.update()

    def plus_click(e):
        txt_number.value = str(int(txt_number.value) + 1)
        logger.info(f"plus_click: {txt_number.value}")
        page.update()

    page.add(
        Row(
            [
                IconButton(icons.REMOVE, on_click=minus_click),
                txt_number,
                IconButton(icons.ADD, on_click=plus_click),
            ],
            alignment=flet.MainAxisAlignment.CENTER,
        )
    )


if __name__ == "__main__":
    flet.app(target=main)
