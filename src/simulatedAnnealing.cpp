//
// Created by tomasz on 17.05.2022.
//

#include "algorithms.h"

#include <algorithm>
#include <random>

void simulatedAnnealing(std::vector<int> startSolution, int binSize, int quantity, int iterations, bool uniformRealDistributionIsSet) {

    int score, nextScore, bestScore;
    double boltzmannDistribution;
    std::vector<int> bestSolution = startSolution;
    std::vector<int> nextSolution = startSolution;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> uniformRealDistribution(0.0, 1.0);
    std::normal_distribution<double> normalDistribution(0.5,0.25);

    for (int i = 0; i < iterations; ++i) {
        std::shuffle(std::begin(nextSolution), std::end(nextSolution), gen);
        score = howManyBin(startSolution, binSize, quantity);
        nextScore = howManyBin(nextSolution, binSize, quantity);
        boltzmannDistribution = exp(-abs(score - nextScore) / (iterations/(i+1)));
        if ( nextScore < score ){
            startSolution = nextSolution;
            score = nextScore;
        } else if (uniformRealDistributionIsSet && (uniformRealDistribution(gen) < boltzmannDistribution)) {
                startSolution = nextSolution;
                score = nextScore;
        } else if (!uniformRealDistributionIsSet && (normalDistribution(gen) < boltzmannDistribution)) {
            startSolution = nextSolution;
            score = nextScore;
        }
        bestScore = howManyBin(bestSolution, binSize, quantity);
        if (score < bestScore){
            bestSolution = startSolution;
            bestScore = score;
        }
        std::cout << i << " " << score << " " << bestScore << std::endl;
    }
}
