import marimo

__generated_with = "0.23.5"
app = marimo.App(width="medium")


@app.cell(hide_code=True)
def _(mo):
    mo.md(r"""
    # Python 函数

    本笔记本演示 Python 函数的交互式示例。

    **内容包括:**
    - 函数定义与调用
    - 参数与返回值
    - 默认参数
    - Lambda 匿名函数
    - 递归函数
    """)
    return


@app.cell
def _():
    import marimo as mo
    import pandas as pd

    return mo, pd


@app.cell(hide_code=True)
def _(mo):
    mo.md(r"""
    ## 1. 函数定义与调用
    """)
    return


@app.cell
def _(mo):
    # 函数选择
    func_type = mo.ui.dropdown(
        ["问候函数", "计算面积", "温度转换", "判断奇偶"],
        value="问候函数",
        label="选择函数示例:",
    )
    name = mo.ui.text("输入参数:", value="Python")

    mo.vstack([func_type, name])
    return func_type, name


@app.cell
def _(func_type, mo, name):
    # 函数定义
    def greet(person_name):
        """问候函数 - 返回问候语"""
        return f"你好, {person_name}!欢迎学习 Python!"

    def rectangle_area(width, height):
        """计算矩形面积"""
        return width * height

    def celsius_to_fahrenheit(c):
        """摄氏温度转华氏温度"""
        return (c * 9 / 5) + 32

    def is_odd(number):
        """判断奇偶"""
        return number % 2 != 0

    # 根据选择调用不同函数
    choice = func_type.value
    param = name.value

    if choice == "问候函数":
        _result = greet(param)
        _code = (
            'def greet(name):\n    """问候函数 - 返回问候语"""\n    return f"你好, {name}!欢迎学习 Python!"\n\n# 调用函数\nresult = greet("'
            + param
            + '")\nprint(result)  # 输出: '
            + _result
        )

    elif choice == "计算面积":
        try:
            w = float(param) if param else 5
            h = 10
            _result = rectangle_area(w, h)
            _code = (
                'def rectangle_area(width, height):\n    """计算矩形面积"""\n    return width * height\n\n# 调用函数\narea = rectangle_area('
                + str(w)
                + ", "
                + str(h)
                + ')\nprint(f"矩形面积: {area}")  # 输出: '
                + str(_result)
            )
        except ValueError:
            _result = "请输入有效数字"
            _code = "# 请输入有效数字"

    elif choice == "温度转换":
        try:
            c = float(param)
            _result = celsius_to_fahrenheit(c)
            _code = (
                'def celsius_to_fahrenheit(c):\n    """摄氏温度转华氏温度"""\n    return (c * 9 / 5) + 32\n\n# 调用函数\nf = celsius_to_fahrenheit('
                + str(c)
                + ')\nprint(f"'
                + str(c)
                + '°C = {f}°F")  # 输出: '
                + f"{_result:.2f}"
                + "°F"
            )
        except ValueError:
            _result = "请输入有效数字"
            _code = "# 请输入有效数字"

    else:  # 判断奇偶
        try:
            _num = int(param)
            _result = is_odd(_num)
            _emoji = "✅ 是奇数" if _result else "❌ 是偶数"
            _code = (
                'def is_odd(number):\n    """判断奇偶"""\n    return number % 2 != 0\n\n# 调用函数\nis_odd('
                + str(_num)
                + ")  # 返回: "
                + str(_result)
                + "\n# "
                + _emoji
            )
        except ValueError:
            _result = "请输入整数"
            _code = "# 请输入整数"

    # 安全地分割代码
    _code_parts = _code.split("# 调用函数")
    _code_def = _code_parts[0].strip()
    _code_call = _code_parts[1].strip() if len(_code_parts) > 1 else ""

    _markdown = """
    ### {choice}

    **函数定义:**
    ```python
    {code_def}
    ```

    **调用:**
    ```python
    {code_call}
    ```

    **参数:** `{param}`

    **返回值:** `{result}`

    ---

    ### 函数语法

    ```python
    def 函数名(参数1, 参数2, ...):
        \"\"\"文档字符串 - 说明函数功能\"\"\"
        # 函数体
        执行语句...
        return 返回值
    ```
    """.format(
        choice=choice,
        code_def=_code_def,
        code_call=_code_call,
        param=param,
        result=_result,
    )

    mo.md(_markdown)
    return


