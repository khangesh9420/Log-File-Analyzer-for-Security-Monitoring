#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <fmt/core.h>
#include <spdlog/spdlog.h>
#include "LogAnalyzer.h"  // Class header

int main(int argc, char* argv[]) {
    if (argc < 2 || std::string(argv[1]) == "--help") {
        fmt::print("Usage: LogAnalyzer <log_file_path>\n");
        fmt::print("Example: LogAnalyzer logs/server_logs.txt\n");
        return 0;
    }

    std::string logFilePath = argv[1];
    spdlog::info("Starting log analysis for: {}", logFilePath);

    try {
        LogAnalyzer analyzer(logFilePath);
        analyzer.analyzeLogs();
    } catch (const std::exception& ex) {
        spdlog::error("An error occurred: {}", ex.what());
        return 1;
    }

    return 0;
}
