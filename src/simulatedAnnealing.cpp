//
// Created by tomasz on 17.05.2022.
//

#include "algorithms.h"

#include <algorithm>
#include <random>

void simulatedAnnealing(std::vector<int> startSolution, int binSize, int quantity, int iterations) {

    int score, nextScore;
    int bestScore = howManyBin(startSolution, binSize, quantity);
    std::vector<int> bestSolution = startSolution;
    std::vector<int> nextSolution = startSolution;
    int iteration_counter = 1;

    for (int i = 0; i < iterations; ++i) {
        std::shuffle(std::begin(nextSolution), std::end(nextSolution), std::mt19937(std::random_device()()));
        score = howManyBin(startSolution, binSize, quantity);
        nextScore = howManyBin(nextSolution, binSize, quantity);
        if ( nextScore < score ){
            startSolution = nextSolution;
            score = nextScore;
        } else {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_real_distribution<> dis(0.0, 1.0);
            if (dis(gen) < exp(-abs(score - nextScore) * iteration_counter / 1000)) {
                startSolution = nextSolution;
                score = nextScore;
            }
        }
        bestScore = howManyBin(bestSolution, binSize, quantity);
        if (score < bestScore){
            bestSolution = startSolution;
            bestScore = score;
        }
        std::cout << i << " " << score << " " << bestScore << std::endl;
        iteration_counter++;
    }
}
