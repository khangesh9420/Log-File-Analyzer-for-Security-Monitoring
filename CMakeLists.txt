cmake_minimum_required(VERSION 3.10)
project(LogFileAnalyzer)

set(CMAKE_CXX_STANDARD 17)

# Add the include directory
include_directories(include)

# Set up Conan for dependency management
include(${CMAKE_BINARY_DIR}/conan_toolchain.cmake)

# Add the source files
add_executable(LogFileAnalyzer src/main.cpp)

# Link with Conan dependencies (fmt, spdlog, curl, etc.)
target_link_libraries(LogFileAnalyzer CONAN_PKG::fmt CONAN_PKG::spdlog CONAN_PKG::libcurl)
