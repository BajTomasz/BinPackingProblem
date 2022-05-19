//
// Created by tomasz on 21.04.2022.
//

#include <random>

#include "dataGenerator.h"
#include "algorithm"





void hillClimbing(std::vector<int> xTymczasowy, int binSize, int quantity) {
    // sporadic munmap_chunk(): invalid pointer, free(): invalid pointer
    int yTymczasowe = howManyBin(xTymczasowy, binSize, quantity);
    int yMax = yTymczasowe;
    std::vector<int> xMax = xTymczasowy;

    std::cout << yMax << std::endl;

    srand((unsigned) time(NULL));
    int x = rand() % (std::end(xTymczasowy) - std::begin(xTymczasowy));
    int xStart;
    int iMax;
    int range = 20;

    do {
        xStart = x;
        iMax = 0;
        for (int i = 0; i <= range; ++i) {
            if (x-i>=0 && x+i < xTymczasowy.size()) {
                std::swap(xTymczasowy[x], xTymczasowy[x-i]);
                yTymczasowe = howManyBin(xTymczasowy, binSize, quantity);
                if (yTymczasowe < yMax) {
                    yMax = yTymczasowe;
                    xMax = xTymczasowy;
                    iMax = i;
                }
                std::swap(xTymczasowy[x], xTymczasowy[x+i]);
                yTymczasowe = howManyBin(xTymczasowy, binSize, quantity);
                if (yTymczasowe < yMax) {
                    yMax = yTymczasowe;
                    xMax = xTymczasowy;
                    iMax = i;
                }
            }
        }
        x += iMax;
    } while (xStart != x);
    xTymczasowy.clear();
    std::cout << yMax;
}

void hillClimbingrandom(std::vector<int> xTymczasowy, int binSize, int quantity) {
    int n = 1000000;
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
    std::cout << yMax << std::endl;

    int numOfBins = 1;
    int sumInBin = 0;
    for (int i = 0; i < quantity; ++i) {
        int x = xMax.at(i);
        if (sumInBin + x <= binSize) {
            sumInBin += xMax.at(i);
            std::cout << xMax.at(i) << ' ';
        } else {
            std::cout << std::endl;
            sumInBin = xMax.at(i);
            std::cout << xMax.at(i) << ' ';
            numOfBins++;
        }
    }

}
