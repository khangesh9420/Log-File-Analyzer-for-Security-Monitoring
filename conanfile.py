from conan import ConanFile
from conan.tools.cmake import CMake

class LogFileAnalyzerConan(ConanFile):
    name = "LogFileAnalyzer"
    version = "1.0"
    license = "MIT"
    author = "Khangesh Matte <khangeshmatte@gmail.com>"
    description = "Log File Analyzer for detecting suspicious activities"
    topics = ("security", "log", "monitoring", "analyzer")
    settings = "os", "arch", "compiler", "build_type"
    generators = "CMakeToolchain", "CMakeDeps"
    exports_sources = "*"

    requires = (
        "fmt/7.1.3",
        "spdlog/1.8.5",
        "libcurl/7.87.0"
    )

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.install()

    def package_info(self):
        self.cpp_info.libs = ["LogFileAnalyzer"]
