import org.junit.jupiter.params.ParameterizedTest
import org.junit.jupiter.params.provider.ValueSource

class MyGroovyTest {
  boolean isPalindrome(String s) { s.reverse() == s }

  @ParameterizedTest
  @ValueSource(strings = ['a', 'aba', 'abccba', '123454321'])
  void palindromeTest(String s) {
    assert isPalindrome(s)
  }
}
