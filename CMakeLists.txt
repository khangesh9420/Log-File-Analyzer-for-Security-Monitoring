cmake_minimum_required(VERSION 3.10)
project(LogFileAnalyzer)

set(CMAKE_CXX_STANDARD 17)

# Add the include directory
include_directories(include)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(LogFileAnalyzer src/main.cpp)

# Link with Conan dependencies
target_link_libraries(LogFileAnalyzer ${CONAN_LIBS})
