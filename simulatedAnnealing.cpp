//
// Created by tomasz on 17.05.2022.
//

#include <random>

#include "dataGenerator.h"
#include "algorithm"

void simulatdAnnealing(std::vector<int> xTymczasowy, int binSize, int quantity) {
    int n = 1000;
    int yTymczasowe, yMax = howManyBin(xTymczasowy, binSize, quantity);
    std::vector<int> xMax = xTymczasowy;
    std::vector<int> xNext = xTymczasowy;
    int iteration_counter = 1;

    for (int i = 0; i < n; ++i) {
        std::shuffle(std::begin(xNext), std::end(xNext), std::mt19937(std::random_device()()));
        if (howManyBin(xNext, binSize, quantity) < howManyBin(xTymczasowy, binSize, quantity)) {
            xTymczasowy = xNext;
        } else {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_real_distribution<> dis(0.0, 1.0);
            if (dis(gen) < exp(-abs(howManyBin(xTymczasowy, binSize, quantity) - howManyBin(xNext, binSize, quantity)) *
                               iteration_counter / 1000)) {
                xTymczasowy = xNext;
            }
        }
        if (howManyBin(xTymczasowy, binSize, quantity) < howManyBin(xMax, binSize, quantity)) xMax = xTymczasowy;
        std::cout << iteration_counter << " " << howManyBin(xTymczasowy, binSize, quantity) <<  " " << howManyBin(xMax, binSize, quantity) << std::endl;
        iteration_counter++;
    }
}