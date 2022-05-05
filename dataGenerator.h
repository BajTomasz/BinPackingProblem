//
// Created by tomasz on 21.04.2022.
//
#include <iostream>

#ifndef BINPACKINGPROBLEM_DATA_H
#define BINPACKINGPROBLEM_DATA_H

void dataGenerator(int *data, int minRange, int maxRange, int quantity);
void hillClimbing();
void tabuSearch(int data[], int binSize, int quantity);
int howManyBin(int data[], int binSize, int quantity);

#endif //BINPACKINGPROBLEM_DATA_H
