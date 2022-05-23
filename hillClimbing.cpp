//
// Created by tomasz on 21.04.2022.
//

#include <random>

#include "dataGenerator.h"
#include "algorithm"

void hillClimbing(std::vector<int> xTymczasowy, int binSize, int quantity) {
    int n = 1000;

    int yTymczasowe = howManyBin(xTymczasowy, binSize, quantity);
    int yMax = yTymczasowe;

    srand((unsigned) time(NULL));

    for (int i = 0; i < n; ++i) {
        int x = rand() % (std::end(xTymczasowy) - std::begin(xTymczasowy));
        for (int j = 0; j < xTymczasowy.size(); ++j) {
            std::swap(xTymczasowy[x], xTymczasowy[j]);
            yTymczasowe = howManyBin(xTymczasowy, binSize, quantity);
            if (yTymczasowe <= yMax) {
                yMax = yTymczasowe;
            }
        }
    }
    std::cout << yMax << std::endl;
}

void hillClimbingrandom(std::vector<int> xTymczasowy, int binSize, int quantity) {
    int n = 1000;
    int yTymczasowe, yMax = howManyBin(xTymczasowy, binSize, quantity);
    std::vector<int> xMax = xTymczasowy;

    for (int i = 0; i < n; ++i) {
        std::shuffle(std::begin(xTymczasowy), std::end(xTymczasowy), std::mt19937(std::random_device()()));
        yTymczasowe = howManyBin(xTymczasowy, binSize, quantity);
        if (yTymczasowe < yMax) {
            yMax = yTymczasowe;
            xMax = xTymczasowy;
        }
    }

    int numOfBins = 1;
    int sumInBin = 0;
    for (int i = 0; i < quantity; ++i) {
        int x = xMax.at(i);
        if (sumInBin + x <= binSize) {
            sumInBin += xMax.at(i);
        } else {
            sumInBin = xMax.at(i);
            numOfBins++;
        }
    }
    std::cout << numOfBins << std::endl;

}
