SRCDIR=src

HDR=$(wildcard src/*.hpp)
OBJS = $(patsubst %.cpp, %.o, $(wildcard src/*.cpp))

PLATFORM=$(shell uname -s)

ifeq ($(PLATFORM),Darwin)
  LDLIBS=-framework OpenCL
else
  LDLIBS=-lOpenCL
endif

#CROSS_COMPILE=/usr/local/bin/aarch64-linux-gnu-

ifneq ($(CROSS_COMPILE),)
  #LDFLAGS+=-L/usr/local/gcc_9/lib
  #CXXFLAGS+=-I/usr/local/include/OpenCL-Headers
else ifeq ($(PLATFORM),Linux)
  CXXFLAGS+=-L./src/OpenCL/lib
else ifeq ($(PLATFORM),Android)
  CXXFLAGS+=-L/system/vendor/lib64
endif

LDFLAGS+=-L$(SRCDIR)/OpenCL/lib
CXXFLAGS+=-I$(SRCDIR)/OpenCL/include
CXXFLAGS+=-std=c++17 -pthread -O -Wno-comment
CXX=$(CROSS_COMPILE)g++
LD=${CROSS_COMPILE}ld
AR=$(CROSS_COMPILE)ar
CC=$(CROSS_COMPILE)gcc

.PHONY: all clean bin/OpenCL-Benchmark run

all: bin/OpenCL-Benchmark

%.o: %.cpp $(HDR) Makefile
        @printf "  CXX        $<\n"
        @$(CXX) $(CXXFLAGS) -L. -c $< -o $@

bin/OpenCL-Benchmark: $(OBJS)
        @mkdir -p bin
        @printf "  LINK       $@\n"
        @$(CXX) -o $@ $^ $(LDFLAGS) $(LDLIBS)

clean:
        @printf "  CLEAN      bin/OpenCL-Benchmark\n"
        @rm -f $(OBJS)
        @rm -rf bin

run:
        @bin/OpenCL-Benchmark
