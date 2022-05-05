//
// Created by tomasz on 21.04.2022.
//
#include "dataGenerator.h"
void dataGenerator(int * data, int minRange, int maxRange, int quantity) {
    for (int i = 0; i < quantity; i++) {
        data[i] = (rand() % (maxRange + 1 - minRange)) + minRange;
    }
}
