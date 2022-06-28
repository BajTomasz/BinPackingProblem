#!/usr/bin/env bash
cd ../build
cmake ../src
make -j `nproc`

./BinPackingProblem -fname ../data/data.csv -method hillClimbing -printMode 1 -iterations 100 -endMode 1 > resultHillClimbing.txt
./BinPackingProblem -fname ../data/data.csv -method hillClimbingRandom -printMode 1 -iterations 100 -endMode 1 > resultHillClimbingRandom.txt
./BinPackingProblem -fname ../data/data.csv -method tabuSearch -printMode 1 -iterations 1 -endMode 100 > resultTabu.txt
./BinPackingProblem -fname ../data/data.csv -method simulatedAnnealing -printMode 1 -iterations 100 -endMode 1 > resultSimulatedAnnealing.txt
./BinPackingProblem -fname ../data/data.csv -method geneticAlgorithm -printMode 1 -iterations 100 -endMode 1 -populationSize 50 > resultGeneticAlgorithm.txt

gnuplot -e "plot
 'resultHillClimbing.txt' u 1:3 w lines,
 'resultHillClimbingRandom.txt' u 1:3 w lines,
 'resultTabu.txt' u 1:3 w lines,
 'resultSimulatedAnnealing.txt' u 1:3 w lines,
 'resultGeneticAlgorithm.txt' u 1:3 w lines" -p

rm resultHillClimbing.txt resultHillClimbingRandom.txt resultTabu.txt resultSimulatedAnnealing.txt resultGeneticAlgorithm.txt
