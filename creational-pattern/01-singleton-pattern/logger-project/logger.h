#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>
#include <stdarg.h>

// Define log levels
typedef enum {
    LOG_EMERGENCY = 0,
    LOG_ALERT,
    LOG_CRITICAL,
    LOG_ERROR,
    LOG_WARNING,
    LOG_NOTICE,
    LOG_INFORMATIONAL,
    LOG_DEBUG
} LogLevel;

// Logger structure
typedef struct {
    LogLevel currentLogLevel;
    void (*log)(LogLevel level, const char *format, ...);
} Logger;

// Function declarations
Logger *getLoggerInstance();
void setLogLevel(LogLevel level);

#endif // LOGGER_H