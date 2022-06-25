//
// Created by tomasz on 21.04.2022.
//

#include <iostream>
#include <vector>

std::vector<int> dataGenerator(int minRange, int maxRange, int quantity);
int howManyBin(std::vector<int> startSolution, int binSize, int quantity);
std::vector<int> hillClimbingRandom(std::vector<int> startSolution, int binSize, int quantity, int iterations);
std::vector<int> hillClimbing(std::vector<int> startSolution, int binSize, int quantity, int iterations);
std::vector<int> tabuSearch(std::vector<int> startSolution, int binSize, int quantity, int tabuSize, int iterations);
std::vector<int> simulatedAnnealing(std::vector<int> startSolution, int binSize, int quantity, int iterations, bool uniformRealDistributionIsSet);
std::vector<int> geneticAlgorithm(std::vector<int> data, int binSize, int quantity, int iterations, int populationSize, bool pointCrossover, bool mutationMethod);
