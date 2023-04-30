# OpenCL-Benchmark

A small [OpenCL](https://github.com/ProjectPhysX/OpenCL-Wrapper "OpenCL-Wrapper") benchmark program to measure peak GPU/CPU performance.

Works with any GPU in Windows, Linux, macOS and Android.



## Features
- compute performance (FP64, FP32, FP16, INT64, INT32, INT16, INT8)
- memory bandwidth (coalesced/misaligned read/write)
- PCIe bandwidth (send/receive/bidirectional)



## How to use?

### Windows
- Compile+Run
  - open `OpenCL-Benchmark.vcxproj` in Visual Studio Community
  - select "Release" and "x64" and hit compile+run
- Run
  ```
  OpenCL-Benchmark.exe
  ```

### Linux
- Compile+Run
  ```
  git clone https://github.com/ProjectPhysX/OpenCL-Benchmark.git
  cd OpenCL-Benchmark
  chmod +x make.sh
  ./make.sh
  ```
- Run
  ```
  bin/OpenCL-Benchmark
  ```

### macOS
- Compile+Run
  ```
  git clone https://github.com/ProjectPhysX/OpenCL-Benchmark.git
  cd OpenCL-Benchmark
  vim make.sh
  # press i, comment the line "compile on Linux" line with an "#", uncomment "compile on macOS" line by removing the "#" in front of the line, press Esc : w q Enter
  chmod +x make.sh
  ./make.sh
  ```
- Run
  ```
  bin/OpenCL-Benchmark
  ```

### Run only for a specified list of devices
- call `OpenCL-Benchmark.exe 0 2 5` (Windows) or `bin/OpenCL-Benchmark 0 2 5` (Linux/macOS) with the number(s) being the device IDs to be benchmarked



## Examples
```
.-----------------------------------------------------------------------------.
|----------------.------------------------------------------------------------|
| Device ID    0 | NVIDIA A100-PCIE-40GB                                      |
| Device ID    1 | NVIDIA GeForce RTX 2080 Ti                                 |
| Device ID    2 | NVIDIA GeForce RTX 2080 Ti                                 |
| Device ID    3 | NVIDIA GeForce RTX 2080 Ti                                 |
| Device ID    4 | NVIDIA GeForce RTX 2080 Ti                                 |
| Device ID    5 | NVIDIA GeForce RTX 2080 Ti                                 |
| Device ID    6 | NVIDIA GeForce RTX 2080 Ti                                 |
| Device ID    7 | NVIDIA GeForce RTX 2080 Ti                                 |
|----------------'------------------------------------------------------------|
|----------------.------------------------------------------------------------|
| Device ID      | 0                                                          |
| Device Name    | NVIDIA A100-PCIE-40GB                                      |
| Device Vendor  | NVIDIA Corporation                                         |
| Device Driver  | 525.89.02                                                  |
| OpenCL Version | OpenCL C 1.2                                               |
| Compute Units  | 108 at 1410 MHz (6912 cores, 19.492 TFLOPs/s)              |
| Memory, Cache  | 40513 MB, 3024 KB global / 48 KB local                     |
| Buffer Limits  | 10128 MB global, 64 KB constant                            |
|----------------'------------------------------------------------------------|
| Info: OpenCL C code successfully compiled.                                  |
| FP64  compute                                         9.512 TFLOPs/s (1/2 ) |
| FP32  compute                                        19.283 TFLOPs/s ( 1x ) |
| FP16  compute                                          not supported        |
| INT64 compute                                         2.664  TIOPs/s (1/8 ) |
| INT32 compute                                        19.245  TIOPs/s ( 1x ) |
| INT16 compute                                        15.397  TIOPs/s (2/3 ) |
| INT8  compute                                        18.052  TIOPs/s ( 1x ) |
| Memory Bandwidth ( coalesced read      )                       1350.39 GB/s |
| Memory Bandwidth ( coalesced      write)                       1503.39 GB/s |
| Memory Bandwidth (misaligned read      )                       1226.41 GB/s |
| Memory Bandwidth (misaligned      write)                        210.83 GB/s |
| PCIe   Bandwidth (send                 )                         22.06 GB/s |
| PCIe   Bandwidth (   receive           )                         21.16 GB/s |
| PCIe   Bandwidth (        bidirectional)            (Gen4 x16)    8.77 GB/s |
|-----------------------------------------------------------------------------|
|----------------.------------------------------------------------------------|
| Device ID      | 1                                                          |
| Device Name    | NVIDIA GeForce RTX 2080 Ti                                 |
| Device Vendor  | NVIDIA Corporation                                         |
| Device Driver  | 525.89.02                                                  |
| OpenCL Version | OpenCL C 1.2                                               |
| Compute Units  | 68 at 1545 MHz (4352 cores, 13.448 TFLOPs/s)               |
| Memory, Cache  | 11011 MB, 2176 KB global / 48 KB local                     |
| Buffer Limits  | 2752 MB global, 64 KB constant                             |
|----------------'------------------------------------------------------------|
| Info: OpenCL C code successfully compiled.                                  |
| FP64  compute                                         0.507 TFLOPs/s (1/24) |
| FP32  compute                                        16.450 TFLOPs/s ( 1x ) |
| FP16  compute                                          not supported        |
| INT64 compute                                         3.524  TIOPs/s (1/4 ) |
| INT32 compute                                        16.265  TIOPs/s ( 1x ) |
| INT16 compute                                        12.897  TIOPs/s ( 1x ) |
| INT8  compute                                        10.158  TIOPs/s (2/3 ) |
| Memory Bandwidth ( coalesced read      )                        533.08 GB/s |
| Memory Bandwidth ( coalesced      write)                        550.67 GB/s |
| Memory Bandwidth (misaligned read      )                        533.38 GB/s |
| Memory Bandwidth (misaligned      write)                        156.57 GB/s |
| PCIe   Bandwidth (send                 )                         12.87 GB/s |
| PCIe   Bandwidth (   receive           )                         12.86 GB/s |
| PCIe   Bandwidth (        bidirectional)            (Gen4 x16)    6.35 GB/s |
|-----------------------------------------------------------------------------|
|-----------------------------------------------------------------------------|
| Done. Press Enter to exit.                                                  |
'-----------------------------------------------------------------------------'
```
```
.-----------------------------------------------------------------------------.
|----------------.------------------------------------------------------------|
| Device ID    0 | gfx906:sramecc+:xnack-                                     |
| Device ID    1 | gfx906:sramecc+:xnack-                                     |
| Device ID    2 | gfx906:sramecc+:xnack-                                     |
| Device ID    3 | gfx906:sramecc+:xnack-                                     |
| Device ID    4 | gfx906:sramecc+:xnack-                                     |
| Device ID    5 | gfx906:sramecc+:xnack-                                     |
| Device ID    6 | gfx906:sramecc+:xnack-                                     |
| Device ID    7 | gfx906:sramecc+:xnack-                                     |
|----------------'------------------------------------------------------------|
|----------------.------------------------------------------------------------|
| Device ID      | 0                                                          |
| Device Name    | gfx906:sramecc+:xnack-                                     |
| Device Vendor  | Advanced Micro Devices, Inc.                               |
| Device Driver  | 3513.0 (HSA1.1,LC)                                         |
| OpenCL Version | OpenCL C 2.0                                               |
| Compute Units  | 60 at 1801 MHz (3840 cores, 13.832 TFLOPs/s)               |
| Memory, Cache  | 16368 MB, 16 KB global / 64 KB local                       |
| Buffer Limits  | 13912 MB global, 14246707 KB constant                      |
|----------------'------------------------------------------------------------|
| Info: OpenCL C code successfully compiled.                                  |
| FP64  compute                                         3.130 TFLOPs/s (1/4 ) |
| FP32  compute                                        12.440 TFLOPs/s ( 1x ) |
| FP16  compute                                        24.593 TFLOPs/s ( 2x ) |
| INT64 compute                                         0.809  TIOPs/s (1/16) |
| INT32 compute                                         6.273  TIOPs/s (1/2 ) |
| INT16 compute                                        12.488  TIOPs/s ( 1x ) |
| INT8  compute                                         8.314  TIOPs/s (2/3 ) |
| Memory Bandwidth ( coalesced read      )                        693.40 GB/s |
| Memory Bandwidth ( coalesced      write)                        654.52 GB/s |
| Memory Bandwidth (misaligned read      )                        805.20 GB/s |
| Memory Bandwidth (misaligned      write)                        400.12 GB/s |
| PCIe   Bandwidth (send                 )                         10.36 GB/s |
| PCIe   Bandwidth (   receive           )                         10.28 GB/s |
| PCIe   Bandwidth (        bidirectional)            (Gen4 x16)   10.32 GB/s |
|-----------------------------------------------------------------------------|
|-----------------------------------------------------------------------------|
| Done. Press Enter to exit.                                                  |
'-----------------------------------------------------------------------------'
```
```
.-----------------------------------------------------------------------------.
|----------------.------------------------------------------------------------|
| Device ID    0 | NVIDIA TITAN Xp                                            |
| Device ID    1 | Tesla K40m                                                 |
| Device ID    2 | Tesla K40m                                                 |
| Device ID    3 | Tesla K40m                                                 |
|----------------'------------------------------------------------------------|
|----------------.------------------------------------------------------------|
| Device ID      | 1                                                          |
| Device Name    | Tesla K40m                                                 |
| Device Vendor  | NVIDIA Corporation                                         |
| Device Driver  | 470.103.01                                                 |
| OpenCL Version | OpenCL C 1.2                                               |
| Compute Units  | 15 at 745 MHz (2880 cores, 4.291 TFLOPs/s)                 |
| Memory, Cache  | 11441 MB, 240 KB global / 48 KB local                      |
| Buffer Limits  | 2860 MB global, 64 KB constant                             |
|----------------'------------------------------------------------------------|
| Info: OpenCL C code successfully compiled.                                  |
| FP64  compute                                         1.213 TFLOPs/s (1/4 ) |
| FP32  compute                                         2.437 TFLOPs/s (1/2 ) |
| FP16  compute                                          not supported        |
| INT64 compute                                         0.618  TIOPs/s (1/8 ) |
| INT32 compute                                         0.714  TIOPs/s (1/8 ) |
| INT16 compute                                         0.689  TIOPs/s (1/8 ) |
| INT8  compute                                         0.679  TIOPs/s (1/8 ) |
| Memory Bandwidth ( coalesced read      )                        175.44 GB/s |
| Memory Bandwidth ( coalesced      write)                        191.03 GB/s |
| Memory Bandwidth (misaligned read      )                         41.45 GB/s |
| Memory Bandwidth (misaligned      write)                         37.91 GB/s |
| PCIe   Bandwidth (send                 )                          7.67 GB/s |
| PCIe   Bandwidth (   receive           )                          4.35 GB/s |
| PCIe   Bandwidth (        bidirectional)            (Gen3 x16)    5.79 GB/s |
|-----------------------------------------------------------------------------|
|-----------------------------------------------------------------------------|
| Done. Press Enter to exit.                                                  |
'-----------------------------------------------------------------------------'
```
```
.-----------------------------------------------------------------------------.
|----------------.------------------------------------------------------------|
| Device ID    0 | NVIDIA TITAN Xp                                            |
| Device ID    1 | Intel(R) UHD Graphics 630                                  |
| Device ID    2 | Intel(R) Core(TM) i7-8700K CPU @ 3.70GHz                   |
|----------------'------------------------------------------------------------|
|----------------.------------------------------------------------------------|
| Device ID      | 0                                                          |
| Device Name    | NVIDIA TITAN Xp                                            |
| Device Vendor  | NVIDIA Corporation                                         |
| Device Driver  | 531.18                                                     |
| OpenCL Version | OpenCL C 1.2                                               |
| Compute Units  | 30 at 1582 MHz (3840 cores, 12.150 TFLOPs/s)               |
| Memory, Cache  | 12287 MB, 1440 KB global / 48 KB local                     |
| Buffer Limits  | 3071 MB global, 64 KB constant                             |
|----------------'------------------------------------------------------------|
| Info: OpenCL C code successfully compiled.                                  |
| FP64  compute                                         0.441 TFLOPs/s (1/32) |
| FP32  compute                                        12.880 TFLOPs/s ( 1x ) |
| FP16  compute                                          not supported        |
| INT64 compute                                         1.436  TIOPs/s (1/8 ) |
| INT32 compute                                         4.001  TIOPs/s (1/3 ) |
| INT16 compute                                        12.733  TIOPs/s ( 1x ) |
| INT8  compute                                        13.148  TIOPs/s ( 1x ) |
| Memory Bandwidth ( coalesced read      )                        415.77 GB/s |
| Memory Bandwidth ( coalesced      write)                        475.51 GB/s |
| Memory Bandwidth (misaligned read      )                        168.69 GB/s |
| Memory Bandwidth (misaligned      write)                        104.66 GB/s |
| PCIe   Bandwidth (send                 )                         11.40 GB/s |
| PCIe   Bandwidth (   receive           )                         11.06 GB/s |
| PCIe   Bandwidth (        bidirectional)            (Gen4 x16)   11.22 GB/s |
|-----------------------------------------------------------------------------|
|----------------.------------------------------------------------------------|
| Device ID      | 1                                                          |
| Device Name    | Intel(R) UHD Graphics 630                                  |
| Device Vendor  | Intel(R) Corporation                                       |
| Device Driver  | 31.0.101.2114                                              |
| OpenCL Version | OpenCL C 1.2                                               |
| Compute Units  | 24 at 1200 MHz (192 cores, 0.461 TFLOPs/s)                 |
| Memory, Cache  | 6500 MB, 768 KB global / 64 KB local                       |
| Buffer Limits  | 3250 MB global, 3328048 KB constant                        |
|----------------'------------------------------------------------------------|
| Info: OpenCL C code successfully compiled.                                  |
| FP64  compute                                         0.112 TFLOPs/s (1/4 ) |
| FP32  compute                                         0.454 TFLOPs/s ( 1x ) |
| FP16  compute                                         0.781 TFLOPs/s ( 2x ) |
| INT64 compute                                         0.016  TIOPs/s (1/32) |
| INT32 compute                                         0.153  TIOPs/s (1/3 ) |
| INT16 compute                                         0.863  TIOPs/s ( 2x ) |
| INT8  compute                                         0.151  TIOPs/s (1/3 ) |
| Memory Bandwidth ( coalesced read      )                         20.14 GB/s |
| Memory Bandwidth ( coalesced      write)                         22.94 GB/s |
| Memory Bandwidth (misaligned read      )                         34.83 GB/s |
| Memory Bandwidth (misaligned      write)                         12.64 GB/s |
| PCIe   Bandwidth (send                 )                         14.46 GB/s |
| PCIe   Bandwidth (   receive           )                         14.48 GB/s |
| PCIe   Bandwidth (        bidirectional)            (Gen4 x16)    9.38 GB/s |
|-----------------------------------------------------------------------------|
|----------------.------------------------------------------------------------|
| Device ID      | 2                                                          |
| Device Name    | Intel(R) Core(TM) i7-8700K CPU @ 3.70GHz                   |
| Device Vendor  | Intel(R) Corporation                                       |
| Device Driver  | 2022.14.11.0.01_160000.xmain-hotfix                        |
| OpenCL Version | OpenCL C 3.0                                               |
| Compute Units  | 12 at 3700 MHz (6 cores, 0.710 TFLOPs/s)                   |
| Memory, Cache  | 16250 MB, 256 KB global / 32 KB local                      |
| Buffer Limits  | 8125 MB global, 128 KB constant                            |
|----------------'------------------------------------------------------------|
| Info: OpenCL C code successfully compiled.                                  |
| FP64  compute                                         0.179 TFLOPs/s (1/4 ) |
| FP32  compute                                         0.176 TFLOPs/s (1/4 ) |
| FP16  compute                                          not supported        |
| INT64 compute                                         0.053  TIOPs/s (1/12) |
| INT32 compute                                         0.061  TIOPs/s (1/12) |
| INT16 compute                                         0.222  TIOPs/s (1/3 ) |
| INT8  compute                                         0.242  TIOPs/s (1/3 ) |
| Memory Bandwidth ( coalesced read      )                         22.74 GB/s |
| Memory Bandwidth ( coalesced      write)                         11.16 GB/s |
| Memory Bandwidth (misaligned read      )                         41.23 GB/s |
| Memory Bandwidth (misaligned      write)                         14.21 GB/s |
| PCIe   Bandwidth (send                 )                         15.45 GB/s |
| PCIe   Bandwidth (   receive           )                         14.96 GB/s |
| PCIe   Bandwidth (        bidirectional)            (Gen4 x16)   15.02 GB/s |
|-----------------------------------------------------------------------------|
|-----------------------------------------------------------------------------|
| Done. Press Enter to exit.                                                  |
'-----------------------------------------------------------------------------'
```
```
.-----------------------------------------------------------------------------.
|----------------.------------------------------------------------------------|
| Device ID    0 | Intel(R) Arc(TM) A750 Graphics                             |
|----------------'------------------------------------------------------------|
|----------------.------------------------------------------------------------|
| Device ID      | 0                                                          |
| Device Name    | Intel(R) Arc(TM) A750 Graphics                             |
| Device Vendor  | Intel(R) Corporation                                       |
| Device Driver  | 23.05.25593.18                                             |
| OpenCL Version | OpenCL C 1.2                                               |
| Compute Units  | 448 at 2400 MHz (3584 cores, 17.203 TFLOPs/s)              |
| Memory, Cache  | 8127 MB, 512 KB global / 64 KB local                       |
| Buffer Limits  | 3860 MB global, 3953458 KB constant                        |
|----------------'------------------------------------------------------------|
| Info: OpenCL C code successfully compiled.                                  |
| FP64  compute                                          not supported        |
| FP32  compute                                        10.254 TFLOPs/s (2/3 ) |
| FP16  compute                                        15.629 TFLOPs/s ( 1x ) |
| INT64 compute                                         1.032  TIOPs/s (1/16) |
| INT32 compute                                         3.896  TIOPs/s (1/4 ) |
| INT16 compute                                        25.614  TIOPs/s ( 1x ) |
| INT8  compute                                         9.434  TIOPs/s (1/2 ) |
| Memory Bandwidth ( coalesced read      )                        198.56 GB/s |
| Memory Bandwidth ( coalesced      write)                        407.12 GB/s |
| Memory Bandwidth (misaligned read      )                        384.15 GB/s |
| Memory Bandwidth (misaligned      write)                        285.33 GB/s |
| PCIe   Bandwidth (send                 )                          1.33 GB/s |
| PCIe   Bandwidth (   receive           )                          1.28 GB/s |
| PCIe   Bandwidth (        bidirectional)            (Gen1 x16)    1.34 GB/s |
|-----------------------------------------------------------------------------|
|-----------------------------------------------------------------------------|
| Done. Press Enter to exit.                                                  |
'-----------------------------------------------------------------------------'
```