import marimo

__generated_with = "0.23.5"
app = marimo.App(width="medium")


@app.cell(hide_code=True)
def _(mo):
    mo.md(r"""
    # Python 控制流 - 条件判断与循环

    本笔记本演示 Python 控制流的交互式示例。

    **内容包括:**
    - if/elif/else 条件判断
    - for 循环
    - while 循环
    - 循环控制 (break, continue)
    - 列表推导式
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
    ## 1. 条件判断 - if/elif/else
    """)
    return


@app.cell
def _(mo):
    # 成绩等级计算器
    score = mo.ui.number(0, 100, value=85, label="输入成绩 (0-100):")

    score
    return (score,)


@app.cell
def _(mo, score):
    # 成绩等级判断
    s = int(score.value)

    if s >= 90:
        grade = "A"
        emoji = "🎉"
        comment = "优秀!继续保持!"
    elif s >= 80:
        grade = "B"
        emoji = "👍"
        comment = "良好!还有进步空间!"
    elif s >= 70:
        grade = "C"
        emoji = "😊"
        comment = "中等,需要更多练习!"
    elif s >= 60:
        grade = "D"
        emoji = "😅"
        comment = "及格,要加油了!"
    else:
        grade = "F"
        emoji = "💪"
        comment = "不及格,不要气馁,继续努力!"

    mo.md(f"""
    ### 成绩等级计算器

    {emoji} **分数:** {s}/100

    **等级:** {grade}

    **评价:** {comment}

    ---

    ### Python 代码

    ```python
    score = {s}

    if score >= 90:
        grade = "A"
        print("优秀!继续保持!")
    elif score >= 80:
        grade = "B"
        print("良好!还有进步空间!")
    elif score >= 70:
        grade = "C"
        print("中等,需要更多练习!")
    elif score >= 60:
        grade = "D"
        print("及格,要加油了!")
    else:
        grade = "F"
        print("不及格,不要气馁,继续努力!")
    ```
    """)
    return


@app.cell(hide_code=True)
def _(mo):
    mo.md(r"""
    ## 2. for 循环
    """)
    return


@app.cell
def _(mo):
    # 循环参数设置
    n = mo.ui.number(1, 20, value=10, label="循环次数:")
    operation = mo.ui.radio(
        ["累加求和", "计算平方", "计算阶乘", "打印序列"],
        value="累加求和",
        label="选择操作:",
    )
    show_details = mo.ui.switch(value=True, label="显示详细过程:")

    mo.vstack([n, operation, show_details])
    return n, operation, show_details


