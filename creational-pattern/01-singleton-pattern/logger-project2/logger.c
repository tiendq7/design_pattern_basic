#include "logger.h"
#include <stdlib.h>

// Define the global Logger instance
Logger *logger = NULL;

// Function to log messages
void logMessage(LogLevel level, const char *format, ...) {
    if (logger == NULL || level > logger->currentLogLevel) {
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

// Function to initialize the Logger instance
void initializeLogger() {
    if (logger == NULL) {
        logger = (Logger *)malloc(sizeof(Logger));
        if (logger == NULL) {
            fprintf(stderr, "Failed to allocate memory for Logger\n");
            exit(EXIT_FAILURE);
        }
        logger->currentLogLevel = LOG_DEBUG; // Default log level
        logger->log = logMessage;
    }
}

// Function to set the log level
void setLogLevel(LogLevel level) {
    if (logger != NULL) {
        logger->currentLogLevel = level;
    }
}