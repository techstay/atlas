package tech.techstay;

import org.assertj.core.api.Assertions;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

@DisplayName("测试类可以指定显示名称")
public class DisplayNameTest {
  @Test
  @DisplayName("测试方法也可以指定显示名称")
  void testWithLongDisplayName() {
    Assertions.assertThat(true).isTrue();
  }

  @Test
  @DisplayName("显示名称还可以包含表情😻")
  void testWithDisplayNameWithEmoji() {
    Assertions.assertThat(true).isTrue();

  }
}
