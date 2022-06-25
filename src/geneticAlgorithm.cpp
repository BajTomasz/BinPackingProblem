//
// Created by tomasz on 16.06.2022.
//

#include "algorithms.h"
#include <algorithm>
#include <vector>
#include <random>

std::vector<std::vector<int>> createPopulation(int populationSize, int dataSize){
    std::vector<int> chromosome;
    std::vector<std::vector<int>> population;
    for (int i = 0; i < dataSize; ++i) {
        chromosome.push_back(i);
    }
    for (int i = 0; i < populationSize; ++i) {
        population.push_back(chromosome);
        std::shuffle(std::begin(population[i]), std::end(population[i]), std::mt19937(std::random_device()()));
    }
    return population;
}

std::vector<int> getPopulationFitness(std::vector<int> data, std::vector<std::vector<int>> population, int binSize){
    std::vector<int> populationFitness;
    for (int i = 0; i < population.size(); ++i) {
        std::vector<int> tmp;
        for (int j = 0; j < data.size(); ++j) {
            tmp.push_back(data[population[i][j]]);
        }
        populationFitness.push_back(howManyBin(tmp, binSize, data.size()));
        tmp.clear();
    }
    return populationFitness;
}

std::vector<std::vector<int>> roulette(std::vector<std::vector<int>> population, std::vector<int> populationFitness, int bestScore){
    long sumOfPopulationFitness = 0;
    srand((unsigned) time(NULL));
    int populationSize = population.size();

    for (int i = 0; i < populationSize; ++i) {
        populationFitness[i] = populationFitness[i]-bestScore;
        sumOfPopulationFitness += populationFitness[i];
    }

    for(int j=0; j < populationSize/2; j++){
        int offset = 0;
        if (sumOfPopulationFitness != 0){
            offset = rand() % sumOfPopulationFitness;
        }
        int z = 0;
        while(offset > 0) {
            if(offset < populationFitness[z]){
                break;
            }else{
                offset = offset - populationFitness[z];
                z++;
            }
        }
        sumOfPopulationFitness -= populationFitness[z];
        populationFitness.erase(populationFitness.begin()+z);
        population.erase(population.begin()+z);

    }
    return population;
}

std::vector<std::vector<int>> doOffspring(std::vector<std::vector<int>> parents){
    std::vector<std::vector<int>> offspring = parents;
    srand((unsigned) time(NULL));
    int i = 0;

    while(i < parents.size()-1) {
        std::vector<int> firstChildren;
        std::vector<int> secondChildren;
        //Select a random crossover point

        int crossOverPoint = rand() % parents[0].size();

        //Swap values among parents
        for (int j = 0; j < crossOverPoint; j++) {
            firstChildren.push_back(parents[i][j]);
            secondChildren.push_back(parents[i+1][j]);
        }
        for (int j = 0; j < parents[0].size(); ++j) {
            auto it = std::find(firstChildren.begin(), firstChildren.end(), parents[i+1][j]);
            if (it == firstChildren.end()){
                firstChildren.push_back(parents[i+1][j]);
            }
            it = std::find(secondChildren.begin(), secondChildren.end(), parents[i][j]);
            if (it == secondChildren.end()){
                secondChildren.push_back(parents[i][j]);
            }
        }
        offspring.push_back(firstChildren);
        offspring.push_back(secondChildren);
        i += 2;
    }
    return offspring;
}

std::vector<int> geneticAlgorithm(std::vector<int> data, int binSize, int quantity, int iterations, int populationSize){
    int iter = iterations;
    bool continueCondition = true;

    //stwórz populację początkową
    std::vector<std::vector<int>> population = createPopulation(populationSize, quantity);;
    std::vector<int> populationFitness = getPopulationFitness(data, population, binSize);
    int bestScore;
    std::vector<int> bestSolution;

    for (int i = 0; i < populationFitness.size(); ++i) {
        if (populationFitness[i] < bestScore ){
            bestScore = populationFitness[i];
            bestSolution = population[i];
        }
    }

    do {
        //seleckcja rodziców
        std::vector<std::vector<int>> parents = roulette(population,populationFitness, bestScore) ;
        auto parentsSize = parents.size();

        //robienie dzieci
        std::vector<std::vector<int>> offspring = doOffspring(parents);
        auto offspringSize = offspring.size();
        auto populationSize = population.size();
        //mutowanie dzieci

        //warunek końcowy
        iter--;
        if(!iter){
            continueCondition = false;
        }
        population = offspring;
        populationFitness = getPopulationFitness(data, population, binSize);

        for(int i = 0; i < populationFitness.size(); i++) {
            if (bestScore > populationFitness[i]) {
                bestScore = populationFitness[i];
                bestSolution = population[i];
            }
        }
        std::cout << iterations-iter << " " << "score" << " " << bestScore << std::endl;
    } while (continueCondition);

    //oddawane najlepszego rozwiązania


    return data;
}