from loguru import logger


def exception():
    raise ValueError("This is an exception")


def main():
    logger.info("some infomation")
    logger.debug("some debug information")
    logger.warning("some warning")
    logger.error("some error")
    logger.critical("some critical information")
    try:
        exception()
    except Exception as e:
        logger.exception(e)


if __name__ == "__main__":
    main()
