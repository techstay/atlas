package yitian.study.test;

import org.junit.Test;
import yitian.study.singleton.*;

import static org.assertj.core.api.Java6Assertions.assertThat;

public class SingletonTest {
    @Test
    public void testSingleton() {
        UnThreadSafeSingleton singleton1 = UnThreadSafeSingleton.getSingleton();
        UnThreadSafeSingleton singleton2 = UnThreadSafeSingleton.getSingleton();
        assertThat(singleton1 == singleton2).isTrue();

        FirstLoadSingleton singleton3 = FirstLoadSingleton.getSingleton();
        FirstLoadSingleton singleton4 = FirstLoadSingleton.getSingleton();
        assertThat(singleton3 == singleton4).isTrue();

        SynchronizedThreadSafeSingleton singleton5 = SynchronizedThreadSafeSingleton.getSingleton();
        SynchronizedThreadSafeSingleton singleton6 = SynchronizedThreadSafeSingleton.getSingleton();
        assertThat(singleton5 == singleton6).isTrue();

        DoubleCheckLockSingleton singleton7 = DoubleCheckLockSingleton.getSingleton();
        DoubleCheckLockSingleton singleton8 = DoubleCheckLockSingleton.getSingleton();
        assertThat(singleton7 == singleton8).isTrue();

        InnerClassSingleton singleton9 = InnerClassSingleton.getSingleton();
        InnerClassSingleton singleton10 = InnerClassSingleton.getSingleton();
        assertThat(singleton9 == singleton10).isTrue();

        EnumSingleton singleton11 = EnumSingleton.Instance;
        EnumSingleton singleton12 = EnumSingleton.Instance;
        assertThat(singleton11 == singleton12).isTrue();
    }
}
