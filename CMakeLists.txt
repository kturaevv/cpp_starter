cmake_minimum_required(VERSION 3.21)

project(cpp_template VERSION 1.0)

# Set C++ standard and compile options
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_COLOR_DIAGNOSTICS ON)
set(CMAKE_MESSAGE_LOG_LEVEL STATUS)

# Include cmake module
list(APPEND CMAKE_MODULE_PATH
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/"
)

# Set source files
file(GLOB_RECURSE SOURCE_FILES "src/*.[ch]pp")
file(GLOB_RECURSE TEST_FILES "tests/*.[ch]pp")

# Check source files that have been included
message(STATUS " " ${SOURCE_FILES} ${TEST_FILES})

# Add executable and link libraries if needed
add_executable(cpp_template ${SOURCE_FILES})
add_executable(tests ${TEST_FILES})

find_package(fmt CONFIG REQUIRED)
target_link_libraries(cpp_template PRIVATE fmt::fmt)

# These tests can use the Catch2-provided main
find_package(Catch2 3 REQUIRED)

target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
target_include_directories(tests PRIVATE ${Catch2_INCLUDE_DIRS})