@app.cell
def _(mo, n, operation, pd, show_details):
    # for 循环演示
    _for_num = int(n.value)
    _for_op = operation.value

    if _for_op == "累加求和":
        _sum_total = 0
        _sum_steps = []
        for _sum_i in range(1, _for_num + 1):
            _sum_total += _sum_i
            _sum_steps.append({"数字": _sum_i, "累加和": _sum_total})

        _sum_df = pd.DataFrame(_sum_steps)

        if show_details.value:
            _sum_display = mo.vstack([
                mo.md(f"### 累加求和: 1 + 2 + ... + {_for_num}"),
                mo.ui.dataframe(_sum_df),
                mo.md(f"**结果:** 总和 = **{_sum_total}**"),
            ])
        else:
            _sum_display = mo.md(f"""
            ### 累加求和

            **公式:** 1 + 2 + ... + {_for_num}

            **结果:** 总和 = **{_sum_total}**

            ```python
            total = 0
            for i in range(1, {_for_num + 1}):
                total += i
            print(f"总和 = {{total}}")
            ```
            """)

    elif _for_op == "计算平方":
        _sq_data = []
        for _sq_i in range(1, _for_num + 1):
            _sq_data.append({"数字": _sq_i, "平方": _sq_i**2, "立方": _sq_i**3})

        _sq_df = pd.DataFrame(_sq_data)

        if show_details.value:
            _sq_display = mo.vstack([
                mo.md(f"### 平方和立方 (1 到 {_for_num})"),
                mo.ui.dataframe(_sq_df),
            ])
        else:
            _sq_preview = "\n".join(
                f"| {_sq_i} | {_sq_i**2} | {_sq_i**3} |"
                for _sq_i in range(1, min(_for_num + 1, 6))
            )
            _sq_ellipsis = "\n... (省略)" if _for_num > 5 else ""
            _sq_display = mo.md(f"""
            ### 平方和立方

            | 数字 | 平方 | 立方 |
            |------|------|------|
            {_sq_preview}{_sq_ellipsis}

            ```python
            for i in range(1, {_for_num + 1}):
                print(f"{{i}}: 平方={{i**2}}, 立方={{i**3}}")
            ```
            """)

    elif _for_op == "计算阶乘":
        _fact_value = 1
        _fact_steps = []
        for _fact_i in range(1, _for_num + 1):
            _fact_value *= _fact_i
            _fact_steps.append(str(_fact_i))

        if show_details.value and _for_num <= 15:
            _fact_text = " × ".join(_fact_steps)
            _fact_display = mo.md(f"""
            ### 阶乘计算: {_for_num}!

            **计算过程:**

            {_fact_text} = **{_fact_value}**

            ```python
            factorial = 1
            for i in range(1, {_for_num + 1}):
                factorial *= i
                print(f"{{i}}! = {{factorial}}")

            print(f"{_for_num}! = {{factorial}}")
            ```
            """)
        else:
            _fact_display = mo.md(f"""
            ### 阶乘计算: {_for_num}!

            **结果:** **{_fact_value}**

            ```python
            factorial = 1
            for i in range(1, {_for_num + 1}):
                factorial *= i
            ```
            """)

    else:  # 打印序列
        _fib_seq = [0, 1]
        for _fib_i in range(2, _for_num):
            _fib_seq = _fib_seq + [_fib_seq[-1] + _fib_seq[-2]]

        if show_details.value:
            _fib_df = pd.DataFrame({
                "位置": range(1, _for_num + 1),
                "值": _fib_seq[:_for_num],
            })
            _fact_display = mo.vstack([
                mo.md(f"### 斐波那契数列 (前 {_for_num} 项)"),
                mo.ui.dataframe(_fib_df),
            ])
        else:
            _fact_display = mo.md(f"""
            ### 斐波那契数列

            **前 {_for_num} 项:**

            `{_fib_seq[:_for_num]}`

            **规律:** 每个数等于前两个数之和

            ```python
            fib = [0, 1]
            for i in range(2, {_for_num}):
                fib.append(fib[-1] + fib[-2])
            print(fib)
            ```
            """)

    _fact_display
    return


@app.cell(hide_code=True)
def _(mo):
    mo.md(r"""
    ## 3. while 循环
    """)
    return


@app.cell
def _(mo):
    # while 循环参数
    target = mo.ui.number(10, 1000, value=100, label="目标值:")
    mode = mo.ui.radio(
        ["累加到目标值", "2 的幂次", "找最大因子"],
        value="累加到目标值",
        label="选择模式:",
    )

    mo.vstack([target, mode])
    return mode, target


