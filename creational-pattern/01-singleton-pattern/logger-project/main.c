#include "logger.h"

int main() {
    // Get the singleton logger instance
    Logger *logger = getLoggerInstance();

    // Set log level to WARNING
    setLogLevel(LOG_WARNING);

    // Log messages of different levels
    logger->log(LOG_EMERGENCY, "This is an emergency message.");
    logger->log(LOG_ALERT, "This is an alert message.");
    logger->log(LOG_CRITICAL, "This is a critical message.");
    logger->log(LOG_ERROR, "This is an error message.");
    logger->log(LOG_WARNING, "This is a warning message.");
    logger->log(LOG_NOTICE, "This is a notice message.");
    logger->log(LOG_INFORMATIONAL, "This is an informational message.");
    logger->log(LOG_DEBUG, "This is a debug message.");

    return 0;
}