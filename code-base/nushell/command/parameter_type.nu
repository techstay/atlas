# see all types: https://www.nushell.sh/zh-CN/book/custom_commands.html#%E5%8F%82%E6%95%B0%E7%B1%BB%E5%9E%8B
def greet [name: string, age: int] {
    $"Hello ($age)'s ($name)"
}

greet zhang3 18
# greet li4 li4
