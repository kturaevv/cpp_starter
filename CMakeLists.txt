cmake_minimum_required(VERSION 3.23.0)

set(PROJECT_NAME engine)
set(TEST_NAME tests)

# Project definition
project(${PROJECT_NAME} VERSION 1.0 LANGUAGES CXX)

# Common compile options
# Optional source formatting and source listing options
option(AUTOFORMAT_SRC_ON_CONFIGURE "Format sources with clang-format on configuration" ON)
option(LIST_SOURCE_FILES "Print all source files during configuration" ON)

# Define module path
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/")

# Locate and include source files
file(GLOB_RECURSE SOURCE_FILES "src/*.cpp")

# Main executable
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# External dependencies
find_package(fmt CONFIG REQUIRED)

target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt fmt::fmt-header-only)

# Debug-specific settings (inherited via presets)
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    message(STATUS "Debug mode detected: Enabling AddressSanitizer and adding tests")

    add_compile_options(
        -Wall
        -Wextra
        -Wpedantic
        -Werror
        -Wno-unused-variable
        -Wno-infinite-recursion
        -Werror=implicit-function-declaration
        -Wshadow
        -Wuninitialized
        -Wunused-label
        -Wunused-lambda-capture
    )

    # Enable AddressSanitizer in Debug mode
    target_compile_options(${PROJECT_NAME} PUBLIC -fsanitize=address -fno-omit-frame-pointer)
    target_link_libraries(${PROJECT_NAME} PUBLIC -fsanitize=address)

    # Locate and include test files
    file(GLOB_RECURSE TEST_FILES "tests/*.cpp")
    add_executable(${TEST_NAME} ${TEST_FILES})

    # External dependency for tests
    find_package(Catch2 3 REQUIRED)

    # Link tests to dependencies
    target_link_libraries(${TEST_NAME} PRIVATE Catch2::Catch2WithMain fmt::fmt fmt::fmt-header-only)
endif()

# Option to print source files
if(LIST_SOURCE_FILES)
    include(print-source-files)
endif()

# Option to auto-format sources
if(AUTOFORMAT_SRC_ON_CONFIGURE)
    include(clang-format)
endif()

# Output the C++ compiler path for debugging purposes
message(STATUS "C++ Compiler: ${CMAKE_CXX_COMPILER}")
