cmake_minimum_required(VERSION 3.20)

project(gameoflife VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)

# Основной исполняемый файл
add_executable(gameoflife
    src/main.cpp
    src/calc.h src/calc.cpp
    src/cell.h
    src/dumper.h src/dumper.cpp
    src/field.h src/field.cpp
    src/game.h src/game.cpp
    src/importer.h src/importer.cpp
    src/rule.h src/rule.cpp
    src/view.h src/view.cpp
)

# Тестируемый исполняемый файл
add_executable(gameoflife_tests
    tests/gameoflife_tests.cpp
    src/calc.h src/calc.cpp
    src/cell.h
    src/dumper.h src/dumper.cpp
    src/field.h src/field.cpp
    src/game.h src/game.cpp
    src/importer.h src/importer.cpp
    src/rule.h src/rule.cpp
    src/view.h src/view.cpp
)

# Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Связь с библиотекой GTest
target_link_libraries(gameoflife_tests GTest::gtest_main)

# Автоматическое обнаружение тестов
include(GoogleTest)
gtest_discover_tests(gameoflife_tests)
enable_testing()
