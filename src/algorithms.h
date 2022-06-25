//
// Created by tomasz on 21.04.2022.
//

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

void printSolution(std::vector<int> bestSolution);
std::vector<int> dataGenerator(int minRange, int maxRange, int quantity);
int howManyBin(std::vector<int> startSolution, int binSize, int quantity);
std::vector<int> hillClimbingRandom(std::vector<int> startSolution, int binSize, int quantity, int iterations, bool printProgress);
std::vector<int> hillClimbing(std::vector<int> startSolution, int binSize, int quantity, int iterations, bool printProgress);
std::vector<int> tabuSearch(std::vector<int> startSolution, int binSize, int quantity, int tabuSize, int iterations, bool printProgress);
std::vector<int> simulatedAnnealing(std::vector<int> startSolution, int binSize, int quantity, int iterations, bool uniformRealDistributionIsSet, bool printProgress);
std::vector<int> geneticAlgorithm(std::vector<int> data, int binSize, int quantity, int iterations, int populationSize, bool pointCrossover, bool mutationMethod, bool printProgress);
