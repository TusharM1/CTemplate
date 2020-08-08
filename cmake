# Create build directory for cmake output
mkdir -r build build/x64-Debug build/x64-Release

# Initialize CMake for 64 bit release and debug modes
cmake -B build/x64-Debug -DCMAKE_BUILD_TYPE=Debug
cmake -B build/x64-Release -DCMAKE_BUILD_TYPE=Release
