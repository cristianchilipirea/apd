#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>


int P;
int N;
int NReps;
int printLevel;
int* a;
int* b;
int* c;

#define min(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a < _b ? _a : _b; })

void getArgs(int argc, char **argv)
{
	if(argc < 5) {
		printf("Not enough paramters: ./addTwoVectors N NReps printLevel P\nprintLevel: 0=no, 1=some, 2=verbouse\nP: number of threads\n");
		exit(1);
	}
	N = atoi(argv[1]);
	NReps = atoi(argv[2]);
	printLevel = atoi(argv[3]);
	P = atoi(argv[4]);
}

void* threadFunction(void *var)
{
	int thread_id = *(int*)var;

	int start = thread_id * ceil((double)N / P);
	int end = (thread_id + 1) * ceil((double)N / P);
	int i;
	int j;
	for(j = 0; j < NReps; j++)
		for(i = start; i < min(end, N); i++)
			c[i] = a[i] + b[i];
	return NULL;
}

void init()
{
	a = malloc(sizeof(int) * N);
	b = malloc(sizeof(int) * N);
	c = malloc(sizeof(int) * N);
	if(a == NULL || b == NULL || c == NULL) {
		printf("malloc failed!");
		exit(1);
	}

	int i;
	for(i = 0; i < N; i++) {
		a[i] = i%500;
		b[i] = i%500;
	}
}

void printPartial()
{
	int i;
	for(i = 0; i < 10; i++)
		printf("%i ", c[i]);
	printf("\n");
	for(i = 20; i < N; i+=N/10)
		printf("%i ", c[i]);
	printf("\n");
	for(i = N - 10; i < N; i++)
		printf("%i ", c[i]);
	printf("\n");
}

void printAll()
{
	int i;
	for(i = 0; i < N; i++)
		printf("%i ", c[i]);
	printf("\n");
}

void print()
{
	
	if(printLevel == 0)
		return;
	if(printLevel == 1) {
		printPartial();
	} else {
		printAll();
	}
}

int main(int argc, char **argv)
{
	int i;
	pthread_t tid[P];
	getArgs(argc, argv);
	init();

	int thread_id[P];
	for(i = 0;i < P; i++)
		thread_id[i] = i;

	for(i = 0; i < P; i++) {
		pthread_create(&(tid[i]), NULL, threadFunction, &(thread_id[i]));
	}

	for(i = 0; i < P; i++) {
		pthread_join(tid[i], NULL);
	}

	print();

	return 0;
}
