//
// Created by tomasz on 21.04.2022.
//

#include "algorithms.h"

std::vector<int>
tabuSearch(std::vector<int> startSolution, int binSize, int quantity, int tabuSize, int iterations, int printMode) {
    int score = howManyBin(startSolution, binSize, quantity);
    int bestScore = score;
    std::vector<int> bestSolution = startSolution;
    std::vector<std::vector<int>> tabuList = {startSolution};
    bool betterSolutionIsFound;
    int tabuListOffset = 1;
    std::default_random_engine generator;
    std::uniform_int_distribution<int> dist(0, std::end(startSolution) - std::begin(startSolution));

    for (int i = 0; i < iterations; ++i) {
        betterSolutionIsFound = false;
        int x = dist(generator);
        for (int j = 0; j < startSolution.size(); ++j) {
            std::swap(startSolution[x], startSolution[j]);
            score = howManyBin(startSolution, binSize, quantity);
            bool isNotInTabu = std::find(tabuList.begin(), tabuList.end(), startSolution) == tabuList.end();
            if (score <= bestScore and isNotInTabu) {
                bestScore = score;
                bestSolution = startSolution;
                betterSolutionIsFound = true;
            }
        }
        if (betterSolutionIsFound) {
            tabuList.push_back(bestSolution);
            if (tabuList.size() > tabuSize) tabuList.erase(tabuList.begin());
            tabuListOffset = 1;
        } else if ((int) tabuList.size() - tabuListOffset >= 0) {
            startSolution = tabuList[tabuList.size() - tabuListOffset];
            tabuListOffset++;
        } else break;
        if (printMode == 1) std::cout << i << " " << score << " " << bestScore << std::endl;
    }
    return bestSolution;
}