@app.cell
def _(mo, mode, pd, target):
    # while 循环演示
    _target_val = int(target.value)
    _mode_val = mode.value

    if _mode_val == "累加到目标值":
        _total_sum = 0
        _count = 0
        _steps = []

        while _total_sum < _target_val:
            _count += 1
            _total_sum += _count
            _steps.append({"步骤": _count, "当前值": _total_sum})

        _sum_df = pd.DataFrame(_steps)

        _while_output = mo.md(f"""
        ### 累加到目标值: {_target_val}

        **结果:** 需要累加到第 **{_count}** 个数才能超过 {_target_val}

        **最终和:** {_total_sum}

        ```python
        total = 0
        count = 0

        while total < {_target_val}:
            count += 1
            total += count
            print(f"步骤 {{count}}: 总和 = {{total}}")

        print(f"需要 {{count}} 步才能达到 {{total}}")
        ```
        """)

    elif _mode_val == "2 的幂次":
        _power = 1
        _power_steps = []

        while _power < _target_val:
            _power_steps.append({"指数": len(_power_steps), "值": _power})
            _power *= 2

        _power_df = pd.DataFrame(_power_steps)

        _while_output = mo.md(f"""
        ### 2 的幂次 (小于 {_target_val})

        **结果:** 2^0 到 2^{len(_power_steps) - 1}

        **最大值:** {_power_steps[-1]["值"]}

        ```python
        power = 1
        exponent = 0

        while power < {_target_val}:
            print(f"2^{{exponent}} = {{power}}")
            power *= 2
            exponent += 1
        ```
        """)

    else:  # 找最大因子
        _factor_n = _target_val
        _divisor = 2
        _factors = []

        _temp_val = _factor_n
        while _divisor * _divisor <= _temp_val:
            while _temp_val % _divisor == 0:
                _factors.append(_divisor)
                _temp_val //= _divisor
            _divisor += 1

        if _temp_val > 1:
            _factors.append(_temp_val)

        _is_prime_flag = len(_factors) == 1 and _factors[0] == _factor_n

        _while_output = mo.md(f"""
        ### 找 {_factor_n} 的质因数分解

        **结果:** {_factor_n} = {" × ".join(map(str, _factors))}

        **是否为质数:** {"❌ 否" if not _is_prime_flag else "✅ 是"}

        ```python
        n = {_factor_n}
        divisor = 2
        factors = []

        while divisor * divisor <= n:
            while n % divisor == 0:
                factors.append(divisor)
                n //= divisor
            divisor += 1

        if n > 1:
            factors.append(n)

        print(f"质因数: {{factors}}")
        ```
        """)

    _while_output
    return


@app.cell(hide_code=True)
def _(mo):
    mo.md(r"""
    ## 4. 循环控制 - break 和 continue
    """)
    return


@app.cell
def _(mo):
    # break/continue 演示
    limit = mo.ui.number(10, 50, value=20, label="搜索范围:")
    control_type = mo.ui.radio(
        ["break (找到即停)", "continue (跳过某些值)"],
        value="break (找到即停)",
        label="控制类型:",
    )

    mo.vstack([limit, control_type])
    return control_type, limit


@app.cell
def _(control_type, limit, mo):
    # break 和 continue 示例
    _lim = int(limit.value)
    _ctype = control_type.value

    if _ctype.startswith("break"):
        # 找到第一个质数就停止
        _found = False
        _prime_found = None
        _checked = []

        for _break_num in range(2, _lim + 1):
            _is_prime = True
            for _break_i in range(2, int(_break_num**0.5) + 1):
                if _break_num % _break_i == 0:
                    _is_prime = False
                    break

            _checked.append(_break_num)
            if _is_prime:
                _prime_found = _break_num
                _found = True
                break

        _control_output = mo.md(f"""
        ### break - 找到第一个质数就停止

        **搜索范围:** 2 到 {_lim}

        **检查的数字:** {_checked}

        **找到的质数:** {_prime_found}

        ```python
        for num in range(2, {_lim + 1}):
            is_prime = True
            for i in range(2, int(num**0.5) + 1):
                if num % i == 0:
                    is_prime = False
                    break  # 不是质数,跳出内层循环

            if is_prime:
                print(f"找到质数: {{num}}")
                break  # 找到第一个质数,跳出外层循环
        ```

        > 💡 **break** 立即跳出循环,不再执行后续迭代
        """)

    else:  # continue
        _skipped = []
        _processed = []

        for _continue_num in range(1, _lim + 1):
            if _continue_num % 3 == 0:
                _skipped.append(_continue_num)
                continue  # 跳过 3 的倍数
            _processed.append(_continue_num)

        _control_output = mo.md(f"""
        ### continue - 跳过 3 的倍数

        **范围:** 1 到 {_lim}

        **跳过的数字 (3 的倍数):** {_skipped}

        **处理的数字:** {_processed}

        ```python
        for num in range(1, {_lim + 1}):
            if num % 3 == 0:
                continue  # 跳过 3 的倍数
            print(num)
        ```

        > 💡 **continue** 跳过当前迭代,继续下一次迭代
        """)

    _control_output
    return


