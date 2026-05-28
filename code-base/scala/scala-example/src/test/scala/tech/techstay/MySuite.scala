package tech.techstay

import munit.FunSuite
import org.apache.logging.log4j.LogManager

class MySuite extends FunSuite {
  test("example test") {
    val obtained = 42
    val expected = 42
    assertEquals(obtained, expected)
  }

  test("logback test") {
    val logger = LogManager.getLogger(getClass)
    logger.debug("This is a debug message")
    logger.info("This is an info message")
    logger.warn("This is a warning message")
    logger.error("This is an error message")
    logger.fatal("This is a fatal message")

    assert(true, "Logging test passed")
  }
}
