compile: addTwoVectors_sequential.c addTwoVectors_pthreads.c
	gcc -o addTwoVectors_sequential addTwoVectors_sequential.c -lm -O3
	gcc -o addTwoVectors_pthreads addTwoVectors_pthreads.c -lm -O3 -lpthread

clean:
	rm addTwoVectors_sequential
	rm addTwoVectors_pthreads