@app.cell(hide_code=True)
def _(mo):
    mo.md(r"""
    ## 5. 列表推导式
    """)
    return


@app.cell
def _(mo):
    # 列表推导式参数
    comp_n = mo.ui.number(5, 20, value=10, label="范围 n:")
    comp_type = mo.ui.radio(
        ["平方列表", "偶数列表", "奇数平方", "条件过滤"],
        value="平方列表",
        label="推导式类型:",
    )

    mo.vstack([comp_n, comp_type])
    return comp_n, comp_type


@app.cell
def _(comp_n, comp_type, mo, pd):
    # 列表推导式演示
    _comp_num = int(comp_n.value)
    _comp_ctype = comp_type.value

    if _comp_ctype == "平方列表":
        # 传统方式
        _traditional = []
        for _square_i in range(1, _comp_num + 1):
            _traditional.append(_square_i**2)

        # 推导式方式
        _comprehension = [_square_i**2 for _square_i in range(1, _comp_num + 1)]

        _df = pd.DataFrame({"数字": range(1, _comp_num + 1), "平方": _comprehension})

        _comp_output = mo.md(f"""
        ### 平方列表

        **传统写法:**
        ```python
        squares = []
        for i in range(1, {_comp_num + 1}):
            squares.append(i**2)
        ```

        **列表推导式:**
        ```python
        squares = [i**2 for i in range(1, {_comp_num + 1})]
        ```

        **结果:** {_comprehension}
        """)

    elif _comp_ctype == "偶数列表":
        _evens = [_even_i for _even_i in range(1, _comp_num + 1) if _even_i % 2 == 0]

        _comp_output = mo.md(f"""
        ### 偶数列表 (1 到 {_comp_num})

        **列表推导式:**
        ```python
        evens = [i for i in range(1, {_comp_num + 1}) if i % 2 == 0]
        ```

        **结果:** {_evens}

        **数量:** {len(_evens)} 个偶数
        """)

    elif _comp_ctype == "奇数平方":
        _odd_squares = [
            _odd_i**2 for _odd_i in range(1, _comp_num + 1) if _odd_i % 2 != 0
        ]

        _comp_output = mo.md(f"""
        ### 奇数的平方

        **列表推导式:**
        ```python
        odd_squares = [i**2 for i in range(1, {_comp_num + 1}) if i % 2 != 0]
        ```

        **结果:** {_odd_squares}
        """)

    else:  # 条件过滤
        # 过滤出既能被 2 整除又能被 3 整除的数
        _filtered = [
            _filter_i
            for _filter_i in range(1, _comp_num + 1)
            if _filter_i % 2 == 0 and _filter_i % 3 == 0
        ]

        _comp_output = mo.md(f"""
        ### 条件过滤 - 能被 2 和 3 整除的数

        **列表推导式:**
        ```python
        filtered = [i for i in range(1, {_comp_num + 1}) if i % 2 == 0 and i % 3 == 0]
        ```

        **结果:** {_filtered}

        **说明:** 这些数是 6 的倍数
        """)

    _comp_output
    return


@app.cell(hide_code=True)
def _(mo):
    mo.md(r"""
    ## 总结

    本笔记本学习了 Python 控制流的核心概念:

    1. **条件判断** - if/elif/else 分支结构
    2. **for 循环** - 遍历序列或范围
    3. **while 循环** - 条件满足时持续循环
    4. **break** - 立即跳出循环
    5. **continue** - 跳过当前迭代
    6. **列表推导式** - 简洁的列表创建方式

    ### 关键要点

    - 条件判断用于**分支决策**
    - for 循环适合**已知次数**的迭代
    - while 循环适合**条件驱动**的迭代
    - break 和 continue 用于**精细控制**循环流程
    - 列表推导式比传统循环**更简洁高效**

    > 💡 **下一步:** 查看 `functions.py` 学习函数定义和调用!
    """)
    return


if __name__ == "__main__":
    app.run()
