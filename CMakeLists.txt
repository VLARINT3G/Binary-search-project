cmake_minimum_required(VERSION 3.10)
project(BinarySearchProject)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${CMAKE_SOURCE_DIR}/src)

include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)

add_executable(main_bin_search src/main.cpp)

add_executable(test_bin_search tests/TestBinarySearch.cpp)

target_link_libraries(test_bin_search gtest_main)

enable_testing()

add_test(NAME BinarySearchTest COMMAND test_bin_search)
