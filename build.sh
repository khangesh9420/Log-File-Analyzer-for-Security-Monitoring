#!/bin/bash

set -e  # Exit immediately if any command fails

# Step 1: Create the build directory (if it doesn't exist)
echo "Creating build directory..."
mkdir -p build
cd build

# Step 2: Install dependencies with Conan
# Using --install-folder to direct Conan to put everything in the build directory
echo "Installing dependencies with Conan..."
conan install .. --build=missing --settings os=Linux --settings compiler=gcc --settings compiler.version=10 --settings compiler.libcxx=libstdc++11 --install-folder=build/conan

# Step 3: Run CMake to configure the project
echo "Configuring project with CMake..."
cmake .. -DCMAKE_TOOLCHAIN_FILE=build/conan/conan_toolchain.cmake

# Step 4: Build the project
echo "Building the project..."
make

# Step 5: Run the executable
echo "Running the application..."
./LogFileAnalyzer
