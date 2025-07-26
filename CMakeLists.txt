cmake_minimum_required(VERSION 3.15)
project(LogFileAnalyzer)

set(CMAKE_CXX_STANDARD 17)

# Add your source and header directories
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)
file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS include/*.h)

add_executable(LogFileAnalyzer ${SOURCES} ${HEADERS})

# Use Conan-generated find_package targets
find_package(fmt REQUIRED)
find_package(spdlog REQUIRED)
find_package(CURL REQUIRED)

target_include_directories(LogFileAnalyzer PRIVATE include)
target_link_libraries(LogFileAnalyzer
    fmt::fmt
    spdlog::spdlog
    CURL::libcurl
)
