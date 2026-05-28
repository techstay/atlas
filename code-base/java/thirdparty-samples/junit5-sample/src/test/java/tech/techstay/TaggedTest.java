package tech.techstay;

import org.assertj.core.api.Assertions;
import org.junit.jupiter.api.Tag;
import org.junit.jupiter.api.Test;

@Tag("taggedTest")
public class TaggedTest {
  @Test
  @Tag("taggedTest1")
  void testWithTag1() {
    Assertions.assertThat(2).isEven();
  }

  @Test
  @Tag("taggedTest2")
  void testWithTag2() {
    Assertions.assertThat(5).isOdd();
  }
}
