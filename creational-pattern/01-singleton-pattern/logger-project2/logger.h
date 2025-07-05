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

    // Method to log messages
    void (*log)(LogLevel level, const char *format, ...);

    // Specific methods for each log level
    // void (*e)(struct Logger *self, const char *format, ...);    // Emergency
    // void (*a)(struct Logger *self, const char *format, ...);    // Alert
    // void (*c)(struct Logger *self, const char *format, ...);    // Critical
    // void (*err)(struct Logger *self, const char *format, ...);  // Error
    // void (*w)(struct Logger *self, const char *format, ...);    // Warning
    // void (*n)(struct Logger *self, const char *format, ...);    // Notice
    // void (*i)(struct Logger *self, const char *format, ...);    // Informational
    // void (*d)(struct Logger *self, const char *format, ...);    // Debug
} Logger;

// Declare the global Logger instance
extern Logger *logger;

// Function declarations
void initializeLogger();              // Initialize the Logger instance
void setLogLevel(LogLevel level);     // Set the log level

#endif // LOGGER_H