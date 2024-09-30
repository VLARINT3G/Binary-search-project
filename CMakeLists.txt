cmake_minimum_required(VERSION 3.10)

project(BinarySearchProject)

# Указываем стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Источники программы
set(SOURCE_FILES
        src/main.cpp
        src/BinarySearch.cpp
        src/SimpleLogger.cpp
)

# Создание исполняемого файла
add_executable(main_bin_search ${SOURCE_FILES})

# Включаем тестирование и подключаем GoogleTest
enable_testing()

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Добавляем тестируемый исполняемый файл
add_executable(test_binary_search
        tests/TestBinarySearch.cpp
        src/BinarySearch.cpp
        src/SimpleLogger.cpp
)

# Линкуем GoogleTest с тестовым исполняемым файлом
target_link_libraries(test_binary_search gtest gtest_main)
target_include_directories(test_binary_search PRIVATE src)

# Определяем тесты
add_test(NAME BinarySearchTests COMMAND test_binary_search)

# Поддержка Doxygen для генерации документации
find_package(Doxygen)
if(DOXYGEN_FOUND)
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

    add_custom_command(
            OUTPUT ${DOXYGEN_OUT}
            COMMAND ${CMAKE_COMMAND} -E copy ${DOXYGEN_IN} ${DOXYGEN_OUT}
            DEPENDS ${DOXYGEN_IN}
    )

    add_custom_target(doc ALL
            COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
            COMMENT "Генерация API документации с помощью Doxygen"
            VERБATIM
    )
endif()
