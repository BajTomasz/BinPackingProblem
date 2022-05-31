#!/usr/bin/env bash
./cmake-build-debug/BinPackingProblem -fname dane.csv -method hillClimbing > resultHillClimbing.txt
./cmake-build-debug/BinPackingProblem -fname dane.csv -method hillClimbingrandom > resultHillClimbingrandom.txt
./cmake-build-debug/BinPackingProblem -fname dane.csv -method tabu > resultTabu.txt
./cmake-build-debug/BinPackingProblem -fname dane.csv -method simulatedAnnealing > resultSimulatedAnnealing.txt

gnuplot -e "plot
 'resultHillClimbing.txt' u 1:3 w lines,
 'resultHillClimbingrandom.txt' u 1:3 w lines,
 'resultTabu.txt' u 1:3 w lines,
 'resultSimulatedAnnealing.txt' u 1:3 w lines" -p

rm resultHillClimbing.txt resultHillClimbingrandom.txt resultTabu.txt resultSimulatedAnnealing.txt