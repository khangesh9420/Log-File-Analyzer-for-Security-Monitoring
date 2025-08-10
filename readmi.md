# Log File Analyzer for Security Monitoring

A small C++17 utility that scans a log file and reports IP addresses with repeated failed login attempts.

## Features
- Parses simple space-delimited logs
- Detects IPs with three or more failed login attempts
- Uses [`fmt`](https://fmt.dev/) and [`spdlog`](https://spdlog.dev/) for formatted and structured output

## Requirements
- g++ with C++17 support
- `libfmt` and `spdlog` development libraries

## Building
### Using g++ directly
```bash
sudo apt-get install g++ libfmt-dev libspdlog-dev
 g++ -std=c++17 src/main.cpp src/LogAnalyzer.cpp -Iinclude -lfmt -lspdlog -o LogFileAnalyzer
```

### Using the provided script
The repository includes `build.sh` which uses Conan and CMake to manage dependencies and build the project. Conan 2 introduces breaking CLI changes, so the script may require updates if you're using the latest version.

## Usage
Run the executable and provide a path to a log file:
```bash
./LogFileAnalyzer server_logs.txt
```
The log file should contain entries in the form:
```
TIMESTAMP IP ACTION
```
`ACTION` should be `FAIL` to count as a failed login attempt.

Example output:
```
Suspicious IPs:
192.168.1.100 => 3 failed attempts
```

## Sample Data
`server_logs.txt` provides a small example log to test the analyzer.

## License
This project is licensed under the MIT License. See [LICENSE](LICENSE) for details.
