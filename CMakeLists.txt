# CMakeLists.txt in the project root
cmake_minimum_required(VERSION 3.21)

project(project_name VERSION 1.0)

message(COMMENT ${SOURCE_FILES})

# Set C++ standard and compile options
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set g++ as the C++ compiler
set(CMAKE_CXX_COMPILER g++)

# Set source files
file(GLOB_RECURSE SOURCE_FILES "src/*.cpp")
file(GLOB_RECURSE HEADER_FILES "src/*.hpp")

# Add executable and link libraries if needed
add_executable(project_name ${SOURCE_FILES} ${HEADER_FILES})

# Example: Include directories if needed
target_include_directories(project_name PUBLIC include)
