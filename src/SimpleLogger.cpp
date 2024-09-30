#include "SimpleLogger.h"

/**
 * @brief Запись сообщения в файл "binary_search.log".
 *
 * Открывает файл для записи (в режиме добавления), записывает сообщение, и закрывает файл.
 *
 * @param message Строка сообщения для записи в лог.
 */
void SimpleLogger::log(const std::string& message) {
    std::ofstream logFile;
    logFile.open("binary_search.log", std::ios::out | std::ios::app);
    if (logFile.is_open()) {
        logFile << message << std::endl;
        logFile.close();
    }
}
