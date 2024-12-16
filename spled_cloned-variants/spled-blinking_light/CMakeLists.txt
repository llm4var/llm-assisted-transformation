cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(BlinkingLight VERSION 1.0)

# Add the source files, excluding test files
file(GLOB_RECURSE SOURCES "src/*.c")
file(GLOB_RECURSE HEADERS "src/*.h")

# Add the executable
add_executable(BlinkingLight ${SOURCES} ${HEADERS})