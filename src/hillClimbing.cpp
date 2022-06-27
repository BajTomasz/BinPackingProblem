//
// Created by tomasz on 21.04.2022.
//

#include "algorithms.h"

std::vector<int>
hillClimbing(std::vector<int> startSolution, int binSize, int quantity, int iterations, int printMode) {
    std::default_random_engine generator;
    int score = howManyBin(startSolution, binSize, quantity);
    int bestScore = score;
    std::vector<int> bestSolution = startSolution;
    std::uniform_int_distribution<int> dist(0, std::end(startSolution) - std::begin(startSolution));

    for (int i = 0; i < iterations; ++i) {
        int x = dist(generator);
        for (int j = 0; j < startSolution.size(); ++j) {
            std::swap(startSolution[x], startSolution[j]);
            score = howManyBin(startSolution, binSize, quantity);
            if (score < bestScore) {
                bestScore = score;
                bestSolution = startSolution;
            } else std::swap(startSolution[x], startSolution[j]);
        }
        startSolution = bestSolution;
        if (printMode == 1) std::cout << i << " " << score << " " << bestScore << std::endl;
    }
    return bestSolution;
}

std::vector<int>
hillClimbingRandom(std::vector<int> startSolution, int binSize, int quantity, int iterations, int printMode) {
    std::default_random_engine generator;
    int score = howManyBin(startSolution, binSize, quantity);
    int bestScore = score;
    std::vector<int> bestSolution = startSolution;
    std::uniform_int_distribution<int> dist(0, std::end(startSolution) - std::begin(startSolution));

    for (int i = 0; i < iterations; ++i) {
        int x = dist(generator);
        std::swap(startSolution[x], startSolution[i]);
        score = howManyBin(startSolution, binSize, quantity);
        if (score < bestScore) {
            bestScore = score;
            bestSolution = startSolution;
        } else std::swap(startSolution[x], startSolution[i]);
        if (printMode == 1) std::cout << i << " " << score << " " << bestScore << std::endl;
    }
    return bestSolution;
}
