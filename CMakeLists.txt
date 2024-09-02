cmake_minimum_required(VERSION 3.10)

project(BinarySearchProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCE_FILES
        src/main.cpp        # Путь к main.cpp
        src/BinarySearch.cpp # Путь к BinarySearch.cpp
)

add_executable(main_bin_search ${SOURCE_FILES})

target_include_directories(main_bin_search PRIVATE src)

enable_testing()

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(test_binary_search
        tests/TestBinarySearch.cpp  # Путь к тестовому файлу
        src/BinarySearch.cpp        # Подключение реализации для тестов
)

target_link_libraries(test_binary_search gtest gtest_main)

target_include_directories(test_binary_search PRIVATE src)

add_test(NAME BinarySearchTests COMMAND test_binary_search)
