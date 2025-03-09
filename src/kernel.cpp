#include "kernel.hpp" // note: unbalanced round brackets () are not allowed and string literals can't be arbitrarily long, so periodically interrupt with )+R(
string opencl_c_container() { return R( // ########################## begin of OpenCL C code ####################################################################



int dp4a(const char4 a, const char4 b, const int c) { // 4-wide byte dot product and accumulate
)+"#if cl_nv_compute_capability>=61"+R( // use hardware-supported dp4a on Nvidia Pascal or newer GPUs with inline PTX assembly
	int d;)+"asm(\"dp4a.s32.s32\t%0,%1,%2,%3;\":\"=r\"(d):\"r\"(as_int(a)),\"r\"(as_int(b)),\"r\"(c));"+R(return d;
)+"#elif defined(__opencl_c_integer_dot_product_input_4x8bit)"+R( // use hardware-supported dp4a on some Intel GPUs
	return c+dot(a, b); // dot_acc_sat(a, b, c); is slow
)+"#elif __has_builtin(__builtin_amdgcn_sdot4)"+R( // use hardware-supported dp4a on some AMD GPUs
    return __builtin_amdgcn_sdot4(as_int(a), as_int(b), c, false);
)+"#elif defined(cl_arm_integer_dot_product_accumulate_int8)"+R( // use hardware-supported dp4a on some ARM GPUs
    return arm_dot_acc(a, b, c);
)+"#else"+R( // fallback emulation (compilers will turn this into hardware-supported dp4a instruction if available)
	return c+a.x*b.x+a.y*b.y+a.z*b.z+a.w*b.w;
)+"#endif"+R(
}



)+"#ifdef cl_khr_fp64"+R( // OpenCL C defines don't work in R() stringification macro
kernel void kernel_double(global float* data) {
	double x = (double)get_global_id(0);
	double y = (double)get_local_id(0);
	for(uint i=0u; i<128u; i++) {
		x = fma(y, x, y); // 2 operations
		y = fma(x, y, x); // 2 operations
	}
	data[get_global_id(0)] = (float)y;
}
)+"#endif"+R( // cl_khr_fp64

kernel void kernel_float(global float* data) {
	float x = (float)get_global_id(0);
	float y = (float)get_local_id(0);
	for(uint i=0u; i<512u; i++) {
		x = fma(y, x, y); // 2 operations
		y = fma(x, y, x); // 2 operations
	}
	data[get_global_id(0)] = y;
}

)+"#ifdef cl_khr_fp16"+R( // OpenCL C defines don't work in R() stringification macro
kernel void kernel_half(global float* data) {
	half2 x = (half2)((float)get_global_id(0), (float)get_local_id(0));
	half2 y = (half2)((float)get_local_id(0), (float)get_global_id(0));
	for(uint i=0u; i<512u; i++) {
		x = y*x+y; // 4 operations
		y = x*y+x; // 4 operations
	}
	data[get_global_id(0)] = (float)y.x+(float)y.y;
}
)+"#endif"+R( // cl_khr_fp16

kernel void kernel_long(global float* data) {
	long x = (long)get_global_id(0);
	long y = (long)get_local_id(0);
	for(uint i=0u; i<8u; i++) {
		x = y*x+y; // 2 operations
		y = x*y+x; // 2 operations
	}
	data[get_global_id(0)] = as_float((int)y);
}

kernel void kernel_int(global float* data) {
	int x = get_global_id(0);
	int y = get_local_id(0);
	for(uint i=0u; i<512u; i++) {
		x = y*x+y; // 2 operations
		y = x*y+x; // 2 operations
	}
	data[get_global_id(0)] = as_float(y);
}

kernel void kernel_short(global float* data) {
	short2 x = as_short2((uint)get_global_id(0));
	short2 y = as_short2((uint)get_local_id(0));
	for(uint i=0u; i<128u; i++) {
		x = y*x+y; // 4 operations
		y = x*y+x; // 4 operations
	}
	data[get_global_id(0)] = as_float(y);
}

kernel void kernel_char(global float* data) {
	char4 x = as_char4((uint)get_global_id(0));
	char4 y = as_char4((uint)get_local_id(0));
	for(uint i=0u; i<64u; i++) {
		x = as_char4(dp4a(y, x, as_int(y))); // 8 operations
		y = as_char4(dp4a(x, y, as_int(x))); // 8 operations
	}
	data[get_global_id(0)] = as_float(y);
}



kernel void kernel_coalesced_write(global float* data) {
	const uint n = get_global_id(0);
	for(uint i=0u; i<def_M; i++) data[i*def_N+n] = as_float(n); // coalesced write
}
kernel void kernel_coalesced_read(global float* data) {
	const uint n = get_global_id(0);
	float x = 0.0f;
	for(uint i=0u; i<def_M; i++) x += data[i*def_N+n]; // coalesced read
	data[n] = x;
}
kernel void kernel_misaligned_write(global float* data) {
	const uint n = get_global_id(0);
	for(uint i=0u; i<def_M; i++) data[n*def_M+i] = as_float(n); // misaligned write
}
kernel void kernel_misaligned_read(global float* data) {
	const uint n = get_global_id(0);
	float x = 0.0f;
	for(uint i=0u; i<def_M; i++) x += data[n*def_M+i]; // misaligned read
	data[n] = x;
}



);} // ############################################################### end of OpenCL C code #####################################################################