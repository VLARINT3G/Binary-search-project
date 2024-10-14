#pragma once

#include <string>

/**
 * @enum LogLevel
 * @brief Определяет уровни логирования.
 */
enum class LogLevel {
    INFO,
    WARNING,
    ERROR
};

/**
 * @class SimpleLogger
 * @brief Класс для простого логирования с уровнями в файл.
 *
 * Этот класс предоставляет статический метод для записи сообщений с уровнем логирования в файл логов.
 */
class SimpleLogger {
public:
    /**
     * @brief Запись сообщения в лог с указанным уровнем.
     *
     * Записывает строку сообщения с указанным уровнем в файл "binary_search.log".
     *
     * @param message Сообщение для записи в лог.
     * @param level Уровень логирования.
     */
    static void log(const std::string& message, LogLevel level = LogLevel::INFO);

private:
    /**
     * @brief Получает строковое представление уровня логирования.
     *
     * @param level Уровень логирования.
     * @return std::string Строковое представление уровня.
     */
    static std::string getLogLevelString(LogLevel level);

    /**
     * @brief Получает текущую метку времени.
     *
     * @return std::string Текущая метка времени в формате "YYYY-MM-DD HH:MM:SS".
     */
    static std::string getCurrentTimestamp();
};
