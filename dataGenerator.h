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
void hillClimbingrandom(std::vector<int> data, int binSize, int quantity);
void hillClimbing(std::vector<int> data, int binSize, int quantity);
void tabuSearch(std::vector<int> data, int binSize, int quantity);
void simulatdAnnealing(std::vector<int> data, int binSize, int quantity);

#endif //BINPACKINGPROBLEM_DATA_H
