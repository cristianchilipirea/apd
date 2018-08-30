#!/bin/bash

seq_program=$1
par_program=$2
N=$3
NReps=$4
verbosity=2
runs="1 2 4 8"

echo Creating comparison
./$seq_program $N $NReps $verbosity > out

#Correctness test
for P in $runs; do
	echo Running correctness test with $P threads
	./$par_program $N $NReps $verbosity $P > out$P
	diff out out$P > /dev/null
	DiffRez=$?
#	echo $DiffRez
	if [ $DiffRez -gt 0 ]; then
		echo Output not correct when running with $P threads
		break
	else
		echo Output correct
	fi
done

rm out*
