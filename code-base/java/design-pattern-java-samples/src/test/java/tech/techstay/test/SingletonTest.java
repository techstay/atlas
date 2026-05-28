package tech.techstay.test;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;
import tech.techstay.singleton.*;


public class SingletonTest {
  @Test
  public void testSingleton() {
    UnThreadSafeSingleton singleton1 = UnThreadSafeSingleton.getSingleton();
    UnThreadSafeSingleton singleton2 = UnThreadSafeSingleton.getSingleton();
    Assertions.assertEquals(singleton1, singleton2);

    FirstLoadSingleton singleton3 = FirstLoadSingleton.getSingleton();
    FirstLoadSingleton singleton4 = FirstLoadSingleton.getSingleton();
    Assertions.assertEquals(singleton3, singleton4);

    SynchronizedThreadSafeSingleton singleton5 = SynchronizedThreadSafeSingleton.getSingleton();
    SynchronizedThreadSafeSingleton singleton6 = SynchronizedThreadSafeSingleton.getSingleton();
    Assertions.assertEquals(singleton5, singleton6);

    DoubleCheckLockSingleton singleton7 = DoubleCheckLockSingleton.getSingleton();
    DoubleCheckLockSingleton singleton8 = DoubleCheckLockSingleton.getSingleton();
    Assertions.assertEquals(singleton7, singleton8);

    InnerClassSingleton singleton9 = InnerClassSingleton.getSingleton();
    InnerClassSingleton singleton10 = InnerClassSingleton.getSingleton();
    Assertions.assertEquals(singleton9, singleton10);

    EnumSingleton singleton11 = EnumSingleton.Instance;
    EnumSingleton singleton12 = EnumSingleton.Instance;
    Assertions.assertEquals(singleton11, singleton12);
  }
}
