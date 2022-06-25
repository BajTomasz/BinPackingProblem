//
// Created by tomasz on 21.04.2022.
//

#include "algorithms.h"

std::vector<int> dataGenerator(int minRange, int maxRange, int quantity) {
    std::vector<int> data;
    std::default_random_engine generator;
    std::uniform_int_distribution<int> dist(minRange, (maxRange - minRange + 1));
    for (int i = 0; i < quantity; i++) {
        int a = dist(generator);
        data.push_back(a);
    }
    return data;
}
