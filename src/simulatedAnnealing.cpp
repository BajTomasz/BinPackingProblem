//
// Created by tomasz on 17.05.2022.
//

#include "algorithms.h"

std::vector<int> simulatedAnnealing(std::vector<int> startSolution, int binSize, int quantity, int iterations,
                                    bool uniformRealDistributionIsSet, int printMode, int endMode) {
    int score, nextScore, bestScore;
    double boltzmannDistribution;
    std::vector<int> bestSolution = startSolution;
    std::vector<int> nextSolution = startSolution;
    std::default_random_engine generator;
    std::uniform_real_distribution<> uniformRealDistribution(0.0, 1.0);
    std::normal_distribution<double> normalDistribution(0.5, 0.25);
    score = howManyBin(startSolution, binSize, quantity);
    int i = 0;
    bool continueCondition = true;
    clock_t start = clock();
    clock_t end = clock();

    while (continueCondition) {
        std::shuffle(std::begin(nextSolution), std::end(nextSolution), generator);
        nextScore = howManyBin(nextSolution, binSize, quantity);
        boltzmannDistribution = exp(-abs(score - nextScore) * (i + 1) / iterations);
        if (nextScore < score) {
            startSolution = nextSolution;
            score = nextScore;
        } else if (uniformRealDistributionIsSet && (uniformRealDistribution(generator) < boltzmannDistribution)) {
            startSolution = nextSolution;
            score = nextScore;
        } else if (!uniformRealDistributionIsSet && (normalDistribution(generator) < boltzmannDistribution)) {
            startSolution = nextSolution;
            score = nextScore;
        }
        bestScore = howManyBin(bestSolution, binSize, quantity);
        if (score < bestScore) {
            bestSolution = startSolution;
            bestScore = score;
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