@app.cell(hide_code=True)
def _(mo):
    mo.md(r"""
    ### 关键点

    - 使用 `def` 关键字定义函数
    - 函数名应该**见名知意** (动词或动词短语)
    - 参数在括号内,可以有多个
    - `return` 返回结果,可以省略 (默认返回 None)
    - 函数可以添加**文档字符串** (三重引号)
    """)
    return


@app.cell(hide_code=True)
def _(mo):
    mo.md(r"""
    ## 2. 参数类型
    """)
    return


@app.cell
def _(mo):
    # 参数类型演示
    param_type = mo.ui.radio(
        [
            "位置参数",
            "默认参数",
            "关键字参数",
            "可变参数 (*args)",
            "关键字可变参数 (**kwargs)",
        ],
        value="默认参数",
        label="参数类型:",
    )
    input1 = mo.ui.text("参数 1:", value="Alice")
    input2 = mo.ui.text("参数 2 (可选):", value="30")

    mo.vstack([param_type, input1, input2])
    return input1, input2, param_type


@app.cell
def _(greeting, input1, input2, mo, param_type):
    # 参数类型示例
    ptype = param_type.value
    val1 = input1.value
    val2 = input2.value

    if ptype == "位置参数":
        _param_code = '''def introduce(name, age):
    """位置参数 - 必须按顺序传递"""
    return f"我叫{name},今年{age}岁"

    # 调用 - 必须提供两个参数
    result = introduce("Alice", 25)
    print(result)'''
        try:
            _param_result = f"我叫{val1},今年{val2}岁"
        except:
            _param_result = "需要提供两个参数"

    elif ptype == "默认参数":
        _param_code = f'''def greet(name, greeting="你好"):
    """默认参数 - greeting 有默认值"""
    return f"{{greeting}}, {{name}}!"

    # 调用 - 可以省略 greeting
    result1 = greet("{val1}")
    print(result1)  # {greeting}, {val1}!

    result2 = greet("{val1}", "早上好")
    print(result2)  # 早上好, {val1}!'''
        _param_result = f"你好, {val1}!"

    elif ptype == "关键字参数":
        _param_code = f'''def create_user(name, age, city):
    """关键字参数 - 可以用参数名指定"""
    return f"{{name}}, {{age}}岁, 来自{{city}}"

    # 调用 - 使用关键字,顺序可以打乱
    result = create_user(name="{val1}", age={val2 if val2 else "25"}, city="北京")
    print(result)'''
        _param_result = f"{val1}, {val2 if val2 else '25'}岁, 来自北京"

    elif ptype == "可变参数 (*args)":
        _param_code = '''def calculate_sum(*args):
    """可变参数 - 接受任意数量的位置参数"""
    return sum(args)

    # 调用 - 可以传递任意个参数
    result1 = calculate_sum(1, 2, 3)
    print(result1)  # 6

    result2 = calculate_sum(1, 2, 3, 4, 5)
    print(result2)  # 15'''
        try:
            _param_nums = [float(x) for x in val1.split(",") if x.strip()]
            _param_result = f"sum({_param_nums}) = {sum(_param_nums)}"
        except:
            _param_result = "请输入逗号分隔的数字,如: 1,2,3,4,5"

    else:  # **kwargs
        _param_code = '''def create_profile(**kwargs):
    """关键字可变参数 - 接受任意数量的关键字参数"""
    return kwargs

    # 调用 - 可以传递任意键值对
    profile = create_profile(name="Alice", age=25, city="北京")
    print(profile)
    # {'name': 'Alice', 'age': 25, 'city': '北京'}'''
        _param_result = f"可以传递任意键值对,如: name='{val1}', age={val2 if val2 else '25'}"

    mo.md(f"""
    ### {ptype}

    **代码示例:**
    ```python
    {_param_code}
    ```

    **结果:** `{_param_result}`
    """)
    return


