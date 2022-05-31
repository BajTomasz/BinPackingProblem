//
// Created by tomasz on 21.04.2022.
//

#include "algorithms.h"

std::vector<int> dataGenerator(int minRange, int maxRange, int quantity) {
    std::vector<int> data;
    srand((unsigned)time(NULL));
    for (int i = 0; i < quantity; i++) {
        int a = (rand() % (maxRange + 1 - minRange)) + minRange;
        data.push_back(a);
    }
    return data;
}
