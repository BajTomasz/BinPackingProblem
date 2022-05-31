//
// Created by tomasz on 21.04.2022.
//
#include <iostream>
#include <array>
#include <vector>

#ifndef BINPACKINGPROBLEM_DATA_H
#define BINPACKINGPROBLEM_DATA_H

std::vector<int> dataGenerator(std::vector<int> data, int minRange, int maxRange, int quantity);
int howManyBin(std::vector<int> data, int binSize, int quantity);
void hillClimbingrandom(std::vector<int> data, int binSize, int quantity, int iterations);
void hillClimbing(std::vector<int> data, int binSize, int quantity, int iterations);
void tabuSearch(std::vector<int> data, int binSize, int quantity, int tabuSize, int iterations);
void simulatdAnnealing(std::vector<int> data, int binSize, int quantity, int iterations);

#endif //BINPACKINGPROBLEM_DATA_H
