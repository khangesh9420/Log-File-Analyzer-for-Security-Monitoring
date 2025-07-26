#include "LogAnalyzer.h"
#include <iostream>
#include <fstream>
#include <sstream>

LogAnalyzer::LogAnalyzer(const std::string& logFile) {
    readLogFile(logFile);
}

void LogAnalyzer::analyzeLogs() {
    checkFailedLoginAttempts();
    checkSuspiciousIPs();
    printReport();
}

void LogAnalyzer::readLogFile(const std::string& logFile) {
    std::ifstream file(logFile);
    std::string line;

    while (std::getline(file, line)) {
        logs.push_back(parseLogLine(line));
    }
}

LogEntry LogAnalyzer::parseLogLine(const std::string& line) {
    std::istringstream ss(line);
    std::string timestamp, ip, action;
    ss >> timestamp >> ip >> action;
    return {timestamp, ip, action};
}

void LogAnalyzer::checkFailedLoginAttempts() {
    for (const auto& entry : logs) {
        if (entry.action == "FAIL") {
            failedLoginAttempts[entry.ipAddress]++;
        }
    }
}

void LogAnalyzer::checkSuspiciousIPs() {
    for (const auto& [ip, count] : failedLoginAttempts) {
        if (count >= 3) {
            suspiciousIPCount[ip] = count;
        }
    }
}

void LogAnalyzer::printReport() {
    std::cout << "Suspicious IPs:\n";
    for (const auto& [ip, count] : suspiciousIPCount) {
        std::cout << ip << " => " << count << " failed attempts\n";
    }
}
