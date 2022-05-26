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
            if (yTymczasowe < yMax) {
                yMax = yTymczasowe;
            }
        }
        std::cout << i << " " << yTymczasowe << " " << yMax << std::endl;
    }
}

void hillClimbingrandom(std::vector<int> xTymczasowy, int binSize, int quantity) {
    int n = 1000;
    int yTymczasowe, yMax = howManyBin(xTymczasowy, binSize, quantity);

    for (int i = 0; i < n; ++i) {
        std::shuffle(std::begin(xTymczasowy), std::end(xTymczasowy), std::mt19937(std::random_device()()));
        yTymczasowe = howManyBin(xTymczasowy, binSize, quantity);
        if (yTymczasowe < yMax) {
            yMax = yTymczasowe;
        }
        std::cout << i << " " << yTymczasowe << " " << yMax << std::endl;
    }
}
