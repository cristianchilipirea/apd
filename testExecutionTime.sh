#!/bin/bash

seq_program=$1
par_program=$2
N=$3
NReps=$4
verbosity=0
runs="1 2 4 8"

/usr/bin/time -f"%E" -o outTime ./$seq_program $N $NReps $verbosity
echo `cat outTime` Execution time with --- sequential program

#Time test
for P in $runs; do
	echo Running time test with $P threads
	/usr/bin/time -f"%E" -o outTime$P ./$par_program $N $NReps $verbosity $P
	echo `cat outTime$P` Execution time with --- $P threads 
done

rm out*
