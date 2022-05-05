//
// Created by tomasz on 21.04.2022.
//

#include "dataGenerator.h"
#include <map>

void req(int *datacp, int *data, int *quantityPtr, int x, int *binSizePtr, int offset) {
    for (int i = 0; i < x; ++i) {
        datacp[offset] = data[offset-i]; // przypisz jeśli nie ma na tabu
        req(datacp, data, quantityPtr, --x, binSizePtr, ++offset);
    }  //jeśli nie to wyświetl wynik
    int scr = howManyBin(datacp, *binSizePtr, *quantityPtr);
    if (scr != 106){ std::cout << scr << std::endl; }
}
// trzeba przy rekurencji usuwać dany rekord z tablicy orginalnych danych

void tabuSearch(int data[], int binSize, int quantity){
    int datacp[quantity];
    int tmp;
    int lowestBinsNum, oldLowestBinsNum, tmpBins;
    lowestBinsNum = howManyBin(data, binSize, quantity);
    oldLowestBinsNum = lowestBinsNum;
    int minI, minJ;
    int timer =50;

    for (int i = 0; i < quantity; ++i) {
        datacp[i] = data[i];
    }

    int x = 10; //x kroków i x tabu
/*
    std::map<int, int> tabuList;
    for (int i = 1; i <= x; ++i) {
        tabuList[quantity-i] = datacp[quantity-i];
        std::cout<<datacp[quantity-i]<<std::endl;
    } // zapisanie ostatnich5 kroków do tabu
*/

    //for (int i = quantity-x; i > 0; --i) {
    
    
        req(datacp, data, &quantity, x, &binSize, quantity-x);
    //}

}