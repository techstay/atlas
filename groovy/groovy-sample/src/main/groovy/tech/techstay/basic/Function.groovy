package tech.techstay.basic

void f1() {}

void f2(int d) {}

void f3(def d) {}

// default parameters
void f4(int a = 10, String b = 'abc') {
  println([a, b])
}

// varargs
void f5(def ... list) {
  println(list)
}

// named parameters
void f6(Map map) {
  println(map)
}

f1()
f2(10)
f3(10)
f4()
f4(5)
f4(5, 'aaa')
f5()
f5(1)
f5(1, 2, 3, 4)
f6(a: 100, b: 20, c: 'a')

