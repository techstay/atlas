package tech.techstay;

import org.aeonbits.owner.ConfigFactory;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

public class OwnerSample {
  public static void main(String[] args) {
    MyConfig config = ConfigFactory.create(MyConfig.class);
    Logger logger = LogManager.getLogger();

    logger.info(config.username());
    logger.info(config.password());
    logger.info(config.port());
    logger.info(config.fooBar());
  }
}
