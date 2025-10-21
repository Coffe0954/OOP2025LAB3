cmake_minimum_required(VERSION 3.10)
project(Lab03_OOP)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Основная программа
add_executable(lab03
    src/main.cpp
    src/Triangle.cpp
    src/Square.cpp
    src/Rectangle.cpp
    src/Array.cpp
)

target_include_directories(lab03 PRIVATE include)

# Тесты
enable_testing()

find_package(GTest REQUIRED)

add_executable(tests
    tests/test_figures.cpp
    src/Triangle.cpp
    src/Square.cpp
    src/Rectangle.cpp
    src/Array.cpp
)

target_include_directories(tests PRIVATE include)
target_link_libraries(tests GTest::gtest GTest::gtest_main)

add_test(NAME FiguresTests COMMAND tests)