#include "opencl.hpp" // includes "utilities.hpp"

string fraction(const float x) {
	float values[]   = { 1.0f/64.0f, 1.0f/32.0f, 1.0f/24.0f, 1.0f/16.0f, 1.0f/12.0f, 1.0f/8.0f, 1.0f/4.0f, 1.0f/3.0f, 1.0f/2.0f, 2.0f/3.0f, 1.0f, 2.0f, 4.0f, 8.0f, 16.0f, 32.0f, 64.0f };
	string strings[] = {   "1/64"  ,   "1/32"  ,   "1/24"  ,   "1/16"  ,   "1/12"  ,   "1/8 ",   "1/4 ", "1/3 ", "1/2 ", "2/3 ", " 1x ", " 2x ", " 4x ", " 8x ", " 16x", " 32x", " 64x" };
	uint i=0u, imin=0u;
	float vmin = max_float;
	for(float v : values) {
		const float vnew = sq(0.01f*x-v);
		if(vnew<=vmin) {
			vmin = vnew;
			imin = i;
		}
		i++;
	}
	return "("+strings[imin]+")";
}

void benchmark_device(const Device_Info& device_info) {
	const uint N = 4096u*4096u; // kernel range: N*M*sizeof(float) = 1GB memory allocation
	const uint M = 16u; // coalescence size
	const uint N_kernel = 256u; // iterations for kernel calls
	const uint N_memory = 16u; // iterations for PCIe memory transfers

	double time_double=max_double, time_float=max_double, time_half=max_double;
	double time_long=max_double, time_int=max_double, time_short=max_double, time_char=max_double;
	double time_cw=max_double, time_cr=max_double, time_mw=max_double, time_mr=max_double, time_send=max_double, time_receive=max_double, time_bidirectional=max_double;
	Clock clock;

	const string defines =
		"\n	#define def_N "+to_string(N)+"u"
		"\n	#define def_M "+to_string(M)+"u"
	;
	print("| Compiling ...                                                               |");
	Device device(device_info, defines+get_opencl_c_code());
	Memory<float> buffer(device, N, M);
	//print_info("Device mormory usage: "+to_string(device.info.memory_used)+" MB");

	if(device.info.is_fp64_capable) {
		print("| Benchmarking ...                                                            |");
		Kernel kernel_double(device, N, "kernel_double", buffer);
		for(uint i=0u; i<N_kernel; i++) {
			clock.start();
			kernel_double.run();
			time_double = fmin(clock.stop(), time_double);
		}
		const float flops_double = 512.0f*(float)N/(float)time_double*1E-12f;
		println("\r| FP64  compute "+alignr(45u, to_string(flops_double, 3u))+" TFLOPs/s "+fraction(100.0f*flops_double/device.info.tflops)+" |");
	} else {
		println("\r| FP64  compute                                          not supported        |");
	}

	print("| Benchmarking ...                                                            |");
	Kernel kernel_float(device, N, "kernel_float", buffer);
	for(uint i=0u; i<N_kernel; i++) {
		clock.start();
		kernel_float.run();
		time_float = fmin(clock.stop(), time_float);
	}
	const float flops_float = 2048.0f*(float)N/(float)time_float*1E-12f; //const float flops = 32.0f*2.0f*(float)sq(M)*N/(float)timef*1E-12f;
	println("\r| FP32  compute "+alignr(45u, to_string(flops_float, 3u))+" TFLOPs/s "+fraction(100.0f*flops_float/device.info.tflops)+" |");

	if(device.info.is_fp16_capable) {
		print("| Benchmarking ...                                                            |");
		Kernel kernel_half(device, N, "kernel_half", buffer);
		for(uint i=0u; i<N_kernel; i++) {
			clock.start();
			kernel_half.run();
			time_half = fmin(clock.stop(), time_half);
		}
		const float flops_half = 4096.0f*(float)N/(float)time_half*1E-12f;
		println("\r| FP16  compute "+alignr(45u, to_string(flops_half, 3u))+" TFLOPs/s "+fraction(100.0f*flops_half/device.info.tflops)+" |");
	} else {
		println("\r| FP16  compute                                          not supported        |");
	}

	print("| Benchmarking ...                                                            |");
	Kernel kernel_long(device, N, "kernel_long", buffer);
	for(uint i=0u; i<N_kernel; i++) {
		clock.start();
		kernel_long.run();
		time_long = fmin(clock.stop(), time_long);
	}
	const float flops_long = 32.0f*(float)N/(float)time_long*1E-12f;
	println("\r| INT64 compute "+alignr(45u, to_string(flops_long, 3u))+"  TIOPs/s "+fraction(100.0f*flops_long/device.info.tflops)+" |");

	print("| Benchmarking ...                                                            |");
	Kernel kernel_int(device, N, "kernel_int", buffer);
	for(uint i=0u; i<N_kernel; i++) {
		clock.start();
		kernel_int.run();
		time_int = fmin(clock.stop(), time_int);
	}
	const float flops_int = 2048.0f*(float)N/(float)time_int*1E-12f;
	println("\r| INT32 compute "+alignr(45u, to_string(flops_int, 3u))+"  TIOPs/s "+fraction(100.0f*flops_int/device.info.tflops)+" |");

	print("| Benchmarking ...                                                            |");
	Kernel kernel_short(device, N, "kernel_short", buffer);
	for(uint i=0u; i<N_kernel; i++) {
		clock.start();
		kernel_short.run();
		time_short = fmin(clock.stop(), time_short);
	}
	const float flops_short = 1024.0f*(float)N/(float)time_short*1E-12f;
	println("\r| INT16 compute "+alignr(45u, to_string(flops_short, 3u))+"  TIOPs/s "+fraction(100.0f*flops_short/device.info.tflops)+" |");

	print("| Benchmarking ...                                                            |");
	Kernel kernel_char(device, N, "kernel_char", buffer);
	for(uint i=0u; i<N_kernel; i++) {
		clock.start();
		kernel_char.run();
		time_char = fmin(clock.stop(), time_char);
	}
	const float flops_char = 1024.0f*(float)N/(float)time_char*1E-12f;
	println("\r| INT8  compute "+alignr(45u, to_string(flops_char, 3u))+"  TIOPs/s "+fraction(100.0f*flops_char/device.info.tflops)+" |");

	print("| Benchmarking ...                                                            |");
	Kernel kernel_coalesced_write(device, N, "kernel_coalesced_write" , buffer);
	for(uint i=0u; i<N_kernel; i++) {
		clock.start();
		kernel_coalesced_write.run();
		time_cw = fmin(clock.stop(), time_cw);
	}
	Kernel kernel_coalesced_read(device, N, "kernel_coalesced_read"  , buffer);
	for(uint i=0u; i<N_kernel; i++) {
		clock.start();
		kernel_coalesced_read.run();
		time_cr = fmin(clock.stop(), time_cr);
	}
	println("\r| Memory Bandwidth ( coalesced read      ) "+alignr(29u, to_string(4.0f*(float)N*(float)M/(float)(time_cr-time_cw/(double)M)*1E-9f, 2u))+" GB/s |");
	println("\r| Memory Bandwidth ( coalesced      write) "+alignr(29u, to_string(4.0f*(float)N*(float)M/(float) time_cw                   *1E-9f, 2u))+" GB/s |");

	print("| Benchmarking ...                                                            |");
	Kernel kernel_misaligned_write(device, N, "kernel_misaligned_write", buffer);
	for(uint i=0u; i<N_kernel; i++) {
		clock.start();
		kernel_misaligned_write.run();
		time_mw = fmin(clock.stop(), time_mw);
	}
	Kernel kernel_misaligned_read(device, N, "kernel_misaligned_read" , buffer);
	for(uint i=0u; i<N_kernel; i++) {
		clock.start();
		kernel_misaligned_read.run();
		time_mr = fmin(clock.stop(), time_mr);
	}
	println("\r| Memory Bandwidth (misaligned read      ) "+alignr(29u, to_string(4.0f*(float)N*(float)M/(float)(time_mr-time_cw/(double)M)*1E-9f, 2u))+" GB/s |");
	println("\r| Memory Bandwidth (misaligned      write) "+alignr(29u, to_string(4.0f*(float)N*(float)M/(float) time_mw                   *1E-9f, 2u))+" GB/s |");

	if(!device.info.uses_ram) {
		print("| Benchmarking ...                                                            |");
		for(uint i=0u; i<N_memory; i++) {
			clock.start();
			buffer.write_to_device();
			time_send = fmin(clock.stop(), time_send);
		}
		const float bw_send = 4.0f*M*N/(float)time_send*1E-9f;
		println("\r| PCIe   Bandwidth (send                 ) "+alignr(29u, to_string(bw_send, 2u))+" GB/s |");
		print("| Benchmarking ...                                                            |");
		for(uint i=0u; i<N_memory; i++) {
			clock.start();
			buffer.read_from_device();
			time_receive = fmin(clock.stop(), time_receive);
		}
		const float bw_receive = 4.0f*M*N/(float)time_receive*1E-9f;
		println("\r| PCIe   Bandwidth (   receive           ) "+alignr(29u, to_string(bw_receive, 2u))+" GB/s |");
		print("| Benchmarking ...                                                            |");
		for(uint i=0u; i<N_memory; i++) {
			clock.start();
			buffer.read_from_device(N*M/2u, N*M, false);
			buffer.write_to_device(0u, N*M/2u, false);
			buffer.finish_queue();
			time_bidirectional = fmin(clock.stop(), time_bidirectional);
		}
		const float bw_bidirectional = 4.0f*M*N/(float)time_bidirectional*1E-9f;
		const float bw_max = fmax(2.0f*fmax(bw_send, bw_receive), bw_bidirectional);
		println("\r| PCIe   Bandwidth (        bidirectional)            (Gen"+to_string(bw_max>17.6f?4:bw_max>8.8f?3:bw_max>4.4f?2:1)+" x16)"+alignr(8u, to_string(bw_bidirectional, 2u))+" GB/s |");
	}

	println("|-----------------------------------------------------------------------------|");
}

int main(int argc, char* argv[]) {
	vector<string> main_arguments = get_main_arguments(argc, argv);
	println(".-----------------------------------------------------------------------------.");
	const vector<Device_Info> devices = get_devices();
	if((int)main_arguments.size()>0) {
		for(uint i=0u; i<(uint)main_arguments.size(); i++) benchmark_device(select_device_with_id(to_int(main_arguments[i]), devices));
	} else {
		for(uint i=0u; i<(uint)devices.size(); i++) benchmark_device(devices[i]);
	}
#ifdef _WIN32
	println("|-----------------------------------------------------------------------------|");
	println("| Done. Press Enter to exit.                                                  |");
	println("'-----------------------------------------------------------------------------'");
	wait();
#else // Linux
	println("'-----------------------------------------------------------------------------'");
#endif // Linux
	return 0;
}