#!/bin/bash

make

seq_program=addTwoVectors_sequential
par_program=addTwoVectors_pthreads


N=123123123
NReps=1

../testSanity.sh $seq_program $par_program $N $NReps

N=123123
NReps=100

../testCorrectness.sh $seq_program $par_program $N $NReps

N=123123123
NReps=100

../testExecutionTime.sh $seq_program $par_program $N $NReps

make clean
