#pragma once

#include <fstream>
#include <string>

/**
 * @class SimpleLogger
 * @brief Класс для простого логирования в файл.
 *
 * Этот класс предоставляет статический метод для записи сообщений в файл логов.
 */
class SimpleLogger {
public:
    /**
     * @brief Запись сообщения в лог.
     *
     * Записывает строку сообщения в файл "binary_search.log".
     *
     * @param message Сообщение для записи в лог.
     */
    static void log(const std::string& message);
};
