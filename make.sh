# command line argument(s): device ID(s); if empty, it will benchmark all available devices

mkdir -p bin # create directory for executable
rm -f ./bin/OpenCL-Benchmark # prevent execution of old version if compiling fails

g++ ./src/*.cpp -o ./bin/OpenCL-Benchmark -std=c++17 -pthread -I./src/OpenCL/include -L./src/OpenCL/lib -lOpenCL # compile on Linux
#g++ ./src/*.cpp -o ./bin/OpenCL-Benchmark -std=c++17 -pthread -I./src/OpenCL/include -framework OpenCL # compile on macOS
#g++ ./src/*.cpp -o ./bin/OpenCL-Benchmark -std=c++17 -pthread -I./src/OpenCL/include -L/system/vendor/lib64 -lOpenCL # compile on Android

./bin/OpenCL-Benchmark "$@" # run OpenCL-Benchmark
