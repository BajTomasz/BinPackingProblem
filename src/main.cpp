//
// Created by tomasz on 21.04.2022.
//

#include "algorithms.h"

#include <any>
#include <complex>
#include <fstream>

void printSolution(std::vector<int> bestSolution) {
    for (auto i: bestSolution) std::cout << i << ", ";
    std::cout << std::endl << std::endl;
}

std::vector<int> loadProblem(std::string fname) {
    std::vector<int> problem;
    std::fstream file;
    std::string line;
    int x;

    file.open(fname);
    if (file.is_open()) {
        std::getline(file, line);
        while (file) {
            std::stringstream sline(line);
            sline >> x;
            problem.push_back(x);
            std::getline(file, line);
        }
    } else std::cout << "Couldn't open file\n";
    file.close();
    std::shuffle(std::begin(problem), std::end(problem), std::mt19937(std::random_device()()));
    return problem;
}

auto arg = [](int argc, char **argv, std::string name, auto default_value) -> decltype(default_value) {
    std::string paramname = "";
    std::any ret = default_value;
    for (auto argument: std::vector<std::string>(argv, argv + argc)) {
        if ((argument.size() > 0) && (argument[0] == '-')) {
            if (paramname != "") {
                if (name == argument.substr(1)) ret = true;
            }
            paramname = argument.substr(1);
        } else if (name == paramname) {
            if (std::is_same_v<decltype(default_value), int>) ret = stoi(argument);
            else if (std::is_same_v<decltype(default_value), double>) ret = stod(argument);
            else if (std::is_same_v<decltype(default_value), char>) ret = argument.at(0);
            else if (std::is_same_v<decltype(default_value), bool>)
                ret = (argument == "true") || (argument == "1") || (argument == "yes");
            else ret = argument;
            paramname = "";
        }
    }
    return std::any_cast<decltype(default_value)>(ret);
};

int main(int argc, char **argv) {
    int minWeight = 1;
    int maxWeight = 10;
    std::vector<int> data;

    auto fname = arg(argc, argv, "fname", std::string(""));
    auto iterations = arg(argc, argv, "iterations", 1000);
    auto method = arg(argc, argv, "method", std::string(""));
    auto tabuSize = arg(argc, argv, "tabuSize", 100);
    auto quantity = arg(argc, argv, "quantity", 500);
    auto binSize = arg(argc, argv, "binSize", 15);
    auto uniformRealDistributionIsSet = arg(argc, argv, "uniformRealDistributionIsSet", false);
    auto populationSize = arg(argc, argv, "populationSize", 400);
    auto pointCrossover = arg(argc, argv, "pointCrossover", true);
    auto mutationMethod = arg(argc, argv, "mutationMethod", true);
    auto printProgress = arg(argc, argv, "printProgress", false);
    auto generateData = arg(argc, argv, "dataGenerator", false);

    if (generateData) data = dataGenerator(minWeight, maxWeight, quantity);
    else if (fname.empty()) {
        int record;
        while (std::cin >> record)data.push_back(record);
    } else {
        data = loadProblem(fname);
        quantity = data.size();
    }

    if (method == "all") {
        hillClimbing(data, binSize, quantity, iterations, printProgress);
        hillClimbingRandom(data, binSize, quantity, iterations, printProgress);
        tabuSearch(data, binSize, quantity, tabuSize, iterations, printProgress);
        simulatedAnnealing(data, binSize, quantity, iterations, uniformRealDistributionIsSet, printProgress);
        geneticAlgorithm(data, binSize, quantity, iterations, populationSize, pointCrossover, mutationMethod, printProgress);
    } else if (method == "hillClimbing") {
        hillClimbing(data, binSize, quantity, iterations, printProgress);
    } else if (method == "hillClimbingRandom") {
        hillClimbingRandom(data, binSize, quantity, iterations, printProgress);
    } else if (method == "tabuSearch") {
        tabuSearch(data, binSize, quantity, tabuSize, iterations, printProgress);
    } else if (method == "simulatedAnnealing") {
        simulatedAnnealing(data, binSize, quantity, iterations, uniformRealDistributionIsSet, printProgress);
    } else if (method == "geneticAlgorithm") {
        geneticAlgorithm(data, binSize, quantity, iterations, populationSize, pointCrossover, mutationMethod, printProgress);
    } else if (method == "" && generateData) {
        printSolution(data);
    }
    return 0;
}
