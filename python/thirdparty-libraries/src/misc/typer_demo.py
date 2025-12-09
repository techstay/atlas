import typer


def hello(name: str):
    print(f"Hello {name}")


# To run this cli app, type `uv run misc/typer_demo.py`
if __name__ == "__main__":
    typer.run(hello)
