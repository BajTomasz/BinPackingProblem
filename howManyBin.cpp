//
// Created by tomasz on 25.04.2022.
//

#include "dataGenerator.h"
int howManyBin(int data[], int binSize, int quantity){
    int numOfBins = 1;
    int sumInBin = 0;
    for (int i = 0; i < quantity; ++i) {
        if (sumInBin + data[i] <= binSize){
            sumInBin += data[i];
        } else{
            sumInBin = data[i];
            numOfBins++;
        }
    }
    return numOfBins;
}
