#!/usr/bin/env bash
./../build/BinPackingProblem -fname ../data/data.csv -method hillClimbing -printProgress 1 > resultHillClimbing.txt
./../build/BinPackingProblem -fname ../data/data.csv -method hillClimbingRandom -printProgress 1 > resultHillClimbingRandom.txt
./../build/BinPackingProblem -fname ../data/data.csv -method tabuSearch -printProgress 1 > resultTabu.txt
./../build/BinPackingProblem -fname ../data/data.csv -method simulatedAnnealing -printProgress 1 > resultSimulatedAnnealing.txt
./../build/BinPackingProblem -fname ../data/data.csv -method geneticAlgorithm -iterations 100 -printProgress 1 > resultGeneticAlgorithm.txt

gnuplot -e "plot
 'resultHillClimbing.txt' u 1:3 w lines,
 'resultHillClimbingRandom.txt' u 1:3 w lines,
 'resultTabu.txt' u 1:3 w lines,
 'resultSimulatedAnnealing.txt' u 1:3 w lines,
 'resultGeneticAlgorithm.txt' u 1:3 w lines" -p

rm resultHillClimbing.txt resultHillClimbingRandom.txt resultTabu.txt resultSimulatedAnnealing.txt resultGeneticAlgorithm.txt
