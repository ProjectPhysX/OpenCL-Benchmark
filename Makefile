SRCDIR=src

VPATH=$(SRCDIR)

HDR=$(wildcard src/*.hpp)

PLATFORM=$(shell uname -s)

ifeq ($(PLATFORM),Darwin)
  LDLIBS=-framework OpenCL
else
  LDLIBS=-lOpenCL
endif

CROSS_COMPILE=/usr/bin/aarch64-linux-gnu-
LDFLAGS+='-L/usr/local/gcc_9/lib'
CXXFLAGS+='-I/usr/local/OpenCL-Headers'
CXXFLAGS+='-I$(SRCDIR)/OpenCL/include'
CXXFLAGS+=-std=c++17 -pthread -O -Wno-comment
CXX=$(CROSS_COMPILE)g++
LD=${CROSS_COMPILE}ld
AR=$(CROSS_COMPILE)ar
CC=$(CROSS_COMPILE)gcc


OBJS = $(patsubst %.cpp, %.o, $(wildcard src/*.cpp))

%.o: %.c $(HDR) Makefile
        @printf "  CXX        $(SRCDIR)/$@\n"
        @$(CXX) $(CXXFLAGS) -c $< -o $@

OpenCL-Benchmark: $(OBJS)
        @$(CXX) -o $@ $^ $(LDFLAGS) $(LDLIBS)


clean:
        rm -rf OpenCL-Benchmark
