package tech.techstay;

import org.assertj.core.api.Assertions;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Nested;
import org.junit.jupiter.api.Test;

@DisplayName("外层测试")
public class NestedTest {
  @Test
  void testOuter() {
    Assertions.assertThat(true).isTrue();
  }

  @Nested
  @DisplayName("内层测试")
  class InnerTestDemo {
    @Test
    void testInner() {
      Assertions.assertThat(true).isTrue();
    }
  }
}
