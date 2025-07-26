#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <fmt/core.h>
#include <spdlog/spdlog.h>
#include "LogAnalyzer.h"  // Include the header file

int main() {
    std::string logFilePath = "server_logs.txt"; // Replace with your log file path
    LogAnalyzer analyzer(logFilePath);
    analyzer.analyzeLogs();
    return 0;
}
