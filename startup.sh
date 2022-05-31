#!/usr/bin/env bash
./cmake-build-debug/BinPackingProblem -fname data.csv -method hillClimbing > resultHillClimbing.txt
./cmake-build-debug/BinPackingProblem -fname data.csv -method hillClimbingRandom > resultHillClimbingRandom.txt
./cmake-build-debug/BinPackingProblem -fname data.csv -method tabuSearch > resultTabu.txt
./cmake-build-debug/BinPackingProblem -fname data.csv -method simulatedAnnealing > resultSimulatedAnnealing.txt
# You can add data this way
# cat data.csv | ./cmake-build-debug/BinPackingProblem

gnuplot -e "plot
 'resultHillClimbing.txt' u 1:3 w lines,
 'resultHillClimbingRandom.txt' u 1:3 w lines,
 'resultTabu.txt' u 1:3 w lines,
 'resultSimulatedAnnealing.txt' u 1:3 w lines" -p

rm resultHillClimbing.txt resultHillClimbingRandom.txt resultTabu.txt resultSimulatedAnnealing.txt