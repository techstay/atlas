import marimo

__generated_with = "0.23.5"
app = marimo.App(width="medium")


@app.cell
def _():
    import marimo as mo

    return (mo,)


@app.cell(hide_code=True)
def _(mo):
    mo.md(r"""
    # Python 基础示例

    这个笔记本只保留最基础的 Python 示例: 变量、常见类型、类型转换和变量命名。
    """)
    return


@app.cell(hide_code=True)
def _(mo):
    mo.md(r"""
    ## 1. 变量
    """)
    return


@app.cell
def _():
    name = "Alice"
    age = 18
    height = 168.5
    is_student = True
    return age, height, is_student, name


@app.cell
def _(age, height, is_student, name):
    print(name)
    print(age)
    print(height)
    print(is_student)
    return


@app.cell(hide_code=True)
def _(mo):
    mo.md(r"""
    ## 2. 常见数据类型
    """)
    return


@app.cell
def _():
    text_value = "Hello, Python"
    integer_value = 42
    float_value = 3.14
    bool_value = False
    list_value = [1, 2, 3]
    dict_value = {"name": "Alice", "age": 18}
    return (
        bool_value,
        dict_value,
        float_value,
        integer_value,
        list_value,
        text_value,
    )


@app.cell
def _(
    bool_value,
    dict_value,
    float_value,
    integer_value,
    list_value,
    text_value,
):
    print(type(text_value))
    print(type(integer_value))
    print(type(float_value))
    print(type(bool_value))
    print(type(list_value))
    print(type(dict_value))
    return


@app.cell(hide_code=True)
def _(mo):
    mo.md(r"""
    ## 3. 类型转换
    """)
    return


@app.cell
def _():
    number_text = "123"
    converted_int = int(number_text)
    converted_float = float(number_text)
    converted_string = str(converted_int)
    return converted_float, converted_int, converted_string, number_text


@app.cell
def _(converted_float, converted_int, converted_string, number_text):
    print(number_text, type(number_text))
    print(converted_int, type(converted_int))
    print(converted_float, type(converted_float))
    print(converted_string, type(converted_string))
    return


@app.cell(hide_code=True)
def _(mo):
    mo.md(r"""
    ## 4. 变量命名
    """)
    return


@app.cell
def _():
    user_name = "Alice"
    total_score = 95
    MAX_RETRY = 3
    return MAX_RETRY, total_score, user_name


@app.cell
def _(MAX_RETRY, total_score, user_name):
    print(user_name)
    print(total_score)
    print(MAX_RETRY)
    return


@app.cell(hide_code=True)
def _(mo):
    mo.md(r"""
    ## 小结

    - 变量用 `=` 赋值
    - 常见基础类型包括 `str`, `int`, `float`, `bool`, `list`, `dict`
    - 类型转换使用 `str()`, `int()`, `float()`
    - Python 变量名推荐使用 `snake_case`
    """)
    return


if __name__ == "__main__":
    app.run()
