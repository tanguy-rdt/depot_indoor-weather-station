#include "std_logger.h"

#include <iostream>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <string>
#include <ctime>


#define DEFAULT_COLOR "\033[0m"
#define GREY          "\033[90m"
#define CYAN          "\033[36m"
#define ORANGE        "\033[33m"
#define RED           "\033[31m"

#define RED_HIGHLIGHT "\033[41m"

#define DEFAULT_STYLE ""
#define BOLD          "\033[1m"
#define ITALIC        "\033[3m"
#define BOLD_ITALIC   "\033[1;3m"


StdLogger::StdLogger(LogLevel level) 
    : _level(level) {
}

StdLogger::~StdLogger() {

}

void StdLogger::setLevel(LogLevel level) {
    _level = level;
}

void StdLogger::log(LogLevel level, const std::string& message) {
     if (level >= _level) {
        std::cout << levelToColor(level) << levelToStyle(level)
                  << "[" << getTimestamp() << "] -- " << levelToString(level) << " : " << message 
                  << levelToStyle(level) << levelToColor(LogLevel::NONE) << std::endl;
    }
}

std::string StdLogger::levelToString(LogLevel level) const {
    switch (level) {
        case LogLevel::DEBUG:    return "DEBUG";
        case LogLevel::INFO:     return "INFO";
        case LogLevel::WARNING:  return "WARNING";
        case LogLevel::ERROR:    return "ERROR";
        case LogLevel::CRITICAL: return "CRITICAL";
        default:                 return "UNKNOWN";
    }
}

std::string StdLogger::levelToColor(LogLevel level) const {
    switch (level) {
        case LogLevel::DEBUG:    return CYAN;
        case LogLevel::INFO:     return GREY;
        case LogLevel::WARNING:  return ORANGE;
        case LogLevel::ERROR:    return RED;
        case LogLevel::CRITICAL: return RED_HIGHLIGHT;
        default:                 return DEFAULT_COLOR;
    }
}

std::string StdLogger::levelToStyle(LogLevel level) const {
    switch (level) {
        case LogLevel::DEBUG:    return DEFAULT_STYLE;
        case LogLevel::INFO:     return ITALIC;
        case LogLevel::WARNING:  return DEFAULT_STYLE;
        case LogLevel::ERROR:    return BOLD;
        case LogLevel::CRITICAL: return BOLD_ITALIC;
        default:                 return DEFAULT_STYLE;
    }
}

std::string StdLogger::getTimestamp() const {
    auto now = std::chrono::system_clock::now();
    std::time_t timeT = std::chrono::system_clock::to_time_t(now);
    std::tm tm = *std::localtime(&timeT);

    std::ostringstream time;
    time << std::put_time(&tm, "%H:%M:%S");

    return time.str();
}