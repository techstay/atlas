package tech.techstay.standard;

import java.util.logging.Level;
import java.util.logging.Logger;

public class StandardLogging {
  public static void main(String[] args) {
    Logger logger = Logger.getLogger("standard logger");

    logger.info("hello world");
    logger.warning("you should rest now!");
    logger.severe("danger operation detected!");

    greet(logger);
  }

  static void greet(Logger logger) {
    logger.log(Level.SEVERE, "encounter some error!");
  }
}
