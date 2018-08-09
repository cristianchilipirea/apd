compile: addTwoVectors_sequential.c addTwoVectors_solved_pthreads.c
	gcc -o addTwoVectors_sequential addTwoVectors_sequential.c -lm -O3
	gcc -o addTwoVectors_solved_pthreads addTwoVectors_solved_pthreads.c -lm -O3 -lpthread

clean:
	rm addTwoVectors_sequential
	rm addTwoVectors_solved_pthreads