#ifndef LOGANALYZER_H
#define LOGANALYZER_H

#include <string>
#include <vector>
#include <unordered_map>

struct LogEntry {
    std::string timestamp;
    std::string ipAddress;
    std::string action;
};

class LogAnalyzer {
public:
    LogAnalyzer(const std::string& logFile);
    void analyzeLogs();

private:
    std::vector<LogEntry> logs;
    std::unordered_map<std::string, int> failedLoginAttempts;
    std::unordered_map<std::string, int> suspiciousIPCount;

    void readLogFile(const std::string& logFile);
    LogEntry parseLogLine(const std::string& line);
    void checkFailedLoginAttempts();
    void checkSuspiciousIPs();
    void printReport();
};

#endif // LOGANALYZER_H
