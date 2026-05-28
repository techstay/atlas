local table1 = {}

-- set values with keys
table1[1] = 100
table1["foo"] = "bar"

-- get values
print(table1[1])
print(table1["foo"])

-- return nil if key does't exist
print(table1["bar"])
