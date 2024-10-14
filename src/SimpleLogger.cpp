#include "SimpleLogger.h"
#include <fstream>
#include <ctime>
#include <iostream>

void SimpleLogger::log(const std::string& message, LogLevel level) {
    std::ofstream logFile("binary_search.log", std::ios::out | std::ios::app);
    if (logFile.is_open()) {
        logFile << "[" << getCurrentTimestamp() << "] "
                << "[" << getLogLevelString(level) << "] "
                << message << std::endl;
    }
}

std::string SimpleLogger::getLogLevelString(LogLevel level) {
    switch (level) {
        case LogLevel::INFO:
            return "INFO";
        case LogLevel::WARNING:
            return "WARNING";
        case LogLevel::ERROR:
            return "ERROR";
        default:
            return "UNKNOWN";
    }
}

std::string SimpleLogger::getCurrentTimestamp() {
    auto now = std::time(nullptr);
    auto tm = *std::localtime(&now);
    char buffer[20];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &tm);
    return buffer;
}
