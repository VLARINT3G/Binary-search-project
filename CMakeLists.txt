cmake_minimum_required(VERSION 3.10)
project(BinarySearchProject)

# Устанавливаем стандарт C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Указываем CMake, где искать заголовочные файлы
include_directories(${CMAKE_SOURCE_DIR}/src)

# Подключаем FetchContent для загрузки GoogleTest
include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)

# Создаем исполняемый файл для основной программы
add_executable(main_bin_search src/main.cpp)

# Создаем исполняемый файл для тестов
add_executable(test_bin_search tests/TestBinarySearch.cpp)

# Линкуем GoogleTest с тестами
target_link_libraries(test_bin_search gtest_main)

# Включаем тестирование
enable_testing()

# Добавляем тесты
add_test(NAME BinarySearchTest COMMAND test_bin_search)
