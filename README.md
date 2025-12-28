# OpenCL-Benchmark

A small [OpenCL](https://github.com/ProjectPhysX/OpenCL-Wrapper "OpenCL-Wrapper") benchmark program to measure peak GPU/CPU performance.

Works with any GPU in Windows, Linux, macOS and Android.



## Measurements
- compute performance (`FP64` (scalar), `FP32` (scalar), `FP16` (half2), `INT64` (scalar), `INT32` (scalar), `INT16` (short2), `INT8` (dp4a))
  - closest possible fraction/multiplicator of `measured compute performance` divided by `reported theoretical FP32 performance` is shown in `(round brackets)`
    - for example when OpenCL reports `19.492` TFLOPs/s theoretical FP32, and the benchmark measures `9.512` TFLOPs/s for FP64, the ratio of `(measured FP64)/(theoretical FP32) = 9.512/19.492 = 1/2.05` is rounded to the next possible value of `1/2` and reported as such
    - these ratios for any GPU/CPU architecture can only be either `1/64`, `1/32`, `1/24`, `1/16`, `1/12`, `1/8`, `1/4`, `1/3`, `1/2`, `2/3`, `1x`, `2x`, `4x`, `8x`, `16x`, `32x`, `64x`, and nothing in between
- memory bandwidth (`coalesced`/`misaligned` `read`/`write`)
- PCIe bandwidth (`send`/`receive`/`bidirectional`)
  - PCIe Gen is estimated based on measured PCIe bandwidth and assumed x16 link width



## How to use?

### Windows
- Download and install [Visual Studio Community](https://visualstudio.microsoft.com/de/vs/community/). In Visual Studio Installer, add:
  - Desktop development with C++
  - MSVC v142
  - Windows 10 SDK
- Open [`OpenCL-Benchmark.sln`](OpenCL-Benchmark.sln) in [Visual Studio Community](https://visualstudio.microsoft.com/de/vs/community/).
- Compile and run by clicking the <kbd>► Local Windows Debugger</kbd> button.
- To run outside of [Visual Studio Community](https://visualstudio.microsoft.com/de/vs/community/), open Windows CMD in the `OpenCL-Benchmark` folder (type `cmd` in File Explorer in the directory field and press <kbd>Enter</kbd>), then run
  ```
  OpenCL-Benchmark.exe
  ```

### Linux / macOS / Android
- Download, compile and run:
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

### Run only for a specified list of devices
- call `bin\OpenCL-Benchmark.exe 0 2 5` (Windows) or `bin/OpenCL-Benchmark 0 2 5` (Linux/macOS) with the number(s) being the device IDs to be benchmarked



## Examples
```
|----------------.------------------------------------------------------------|
| Device ID      | 0                                                          |
| Device Name    | NVIDIA B200                                                |
| Device Vendor  | NVIDIA Corporation                                         |
| Device Driver  | 570.133.20 (Linux)                                         |
| OpenCL Version | OpenCL C 3.0                                               |
| Compute Units  | 148 at 1965 MHz (18944 cores, 74.450 TFLOPs/s)             |
| Memory, Cache  | 182642 MB VRAM, 4736 KB global / 48 KB local               |
| Buffer Limits  | 45660 MB global, 64 KB constant                            |
|----------------'------------------------------------------------------------|
| Info: OpenCL C code successfully compiled.                                  |
| FP64  compute                                        34.292 TFLOPs/s (1/2 ) |
| FP32  compute                                        69.464 TFLOPs/s ( 1x ) |
| FP16  compute                                        72.909 TFLOPs/s ( 1x ) |
| INT64 compute                                         3.704  TIOPs/s (1/24) |
| INT32 compute                                        36.508  TIOPs/s (1/2 ) |
| INT16 compute                                        33.597  TIOPs/s (1/2 ) |
| INT8  compute                                       117.962  TIOPs/s ( 2x ) |
| Memory Bandwidth ( coalesced read      )                       6668.71 GB/s |
| Memory Bandwidth ( coalesced      write)                       6502.72 GB/s |
| Memory Bandwidth (misaligned read      )                       2280.05 GB/s |
| Memory Bandwidth (misaligned      write)                        937.78 GB/s |
| PCIe   Bandwidth (send                 )                         14.08 GB/s |
| PCIe   Bandwidth (   receive           )                         13.82 GB/s |
| PCIe   Bandwidth (        bidirectional)            (Gen4 x16)   11.39 GB/s |
|-----------------------------------------------------------------------------|
```
```
|----------------.------------------------------------------------------------|
| Device ID      | 0                                                          |
| Device Name    | Intel(R) Data Center GPU Max 1100                          |
| Device Vendor  | Intel(R) Corporation                                       |
| Device Driver  | 23.43.27642.67 (Linux)                                     |
| OpenCL Version | OpenCL C 3.0                                               |
| Compute Units  | 448 at 1550 MHz (7168 cores, 22.221 TFLOPs/s)              |
| Memory, Cache  | 49135 MB VRAM, 196608 KB global / 128 KB local             |
| Buffer Limits  | 46679 MB global, 47799500 KB constant                      |
|----------------'------------------------------------------------------------|
| Info: OpenCL C code successfully compiled.                                  |
| FP64  compute                                        15.929 TFLOPs/s (2/3 ) |
| FP32  compute                                        21.934 TFLOPs/s ( 1x ) |
| FP16  compute                                        41.497 TFLOPs/s ( 2x ) |
| INT64 compute                                         1.083  TIOPs/s (1/24) |
| INT32 compute                                         7.043  TIOPs/s (1/3 ) |
| INT16 compute                                        60.469  TIOPs/s ( 2x ) |
| INT8  compute                                        41.642  TIOPs/s ( 2x ) |
| Memory Bandwidth ( coalesced read      )                        737.51 GB/s |
| Memory Bandwidth ( coalesced      write)                        907.84 GB/s |
| Memory Bandwidth (misaligned read      )                        716.65 GB/s |
| Memory Bandwidth (misaligned      write)                        329.80 GB/s |
| PCIe   Bandwidth (send                 )                         45.92 GB/s |
| PCIe   Bandwidth (   receive           )                         35.89 GB/s |
| PCIe   Bandwidth (        bidirectional)            (Gen4 x16)   40.21 GB/s |
|-----------------------------------------------------------------------------|
```
```
|----------------.------------------------------------------------------------|
| Device ID      | 0                                                          |
| Device Name    | AMD Instinct MI355X                                        |
| Device Vendor  | Advanced Micro Devices, Inc.                               |
| Device Driver  | 3662.0 (HSA1.1,LC) (Linux)                                 |
| OpenCL Version | OpenCL C 2.0                                               |
| Compute Units  | 256 at 2400 MHz (16384 cores, 78.643 TFLOPs/s)             |
| Memory, Cache  | 294896 MB VRAM, 32 KB global / 160 KB local                |
| Buffer Limits  | 294896 MB global, 301973504 KB constant                    |
|----------------'------------------------------------------------------------|
| Info: OpenCL C code successfully compiled.                                  |
| FP64  compute                                        62.858 TFLOPs/s (2/3 ) |
| FP32  compute                                       138.172 TFLOPs/s ( 2x ) |
| FP16  compute                                       143.453 TFLOPs/s ( 2x ) |
| INT64 compute                                         7.078  TIOPs/s (1/12) |
| INT32 compute                                        38.309  TIOPs/s (1/2 ) |
| INT16 compute                                        89.761  TIOPs/s ( 1x ) |
| INT8  compute                                       129.780  TIOPs/s ( 2x ) |
| Memory Bandwidth ( coalesced read      )                       4903.01 GB/s |
| Memory Bandwidth ( coalesced      write)                       5438.98 GB/s |
| Memory Bandwidth (misaligned read      )                       5473.35 GB/s |
| Memory Bandwidth (misaligned      write)                       3449.07 GB/s |
| PCIe   Bandwidth (send                 )                         55.16 GB/s |
| PCIe   Bandwidth (   receive           )                         54.76 GB/s |
| PCIe   Bandwidth (        bidirectional)            (Gen4 x16)   55.00 GB/s |
|-----------------------------------------------------------------------------|
```
```
|----------------.------------------------------------------------------------|
| Device ID      | 2                                                          |
| Device Name    | NVIDIA TITAN Xp                                            |
| Device Vendor  | NVIDIA Corporation                                         |
| Device Driver  | 570.133.07 (Linux)                                         |
| OpenCL Version | OpenCL C 3.0                                               |
| Compute Units  | 30 at 1582 MHz (3840 cores, 12.150 TFLOPs/s)               |
| Memory, Cache  | 12183 MB VRAM, 1440 KB global / 48 KB local                |
| Buffer Limits  | 3045 MB global, 64 KB constant                             |
|----------------'------------------------------------------------------------|
| Info: OpenCL C code successfully compiled.                                  |
| FP64  compute                                         0.440 TFLOPs/s (1/32) |
| FP32  compute                                        13.041 TFLOPs/s ( 1x ) |
| FP16  compute                                         0.218 TFLOPs/s (1/64) |
| INT64 compute                                         1.437  TIOPs/s (1/8 ) |
| INT32 compute                                         4.103  TIOPs/s (1/3 ) |
| INT16 compute                                        10.115  TIOPs/s (2/3 ) |
| INT8  compute                                        35.237  TIOPs/s ( 2x ) |
| Memory Bandwidth ( coalesced read      )                        459.19 GB/s |
| Memory Bandwidth ( coalesced      write)                        510.59 GB/s |
| Memory Bandwidth (misaligned read      )                        144.76 GB/s |
| Memory Bandwidth (misaligned      write)                         94.71 GB/s |
| PCIe   Bandwidth (send                 )                          6.20 GB/s |
| PCIe   Bandwidth (   receive           )                          6.71 GB/s |
| PCIe   Bandwidth (        bidirectional)            (Gen3 x16)    6.37 GB/s |
|-----------------------------------------------------------------------------|
```
```
|----------------.------------------------------------------------------------|
| Device ID      | 0                                                          |
| Device Name    | Intel(R) Arc(TM) B580 Graphics                             |
| Device Vendor  | Intel(R) Corporation                                       |
| Device Driver  | 25.18.33578.6 (Linux)                                      |
| OpenCL Version | OpenCL C 3.0                                               |
| Compute Units  | 160 at 2850 MHz (2560 cores, 14.592 TFLOPs/s)              |
| Memory, Cache  | 12215 MB VRAM, 18432 KB global / 128 KB local              |
| Buffer Limits  | 11605 MB global, 11883724 KB constant                      |
|----------------'------------------------------------------------------------|
| Info: OpenCL C code successfully compiled.                                  |
| FP64  compute                                         0.898 TFLOPs/s (1/16) |
| FP32  compute                                        14.426 TFLOPs/s ( 1x ) |
| FP16  compute                                        26.872 TFLOPs/s ( 2x ) |
| INT64 compute                                         0.694  TIOPs/s (1/24) |
| INT32 compute                                         4.618  TIOPs/s (1/3 ) |
| INT16 compute                                        39.104  TIOPs/s ( 2x ) |
| INT8  compute                                        48.792  TIOPs/s ( 4x ) |
| Memory Bandwidth ( coalesced read      )                        586.30 GB/s |
| Memory Bandwidth ( coalesced      write)                        473.85 GB/s |
| Memory Bandwidth (misaligned read      )                        894.58 GB/s |
| Memory Bandwidth (misaligned      write)                        398.67 GB/s |
| PCIe   Bandwidth (send                 )                          6.86 GB/s |
| PCIe   Bandwidth (   receive           )                          7.00 GB/s |
| PCIe   Bandwidth (        bidirectional)            (Gen3 x16)    6.92 GB/s |
|-----------------------------------------------------------------------------|
```
```
|----------------.------------------------------------------------------------|
| Device ID      | 4                                                          |
| Device Name    | AMD Radeon RX 7700 XT                                      |
| Device Vendor  | Advanced Micro Devices, Inc.                               |
| Device Driver  | 3649.0 (HSA1.1,LC) (Linux)                                 |
| OpenCL Version | OpenCL C 2.0                                               |
| Compute Units  | 54 at 2226 MHz (3456 cores, 30.772 TFLOPs/s)               |
| Memory, Cache  | 12272 MB VRAM, 32 KB global / 64 KB local                  |
| Buffer Limits  | 12272 MB global, 12566528 KB constant                      |
|----------------'------------------------------------------------------------|
| Info: OpenCL C code successfully compiled.                                  |
| FP64  compute                                         0.570 TFLOPs/s (1/64) |
| FP32  compute                                        17.685 TFLOPs/s (1/2 ) |
| FP16  compute                                        33.203 TFLOPs/s ( 1x ) |
| INT64 compute                                         2.738  TIOPs/s (1/12) |
| INT32 compute                                         3.661  TIOPs/s (1/8 ) |
| INT16 compute                                        16.656  TIOPs/s (1/2 ) |
| INT8  compute                                        33.060  TIOPs/s ( 1x ) |
| Memory Bandwidth ( coalesced read      )                        380.32 GB/s |
| Memory Bandwidth ( coalesced      write)                        270.47 GB/s |
| Memory Bandwidth (misaligned read      )                        414.11 GB/s |
| Memory Bandwidth (misaligned      write)                        424.22 GB/s |
| PCIe   Bandwidth (send                 )                         13.24 GB/s |
| PCIe   Bandwidth (   receive           )                         14.22 GB/s |
| PCIe   Bandwidth (        bidirectional)            (Gen4 x16)   13.69 GB/s |
|-----------------------------------------------------------------------------|
```
```
|----------------.------------------------------------------------------------|
| Device ID      | 1                                                          |
| Device Name    | pthread-0xd4f (Nvidia GH200 Neoverse-V2 CPU)               |
| Device Vendor  | ARM                                                        |
| Device Driver  | 1.8 (Linux)                                                |
| OpenCL Version | OpenCL C 1.2 pocl                                          |
| Compute Units  | 72 at 3420 MHz (72 cores, 7.880 TFLOPs/s)                  |
| Memory, Cache  | 488252 MB, 116736 KB global / 1024 KB local                |
| Buffer Limits  | 131072 MB global, 1024 KB constant                         |
|----------------'------------------------------------------------------------|
| Info: OpenCL C code successfully compiled.                                  |
| FP64  compute                                         0.145 TFLOPs/s (1/64) |
| FP32  compute                                         0.125 TFLOPs/s (1/64) |
| FP16  compute                                          not supported        |
| INT64 compute                                         0.370  TIOPs/s (1/24) |
| INT32 compute                                         0.241  TIOPs/s (1/32) |
| INT16 compute                                         0.261  TIOPs/s (1/32) |
| INT8  compute                                         0.567  TIOPs/s (1/16) |
| Memory Bandwidth ( coalesced read      )                        183.49 GB/s |
| Memory Bandwidth ( coalesced      write)                        139.94 GB/s |
| Memory Bandwidth (misaligned read      )                        401.96 GB/s |
| Memory Bandwidth (misaligned      write)                        359.65 GB/s |
|-----------------------------------------------------------------------------|
```
```
|----------------.------------------------------------------------------------|
| Device ID      | 0                                                          |
| Device Name    | Intel(R) Xeon(R) 6960P                                     |
| Device Vendor  | Intel(R) Corporation                                       |
| Device Driver  | 2025.19.3.0.17_230222 (Linux)                              |
| OpenCL Version | OpenCL C 3.0                                               |
| Compute Units  | 288 at 0 MHz (144 cores, 0.000 TFLOPs/s)                   |
| Memory, Cache  | 2321914 MB RAM, 2048 KB global / 256 KB local              |
| Buffer Limits  | 2321914 MB global, 128 KB constant                         |
|----------------'------------------------------------------------------------|
| Info: OpenCL C code successfully compiled.                                  |
| FP64  compute                                         7.507 TFLOPs/s (1/64) |
| FP32  compute                                         8.266 TFLOPs/s (1/64) |
| FP16  compute                                        12.076 TFLOPs/s (1/64) |
| INT64 compute                                         1.549  TIOPs/s (1/64) |
| INT32 compute                                         2.770  TIOPs/s (1/64) |
| INT16 compute                                         9.812  TIOPs/s (1/64) |
| INT8  compute                                         0.407  TIOPs/s (1/64) |
| Memory Bandwidth ( coalesced read      )                        167.72 GB/s |
| Memory Bandwidth ( coalesced      write)                         80.52 GB/s |
| Memory Bandwidth (misaligned read      )                        193.66 GB/s |
| Memory Bandwidth (misaligned      write)                        105.85 GB/s |
|-----------------------------------------------------------------------------|
```
```
|----------------.------------------------------------------------------------|
| Device ID      | 8                                                          |
| Device Name    | AMD EPYC 9654 96-Core Processor                            |
| Device Vendor  | Intel(R) Corporation                                       |
| Device Driver  | 2025.19.3.0.17_230222 (Linux)                              |
| OpenCL Version | OpenCL C 3.0                                               |
| Compute Units  | 176 at 0 MHz (88 cores, 0.000 TFLOPs/s)                    |
| Memory, Cache  | 1461020 MB RAM, 512 KB global / 256 KB local               |
| Buffer Limits  | 1461020 MB global, 128 KB constant                         |
|----------------'------------------------------------------------------------|
| Info: OpenCL C code successfully compiled.                                  |
| FP64  compute                                         4.888 TFLOPs/s (1/64) |
| FP32  compute                                         5.153 TFLOPs/s (1/64) |
| FP16  compute                                         1.139 TFLOPs/s (1/64) |
| INT64 compute                                         1.494  TIOPs/s (1/64) |
| INT32 compute                                         5.611  TIOPs/s (1/64) |
| INT16 compute                                        11.153  TIOPs/s (1/64) |
| INT8  compute                                         0.330  TIOPs/s (1/64) |
| Memory Bandwidth ( coalesced read      )                        275.74 GB/s |
| Memory Bandwidth ( coalesced      write)                        246.76 GB/s |
| Memory Bandwidth (misaligned read      )                        240.12 GB/s |
| Memory Bandwidth (misaligned      write)                         81.64 GB/s |
|-----------------------------------------------------------------------------|
```