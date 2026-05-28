# %%

from functools import cache, partial, reduce
from itertools import (
    accumulate,
    batched,
    chain,
    combinations,
    compress,
    count,
    cycle,
    groupby,
    islice,
    permutations,
    product,
    repeat,
)
from pprint import pprint


@cache
def fibonacci(n):
    return fibonacci(n - 1) + fibonacci(n - 2) if n > 1 else 1


print(fibonacci(100))
# %%
base2 = partial(int, base=2)
print(base2("10000"))

# %%
sum = reduce(lambda a, b: a + b, range(1, 11), 0)
print(sum)


# %%
def take(gen, n: int):
    return list(islice(gen, n))


take(count(1), 10)
# %%
take(cycle("1234"), 10)
# %%
take(repeat(666, 10), 3)

# %%
list(accumulate([1, 2, 3, 4, 5]))

# %%
list(batched("12345678", 3))

# %%
list(chain("123", "456", "789"))

# %%
list(compress("ABCD", [0, 1, 0, 1]))

# %%
result = list(groupby(["a", "b", "cd"], len))
pprint(result)
# %%
list(product("abcd", repeat=2))

# %%
list(permutations("abcd", 2))

# %%
list(combinations("abcd", 2))

# %%
