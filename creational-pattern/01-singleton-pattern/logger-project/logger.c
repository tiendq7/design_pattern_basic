#include "logger.h"
#include <stdlib.h>

// Singleton instance
static Logger *singletonLogger = NULL;

// Function to log messages
void logMessage(LogLevel level, const char *format, ...) {
    if (singletonLogger == NULL || level > singletonLogger->currentLogLevel) {
        return;
    }

    // Map log levels to text
    const char *logLevelNames[] = {
        "EMERGENCY", "ALERT", "CRITICAL", "ERROR",
        "WARNING", "NOTICE", "INFORMATIONAL", "DEBUG"
    };

    // Print log level
    printf("[%s] ", logLevelNames[level]);

    // Handle variable arguments
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);

    printf("\n");
}

// Function to get the singleton logger instance
Logger *getLoggerInstance() {
    if (singletonLogger == NULL) {
        singletonLogger = (Logger *)malloc(sizeof(Logger));
        if (singletonLogger == NULL) {
            fprintf(stderr, "Failed to allocate memory for Logger\n");
            exit(EXIT_FAILURE);
        }
        singletonLogger->currentLogLevel = LOG_DEBUG; // Default log level
        singletonLogger->log = logMessage;
    }
    return singletonLogger;
}

// Function to set the log level
void setLogLevel(LogLevel level) {
    if (singletonLogger != NULL) {
        singletonLogger->currentLogLevel = level;
    }
}