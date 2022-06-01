//
// Created by tomasz on 21.04.2022.
//

#include <iostream>
#include <vector>

std::vector<int> dataGenerator(int minRange, int maxRange, int quantity);
int howManyBin(std::vector<int> startSolution, int binSize, int quantity);
void hillClimbingRandom(std::vector<int> startSolution, int binSize, int quantity, int iterations);
void hillClimbing(std::vector<int> startSolution, int binSize, int quantity, int iterations);
void tabuSearch(std::vector<int> startSolution, int binSize, int quantity, int tabuSize, int iterations);
void simulatedAnnealing(std::vector<int> startSolution, int binSize, int quantity, int iterations);
