package tech.techstay.basic

def arrayList = [1, 2, 3]
def linkedList = [1, 2, 3] as LinkedList

// you can declare an array explicitly
int[] intArray = [1, 2, 3, 4]

intArray = new int[]{1, 2, 3, 4}
assert intArray instanceof int[]

// appending items
arrayList << 4 << 5
assert arrayList == [1, 2, 3, 4, 5]
