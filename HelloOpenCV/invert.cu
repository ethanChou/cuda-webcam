#include "invert.h"

#define BLOCK_SIZE (32)

#define ENABLE_TIMING_CODE 0

__global__
void gpuInvert(
	float* image,
	int width,
	int height
	)
{
	int i = blockIdx.x * BLOCK_SIZE + threadIdx.x;
	int k = blockIdx.y * BLOCK_SIZE + threadIdx.y;

	int cIdx = (i*width + k) * 3;

	*( image + cIdx ) = 1 - *( image + cIdx );
	*( image + cIdx + 1 ) = 1 - *( image + cIdx + 1 );
	*( image + cIdx + 2 ) = 1 - *( image + cIdx + 2 );
}

void deviceInvertLaunch(
	float *d_Image,
	int width,
	int height
	)
{
	 // launch kernel
	dim3 dimBlock( BLOCK_SIZE, BLOCK_SIZE );
    dim3 dimGrid( height / dimBlock.x, width / dimBlock.y );

#if ENABLE_TIMING_CODE

	cudaEvent_t start, stop;
	cudaEventCreate(&start);
	cudaEventCreate(&stop);
	cudaEventRecord(start, 0);

#endif

    gpuInvert<<< dimGrid, dimBlock >>>( d_Image, width, height);

#if ENABLE_TIMING_CODE
	cudaEventRecord(stop, 0);
	cudaEventSynchronize(stop);
	float elapsedTime;
	cudaEventElapsedTime(&elapsedTime, start, stop);

    // block until the device has completed
    cudaThreadSynchronize();
	
	printf("gpuInvert kernel time: %.3f ms\n", elapsedTime);
#endif

	cudaThreadSynchronize();

    // check if kernel execution generated an error
    // Check for any CUDA errors
    checkCUDAError("kernel invocation");
}
