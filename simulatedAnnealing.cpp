//
// Created by tomasz on 17.05.2022.
//

#include "algorithms.h"

#include <algorithm>
#include <random>

void simulatedAnnealing(std::vector<int> startSolution, int binSize, int quantity, int iterations) {

    int score = howManyBin(startSolution, binSize, quantity);
    int bestScore = score;
    std::vector<int> bestSolution = startSolution;
    std::vector<int> nextSolution = startSolution;
    int iteration_counter = 1;

    for (int i = 0; i < iterations; ++i) {
        std::shuffle(std::begin(nextSolution), std::end(nextSolution), std::mt19937(std::random_device()()));
        if (howManyBin(nextSolution, binSize, quantity) < howManyBin(startSolution, binSize, quantity)) {
            startSolution = nextSolution;
        } else {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_real_distribution<> dis(0.0, 1.0);
            if (dis(gen) < exp(-abs(howManyBin(startSolution, binSize, quantity) - howManyBin(nextSolution, binSize, quantity)) * iteration_counter / 1000)) {
                startSolution = nextSolution;
            }
        }
        if (howManyBin(startSolution, binSize, quantity) < howManyBin(bestSolution, binSize, quantity)){
            bestSolution = startSolution;
            bestScore = howManyBin(bestSolution, binSize, quantity);
        }
        std::cout << i << " " << score << " " << bestScore << std::endl;
        iteration_counter++;
    }
}
