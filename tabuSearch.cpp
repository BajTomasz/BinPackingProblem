//
// Created by tomasz on 21.04.2022.
//

#include "dataGenerator.h"
#include <list>
#include <algorithm>

void tabuSearch(std::vector<int> xTymczasowy, int binSize, int quantity){
    int n = 1000;

    int yTymczasowe = howManyBin(xTymczasowy, binSize, quantity);
    int yMax = yTymczasowe;
    std::vector<int> xMax = xTymczasowy;
    int maxTabuSize = 100;
    std:: vector<std::vector<int>> tabuList = {xTymczasowy};
    bool betterSolutionIsFound;
    int tabuListOffset = 1;
    srand((unsigned) time(NULL));

    for (int i = 0; i < n; ++i) {
        betterSolutionIsFound = false;
        int x = rand() % (std::end(xTymczasowy) - std::begin(xTymczasowy));
        for (int j = 0; j < xTymczasowy.size(); ++j) {
            std::swap(xTymczasowy[x], xTymczasowy[j]);
            yTymczasowe = howManyBin(xTymczasowy, binSize, quantity);
            bool isNotInTabu = std::find(tabuList.begin(), tabuList.end(), xTymczasowy) == tabuList.end();
            if (yTymczasowe < yMax and  isNotInTabu){
                yMax = yTymczasowe;
                xMax = xTymczasowy;
                betterSolutionIsFound = true;
            }
        }
        //jeżeli zneleźliśmy lepsze rozwiązanie dodaj do tabuListy
        //jeśli nie to cofnij się w tabuLiście i szukaj innego rozwiązania
        if (betterSolutionIsFound){
            tabuList.push_back(xMax);
            if (tabuList.size() > maxTabuSize) {
                tabuList.erase(tabuList.begin());
            }
        } else if ((int)tabuList.size()-tabuListOffset >= 0) {
            xTymczasowy = tabuList[tabuList.size() - tabuListOffset];
            tabuListOffset++;
            }
        else{
            std::cout <<"End of neighbors" <<std::endl;
            break;
        }
    }

    std::cout << yMax << std::endl;
}