@app.cell(hide_code=True)
def _(mo):
    mo.md(r"""
    ## 3. 返回值
    """)
    return


@app.cell
def _(mo):
    # 返回值类型
    return_type = mo.ui.radio(
        ["单个值", "多个值 (元组)", "字典", "无返回值 (None)"],
        value="多个值 (元组)",
        label="返回值类型:",
    )
    return_n = mo.ui.number(1, 20, value=5, label="输入数字:")

    mo.vstack([return_type, return_n])
    return return_n, return_type


@app.cell
def _(mo, return_n, return_type):
    # 返回值示例
    _return_rtype = return_type.value
    _return_num = int(return_n.value)

    if _return_rtype == "单个值":

        def square(x):
            return x**2

        _return_result = square(_return_num)
        _return_code = f'''def square(x):
    """返回单个值"""
    return x ** 2

    result = square({_return_num})
    print(result)  # 输出: {_return_result}'''

    elif _return_rtype == "多个值 (元组)":

        def calculate_stats(numbers):
            """返回多个值 - Python 会自动打包为元组"""
            return sum(numbers), sum(numbers) / len(numbers), max(numbers), min(numbers)

        _return_nums = list(range(1, _return_num + 1))
        total, avg, maximum, minimum = calculate_stats(_return_nums)
        _return_result = (total, avg, maximum, minimum)
        _return_code = f'''def calculate_stats(numbers):
    """返回多个值"""
    total = sum(numbers)
    average = sum(numbers) / len(numbers)
    maximum = max(numbers)
    minimum = min(numbers)
    return total, average, maximum, minimum

    numbers = {_return_nums}
    total, avg, max_val, min_val = calculate_stats(numbers)

    print(f"总和: {{total}}")
    print(f"平均: {{avg:.2f}}")
    print(f"最大: {{max_val}}")
    print(f"最小: {{min_val}}")'''

    elif _return_rtype == "字典":

        def get_user_info(user_id):
            """返回字典 - 结构化数据"""
            return {"id": user_id, "name": f"User_{user_id}", "age": user_id * 5 + 20}

        _return_result = get_user_info(_return_num)
        _return_code = f'''def get_user_info(user_id):
    """返回字典"""
    return {{
        "id": user_id,
        "name": f"User_{{user_id}}",
        "age": user_id * 5 + 20
    }}

    user = get_user_info({_return_num})
    print(user)
    # {_return_result}'''

    else:  # None

        def print_numbers(count):
            """无返回值 - 默认返回 None"""
            for i in range(1, count + 1):
                print(f"数字: {i}")
            # 没有 return 语句,默认返回 None

        _return_code = f'''def print_numbers(count):
    """无返回值函数"""
    for i in range(1, count + 1):
        print(f"数字: {{i}}")
    # 默认返回 None

    result = print_numbers({_return_num})
    print(f"返回值: {{result}}")  # 输出: None'''
        _return_result = "None (函数没有 return 语句)"

    mo.md(f"""
    ### {_return_rtype}

    **代码:**
    ```python
    {_return_code}
    ```

    **返回值:** `{_return_result}`

    ---

    ### 返回值要点

    - 使用 `return` 关键字返回值
    - 可以返回**任意类型**的数据
    - 返回多个值时,Python 自动打包为**元组**
    - 没有 `return` 语句时,默认返回 `None`
    - 函数执行到 `return` 后立即返回
    """)
    return


@app.cell(hide_code=True)
def _(mo):
    mo.md(r"""
    ## 4. Lambda 匿名函数
    """)
    return


