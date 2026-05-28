package tech.techstay.log4j2;


import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

public class Log4j2Logging {
  private static final Logger logger = LogManager.getLogger();

  public static void main(String[] args) {
    logger.info("Hello world");
    logger.debug("debugging logging");
    logger.warn("have a rest! You have been working so long");
    logger.error("some error");
    logger.fatal("fatal error");

    try {
      throw new UnsupportedOperationException("Unsupported Operation");
    } catch (UnsupportedOperationException ex) {
      logger.catching(ex);
    }
  }
}
