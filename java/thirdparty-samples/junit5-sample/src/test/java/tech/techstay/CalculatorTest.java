package tech.techstay;

import org.assertj.core.api.Assertions;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.Disabled;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

@DisplayName("calculator test")
public class CalculatorTest {
  static Calculator calculator;

  @BeforeAll
  static void init() {
    calculator = new Calculator();
  }

  @Test
  void testPlus() {
    Assertions.assertThat(calculator.plus(6, 4)).isEqualTo(10);
  }


  @Test
  void testException() {
    Assertions.assertThatExceptionOfType(UnsupportedOperationException.class)
        .isThrownBy(() -> calculator.multiple(6, 4)).withMessageContaining("not yet implemented");
  }

  @Test
  @Disabled("This will fail")
  void testFail() {
    Assertions.assertThat(calculator.minus(6, 4)).isEqualTo(2);
  }
}
