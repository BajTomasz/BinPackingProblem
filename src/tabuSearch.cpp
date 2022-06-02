//
// Created by tomasz on 21.04.2022.
//

#include "algorithms.h"

#include <algorithm>
#include <list>

std::vector<int> tabuSearch(std::vector<int> startSolution, int binSize, int quantity, int tabuSize, int iterations){

    int score = howManyBin(startSolution, binSize, quantity);
    int bestScore = score;
    std::vector<int> bestSolution = startSolution;
    std:: vector<std::vector<int>> tabuList = {startSolution};
    bool betterSolutionIsFound;
    int tabuListOffset = 1;
    srand((unsigned) time(NULL));

    for (int i = 0; i < iterations; ++i) {
        betterSolutionIsFound = false;
        int x = rand() % (std::end(startSolution) - std::begin(startSolution));
        for (int j = 0; j < startSolution.size(); ++j) {
            std::swap(startSolution[x], startSolution[j]);
            score = howManyBin(startSolution, binSize, quantity);
            bool isNotInTabu = std::find(tabuList.begin(), tabuList.end(), startSolution) == tabuList.end();
            if (score <= bestScore and isNotInTabu){
                bestScore = score;
                bestSolution = startSolution;
                betterSolutionIsFound = true;
            }
        }
        if (betterSolutionIsFound){
            tabuList.push_back(bestSolution);
            if (tabuList.size() > tabuSize) {
                tabuList.erase(tabuList.begin());
            }
            tabuListOffset = 1;
        } else if ((int)tabuList.size()-tabuListOffset >= 0) {
            startSolution = tabuList[tabuList.size() - tabuListOffset];
            tabuListOffset++;
            }
        else{
            break;
        }
        std::cout << i << " " << score << " " << bestScore << std::endl;
    }
    return bestSolution;
}