@app.cell
def _(mo):
    # Lambda 演示
    lambda_use = mo.ui.radio(
        ["简单计算", "排序", "过滤", "映射 (map)"],
        value="简单计算",
        label="Lambda 用途:",
    )
    lambda_n = mo.ui.number(1, 10, value=5, label="输入数字:")

    mo.vstack([lambda_use, lambda_n])
    return lambda_n, lambda_use


@app.cell
def _(lambda_n, lambda_use, mo, pd):
    # Lambda 函数示例
    _lambda_use = lambda_use.value
    _lambda_num = int(lambda_n.value)

    if _lambda_use == "简单计算":
        _lambda_code = f'''# Lambda 语法: lambda 参数: 表达式

    # 定义 lambda 函数
    square = lambda x: x ** 2

    # 调用
    result = square({_lambda_num})
    print(f"{_lambda_num}² = {{result}}")  # 输出: {_lambda_num**2}

    # 等效的普通函数
    def square_func(x):
    return x ** 2'''
        _lambda_result = f"{_lambda_num}² = {_lambda_num**2}"

    elif _lambda_use == "排序":
        _students = [("Alice", 85), ("Bob", 92), ("Charlie", 78), ("David", 95)]
        _sorted_students = sorted(_students, key=lambda x: x[1], reverse=True)

        _lambda_code = f"""students = {_students}

    # 按分数排序 (使用 lambda)
    sorted_students = sorted(students, key=lambda x: x[1], reverse=True)

    print(sorted_students)
    # {_sorted_students}"""

        _df = pd.DataFrame(_sorted_students, columns=["姓名", "分数"])
        _lambda_result = mo.vstack([mo.md("**按分数排序:**"), mo.ui.dataframe(_df)])

    elif _lambda_use == "过滤":
        _numbers = list(range(1, _lambda_num * 2 + 1))
        _evens = list(filter(lambda x: x % 2 == 0, _numbers))
        _odds = list(filter(lambda x: x % 2 != 0, _numbers))

        _lambda_code = f"""numbers = {_numbers}

    # 过滤偶数
    evens = list(filter(lambda x: x % 2 == 0, numbers))
    print(f"偶数: {{evens}}")
    # {_evens}

    # 过滤奇数
    odds = list(filter(lambda x: x % 2 != 0, numbers))
    print(f"奇数: {{odds}}")
    # {_odds}"""
        _lambda_result = f"偶数: {_evens}\n奇数: {_odds}"

    else:  # map
        _numbers = list(range(1, _lambda_num + 1))
        _squared = list(map(lambda x: x**2, _numbers))

        _lambda_code = f"""numbers = {_numbers}

    # 使用 map + lambda 计算平方
    squared = list(map(lambda x: x**2, numbers))
    print(squared)
    # {_squared}"""

        _df = pd.DataFrame({"数字": _numbers, "平方": _squared})
        _lambda_result = mo.vstack([mo.md("**计算平方:**"), mo.ui.dataframe(_df)])

    _lambda_markdown = mo.md(f"""
    ### Lambda - {_lambda_use}

    **代码:**
    ```python
    {_lambda_code}
    ```

    **结果:**
    {_lambda_result if isinstance(_lambda_result, str) else ""}
    """)
    mo.vstack([_lambda_markdown, _lambda_result]) if not isinstance(_lambda_result, str) else _lambda_markdown
    return


@app.cell(hide_code=True)
def _(mo):
    mo.md(r"""
    ## 5. 递归函数
    """)
    return


@app.cell
def _(mo):
    # 递归演示
    recursive_type = mo.ui.radio(
        ["阶乘", "斐波那契数列", "求和 1 到 n"],
        value="阶乘",
        label="递归类型:",
    )
    recursive_n = mo.ui.number(1, 15, value=5, label="输入 n:")

    mo.vstack([recursive_type, recursive_n])
    return recursive_n, recursive_type


