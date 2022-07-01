//
// Created by tomasz on 21.04.2022.
//

#include "algorithms.h"

std::vector<int>
hillClimbing(std::vector<int> startSolution, int binSize, int quantity, int iterations, int printMode, int endMode) {
    std::default_random_engine generator;
    int score = howManyBin(startSolution, binSize, quantity);
    int bestScore = score;
    std::vector<int> bestSolution = startSolution;
    std::uniform_int_distribution<int> dist(0, std::end(startSolution) - std::begin(startSolution));
    int i = 0;
    bool continueCondition = true;
    clock_t start = clock();
    clock_t end = clock();
    int x = 0;
    bool betterSolutionIsFound;

    while (continueCondition) {
        betterSolutionIsFound = false;
        for (int j = 0; j < startSolution.size(); ++j) {
            std::swap(startSolution[x], startSolution[j]);
            score = howManyBin(startSolution, binSize, quantity);
            if (score < bestScore) {
                bestScore = score;
                bestSolution = startSolution;
                betterSolutionIsFound = true;
            } else std::swap(startSolution[x], startSolution[j]);
        }

        if (betterSolutionIsFound) {
            startSolution = bestSolution;
            x = 0;
        } else if (x < startSolution.size() - 1) x++;
        else continueCondition = false;

        if (printMode == 1) std::cout << i << " " << score << " " << bestScore << std::endl;

        if (endMode == 0) ++i;
        else if (endMode == 1) i = end - start;
        if (endMode == 0 && i > iterations) continueCondition = false;
        else if (endMode == 1 && i > iterations) continueCondition = false;
        end = clock();
    }
    return bestSolution;
}

std::vector<int>
hillClimbingRandom(std::vector<int> startSolution, int binSize, int quantity, int iterations, int printMode,
                   int endMode) {
    std::default_random_engine generator;
    int score = howManyBin(startSolution, binSize, quantity);
    int bestScore = score;
    std::vector<int> bestSolution = startSolution;
    std::uniform_int_distribution<int> dist(0, std::end(startSolution) - std::begin(startSolution));
    int i = 0;
    bool continueCondition = true;
    clock_t start = clock();
    clock_t end = clock();

    while (continueCondition) {
        int x = dist(generator);
        for (int j = 0; j < startSolution.size(); ++j) {
            std::swap(startSolution[x], startSolution[j]);
            score = howManyBin(startSolution, binSize, quantity);
            if (score < bestScore) {
                bestScore = score;
                bestSolution = startSolution;
            } else std::swap(startSolution[x], startSolution[j]);
        }
        if (printMode == 1) std::cout << i << " " << score << " " << bestScore << std::endl;

        if (endMode == 0) ++i;
        else if (endMode == 1) i = end - start;
        if (endMode == 0 && i > iterations) continueCondition = false;
        else if (endMode == 1 && i > iterations) continueCondition = false;
        end = clock();
    }
    return bestSolution;
}
