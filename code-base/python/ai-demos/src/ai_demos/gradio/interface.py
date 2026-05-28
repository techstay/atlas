# %%

import gradio as gr


def greet(name):
    return "Hello " + name + "!"


demo = gr.Interface(
    fn=greet,
    inputs="textbox",
    outputs="textbox",
)

demo.launch()

# %%
import gradio as gr


def greet2(name, intensity):
    return "Hello, " + name + "!" * intensity


demo = gr.Interface(
    fn=greet2,
    inputs=["text", gr.Slider(value=2, minimum=1, maximum=10, step=1)],
    outputs=[gr.Textbox(label="greeting", lines=3)],
)

demo.launch()

# %%
import gradio as gr


def greet3(name: str, is_morning: bool, temperature: int):
    salutation = "Good morning" if is_morning else "Good evening"
    greeting = f"{salutation} {name}. It is {temperature} degrees today"
    celsius = (temperature - 32) * 5 / 9
    return greeting, round(celsius, 2)


demo = gr.Interface(
    fn=greet3,
    inputs=["text", "checkbox", gr.Slider(0, 100)],
    outputs=["text", "number"],
)
demo.launch()

# %%
import gradio as gr
import numpy as np


def sepia(input_img):
    sepia_filter = np.array(
        [[0.393, 0.769, 0.189], [0.349, 0.686, 0.168], [0.272, 0.534, 0.131]]
    )
    sepia_img = input_img.dot(sepia_filter.T)
    sepia_img /= sepia_img.max()
    return sepia_img


demo = gr.Interface(sepia, gr.Image(), "image")
demo.launch()

# %%
