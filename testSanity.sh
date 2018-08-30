#!/bin/bash

seq_program=$1
par_program=$2
N=$3
NReps=$4
verbosity=1

echo "Sequential results"
./$seq_program $N $NReps $verbosity

echo "Multi-threaded results"
./$par_program $N $NReps $verbosity 4
