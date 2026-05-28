package tech.techstay.oop

import java.lang.annotation.ElementType
import java.lang.annotation.Retention
import java.lang.annotation.RetentionPolicy
import java.lang.annotation.Target

@Target([ElementType.METHOD, ElementType.TYPE])
@Retention(RetentionPolicy.RUNTIME)
@interface MyAnnotation {
  String value() default 'default value'

  String[] data()
}

@MyAnnotation(data = ['a', 'b', 'c'])
class MyClass {
  @MyAnnotation(value = 'xyz', data = ['x', 'y', 'z'])
  def doSomething() {}
}

// getting annotations in classes
MyClass.getAnnotationsByType(MyAnnotation).each {
  println([it.value(), it.data()])
}

// getting annotations in methods
MyClass.declaredMethods*.getAnnotationsByType(MyAnnotation)*.each {
  println([it.value(), it.data()])
}
