#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>


int P=1;
long N = 123123123;

long* a;
long* b;
long* c;

#define min(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a < _b ? _a : _b; })

void* threadFunction(void *var)
{
	int thread_id = *(int*)var;
	printf("Here is my id %i\n", thread_id);

	long num_el;
	long start = thread_id * ceil((double)N / P);
	long end = (thread_id + 1) * ceil((double)N / P);
	long i;
	long j;
	for(j = 0; j < 10; j++)
		for(i = start; i < min(end, N); i++)
			c[i] = a[i] * b[i];
	return NULL;
}

void init()
{
	a = malloc(sizeof(long) * N);
	b = malloc(sizeof(long) * N);
	c = malloc(sizeof(long) * N);
	if(a == NULL || b == NULL || c == NULL) {
		printf("malloc failed!");
		exit(1);
	}

	long i;
	for(i = 0; i < N; i++) {
		a[i] = i%500;
		b[i] = i%500;
	}
}

void print()
{
	int i;
	for(i = 0; i < 10; i++)
		printf("%li ", c[i]);
	printf("\n");
	for(i = 20; i < N; i+=N/10)
		printf("%li ", c[i]);
	printf("\n");
	for(i = N - 10; i < N; i++)
		printf("%li ", c[i]);
	printf("\n");
}

int main(int argc, char **argv)
{
	int i;

	init();


	print();

	return 0;
}
