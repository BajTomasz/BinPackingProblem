//
// Created by tomasz on 21.04.2022.
//

#include "algorithms.h"

#include <algorithm>
#include <random>

void hillClimbing(std::vector<int> startSolution, int binSize, int quantity, int iterations) {

    int score = howManyBin(startSolution, binSize, quantity);
    int bestScore = score;

    srand((unsigned) time(NULL));

    for (int i = 0; i < iterations; ++i) {
        int x = rand() % (std::end(startSolution) - std::begin(startSolution));
        for (int j = 0; j < startSolution.size(); ++j) {
            std::swap(startSolution[x], startSolution[j]);
            score = howManyBin(startSolution, binSize, quantity);
            if (score < bestScore) {
                bestScore = score;
            }
        }
        std::cout << i << " " << score << " " << bestScore << std::endl;
    }
}

void hillClimbingRandom(std::vector<int> startSolution, int binSize, int quantity, int iterations) {
    int score = howManyBin(startSolution, binSize, quantity);
    int bestScore = score;
    for (int i = 0; i < iterations; ++i) {
        std::shuffle(std::begin(startSolution), std::end(startSolution), std::mt19937(std::random_device()()));
        score = howManyBin(startSolution, binSize, quantity);
        if (score < bestScore) {
            bestScore = score;
        }
        std::cout << i << " " << score << " " << bestScore << std::endl;
    }
}
