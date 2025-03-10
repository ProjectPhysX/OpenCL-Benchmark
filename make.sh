#!/usr/bin/env bash
# command line argument(s): device ID(s); if empty, it will benchmark all available devices

mkdir -p bin # create directory for executable
rm -f bin/OpenCL-Benchmark # prevent execution of old version if compiling fails

case "$(uname -a)" in # automatically detect operating system
	 Darwin*) g++ src/*.cpp -o bin/OpenCL-Benchmark -std=c++17 -pthread -O -Wno-comment -I./src/OpenCL/include -framework OpenCL               ;; # macOS
	*Android) g++ src/*.cpp -o bin/OpenCL-Benchmark -std=c++17 -pthread -O -Wno-comment -I./src/OpenCL/include -L/system/vendor/lib64 -lOpenCL ;; # Android
	*       ) g++ src/*.cpp -o bin/OpenCL-Benchmark -std=c++17 -pthread -O -Wno-comment -I./src/OpenCL/include -L./src/OpenCL/lib -lOpenCL     ;; # Linux
esac

if [[ $? == 0 ]]; then bin/OpenCL-Benchmark "$@"; fi # run executable only if last compilation was successful
