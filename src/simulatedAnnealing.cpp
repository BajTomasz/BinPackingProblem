//
// Created by tomasz on 17.05.2022.
//

#include "algorithms.h"

std::vector<int> simulatedAnnealing(std::vector<int> startSolution, int binSize, int quantity, int iterations,
                                    bool uniformRealDistributionIsSet, int printMode) {
    int score, nextScore, bestScore;
    double boltzmannDistribution;
    std::vector<int> bestSolution = startSolution;
    std::vector<int> nextSolution = startSolution;
    std::default_random_engine generator;
    std::uniform_real_distribution<> uniformRealDistribution(0.0, 1.0);
    std::normal_distribution<double> normalDistribution(0.5, 0.25);
    score = howManyBin(startSolution, binSize, quantity);

    for (int i = 0; i < iterations; ++i) {
        std::shuffle(std::begin(nextSolution), std::end(nextSolution), generator);
        nextScore = howManyBin(nextSolution, binSize, quantity);
        boltzmannDistribution = exp(-abs(score - nextScore) / (iterations / (i + 1)));
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
    }
    return bestSolution;
}
