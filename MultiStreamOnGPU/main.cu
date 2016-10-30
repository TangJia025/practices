#include <iostream>

using namespace std;

__global__ void KernelA(int *c, int *a, int *b, int N)
{
	int tid = threadIdx.x + blockIdx.x * blockDim.x;
	while (tid < N)
	{
		c[tid] = a[tid] + b[tid];
		tid += blockDim.x * gridDim.x;
	}
	__syncthreads();
}

__global__ void KernelB(int *d, int *a, int *b, int N)
{
	int tid = threadIdx.x + blockIdx.x * blockDim.x;
	while (tid < N)
	{
		d[tid] = a[tid] * b[tid];
		tid += gridDim.x * blockDim.x;
	}
	__syncthreads();
}

int main(int argc, char **argv)
{
	int N;
	N = atoi(argv[1]);
	int *a, *b, *c, *d;
	float elapsedTime;
    cudaMallocManaged(&a, N * sizeof(int));
	cudaMallocManaged(&b, N * sizeof(int));
	cudaMallocManaged(&c, N * sizeof(int));
	cudaMallocManaged(&d, N * sizeof(int));
	for (int i = 0; i < N; i++)
	{
		a[i] = i;
		b[i] = i+1;
		c[i] = d[i] = 0;
	}
	cudaStream_t stream1, stream2;
	cudaStreamCreate(&stream1);
	cudaStreamCreate(&stream2);
    cudaEvent_t start, stop;
	cudaEventCreate(&start);
	cudaEventCreate(&stop);

	cudaEventRecord(start, 0);
	KernelA<<<3, 8, 0, stream1>>>(c, a, b, N);
	KernelB<<<3, 8, 0, stream2>>>(d, a, b, N);
	cudaStreamSynchronize(stream1);
	cudaStreamSynchronize(stream2);
    cudaEventRecord(stop);
	cudaEventSynchronize(stop);
	cudaEventElapsedTime(&elapsedTime, start, stop);
	cout << "N: " << N << ", Time taken: " << elapsedTime << "ms" << endl;

	cudaFree(a);
	cudaFree(b);
	cudaFree(c);
	cudaFree(d);
    cudaStreamDestroy(stream1);
	cudaStreamDestroy(stream2);
	cudaEventDestroy(start);
	cudaEventDestroy(stop);

	return 0;
}



