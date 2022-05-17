//
// Created by tomasz on 21.04.2022.
//

#include "dataGenerator.h"
#include "algorithm"



void hillClimbing(std::vector<int> xTymczasowy, int binSize, int quantity) {
    int n = 1000000;

    int yTymczasowe, yMax = howManyBin(xTymczasowy, binSize, quantity);
    std::vector<int> xMax;
    xMax = xTymczasowy;

    for (int i = 0; i < n; ++i) {
        std::random_shuffle(std::begin(xTymczasowy), std::end(xTymczasowy));
        yTymczasowe = howManyBin(xTymczasowy, binSize, quantity);
        if(yTymczasowe<yMax){
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
            std::cout << xMax.at(i)<< ' ';
            numOfBins++;
        }
    }

}