package tech.techstay;


import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Tag;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.TestInfo;

import java.util.Collections;

import static org.assertj.core.api.Assertions.assertThat;

public class DependencyInjectionTest {
  @Test
  @DisplayName("依赖注入")
  @Tag("test")
  void testDisplayName(TestInfo testInfo) {
    assertThat(testInfo.getDisplayName()).isEqualTo("依赖注入");
    assertThat(testInfo.getTags()).isEqualTo(Collections.singleton("test"));
  }
}
