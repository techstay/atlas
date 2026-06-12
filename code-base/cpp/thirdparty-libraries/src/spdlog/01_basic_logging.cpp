#include <print>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

int main()
{
    // create a colored logger
    auto logger = spdlog::stdout_color_mt("console");
    logger->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%^%l%$] [%s:%#] %v");

    // log levels
    logger->trace("Trace message");
    logger->debug("Debug message");
    logger->info("Info message");
    logger->warn("Warning message");
    logger->error("Error message");
    logger->critical("Critical message");

    // set level
    logger->set_level(spdlog::level::debug);
    logger->debug("This debug message appears");
    logger->set_level(spdlog::level::info);

    // SPDLOG_VER
    std::println("spdlog version: {}.{}.{}", SPDLOG_VER_MAJOR, SPDLOG_VER_MINOR, SPDLOG_VER_PATCH);

    return 0;
}
