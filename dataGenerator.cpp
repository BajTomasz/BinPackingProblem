//
// Created by tomasz on 21.04.2022.
//
#include "dataGenerator.h"
std::vector<int> dataGenerator(std::vector<int> data, int minRange, int maxRange, int quantity) {
    srand((unsigned)time(NULL));
    for (int i = 0; i < quantity; i++) {
        int a = (rand() % (maxRange + 1 - minRange)) + minRange;
        data.push_back(a);
    }
    return data;
}