@app.cell
def _(mo, recursive_n, recursive_type):
    # 递归函数示例
    _recursive_rtype = recursive_type.value
    _recursive_num = int(recursive_n.value)

    if _recursive_rtype == "阶乘":

        def factorial(x):
            """递归计算阶乘"""
            if x <= 1:
                return 1
            return x * factorial(x - 1)

        _recursive_result = factorial(_recursive_num)
        _steps = " × ".join(str(i) for i in range(_recursive_num, 0, -1))

        _recursive_code = f'''def factorial(x):
    """递归计算阶乘"""
    # 基本情况
    if x <= 1:
        return 1
    # 递归调用
    return x * factorial(x - 1)

    result = factorial({_recursive_num})
    print(f"{_recursive_num}! = {_steps} = {{result}}")
    # 输出: {_recursive_result}'''

    elif _recursive_rtype == "斐波那契数列":

        def fibonacci(x):
            """递归计算斐波那契数"""
            if x <= 0:
                return 0
            elif x == 1:
                return 1
            return fibonacci(x - 1) + fibonacci(x - 2)

        _fib_list = [fibonacci(_fib_i) for _fib_i in range(_recursive_num)]
        _recursive_result = _fib_list

        _recursive_code = f'''def fibonacci(x):
    """递归计算斐波那契数"""
    # 基本情况
    if x <= 0:
        return 0
    elif x == 1:
        return 1
    # 递归调用
    return fibonacci(x - 1) + fibonacci(x - 2)

    # 生成前 {_recursive_num} 个斐波那契数
    fib_list = [fibonacci(i) for i in range({_recursive_num})]
    print(fib_list)
    # {_fib_list}'''

    else:  # 求和

        def sum_to_n(n):
            """递归求和 1 到 n"""
            if n <= 1:
                return 1
            return n + sum_to_n(n - 1)

        _recursive_result = sum_to_n(_recursive_num)
        _steps = " + ".join(str(i) for i in range(1, _recursive_num + 1))

        _recursive_code = f'''def sum_to_n(n):
    """递归求和"""
    # 基本情况
    if n <= 1:
        return 1
    # 递归调用
    return n + sum_to_n(n - 1)

    result = sum_to_n({_recursive_num})
    print(f"{_steps} = {{result}}")
    # 输出: {_recursive_result}'''

    mo.md(f"""
    ### 递归 - {_recursive_rtype}

    **代码:**
    ```python
    {_recursive_code}
    ```

    **结果:** `{_recursive_result}`

    ---

    ### 递归要点

    1. **基本情况** (Base Case) - 终止条件,防止无限递归
    2. **递归调用** - 函数调用自身,但参数要更接近基本情况
    3. **必须有终止条件**,否则会栈溢出 (Stack Overflow)

    ### 递归 vs 迭代

    | 特性 | 递归 | 迭代 (循环) |
    |------|------|------------|
    | 可读性 | ✅ 更直观 | ⚠️ 需要更多代码 |
    | 性能 | ⚠️ 可能较慢 | ✅ 通常更快 |
    | 内存 | ⚠️ 占用栈空间 | ✅ 占用少 |
    | 适用场景 | 树/图/分治 | 简单循环 |
    """)
    return


@app.cell(hide_code=True)
def _(mo):
    mo.md(r"""
    ## 总结

    本笔记本学习了 Python 函数的核心概念:

    1. **函数定义** - 使用 `def` 定义,包含名称、参数和返回值
    2. **参数类型** - 位置参数、默认参数、关键字参数、*args、**kwargs
    3. **返回值** - 可以返回任意类型,多个值自动打包为元组
    4. **Lambda 函数** - 简洁的匿名函数,适合简单操作
    5. **递归函数** - 函数调用自身,需要基本情况终止

    ### 函数的优势

    - ✅ **代码复用** - 写一次,多次调用
    - ✅ **模块化** - 将复杂问题分解为小函数
    - ✅ **可读性** - 函数名说明意图
    - ✅ **可测试** - 独立函数易于测试
    - ✅ **可维护** - 修改一处,全局生效

    ### 下一步学习

    - 模块和包 (import)
    - 类和面向对象
    - 装饰器
    - 生成器
    """)
    return


if __name__ == "__main__":
    app.run()
