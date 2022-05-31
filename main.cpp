#include "dataGenerator.h"

#include <vector>
#include <iostream>
#include <random>

#include <complex>
#include <any>
#include <fstream>

std::vector<int> loadProblem(std::string fname) {
    using namespace std;
    std::vector<int> problem;
    istream *fst = &cin;
    ifstream f;
    if (fname != "") {
        f = ifstream(fname);
        fst = &f;
    }
    string line;
    while (getline(*fst, line)) {
        stringstream sline(line);
        int x;
        sline >> x;
        problem.push_back({x});
    }
    return problem;
}

auto arg = [](int argc, char** argv, std::string name, auto default_value) -> decltype(default_value) {
    using namespace std;
    string paramname = "";
    any ret = default_value;
    for (auto argument: vector<string>(argv, argv + argc)) {
        if ((argument.size() > 0) && (argument[0] == '-')) {
            if (paramname != "") {
                if (name == argument.substr(1)) ret = true;
            }
            paramname = argument.substr(1);
        } else if (name == paramname) {
            if (std::is_same_v<decltype(default_value), int>) ret = stoi(argument);
            else if (std::is_same_v<decltype(default_value), double>) ret = stod( argument );
            else if (std::is_same_v<decltype(default_value), char>) ret = argument.at(0);
            else if (std::is_same_v<decltype(default_value), bool>) ret = (argument=="true") || (argument=="1") || (argument=="yes");
            else ret = argument;
            paramname = "";
        }
    }
    return std::any_cast<decltype(default_value)>(ret);
};

int main(int argc, char **argv) {

    auto fname = arg(argc, argv, "fname", std::string(""));
    auto iterations = arg(argc, argv, "iterations", 1000);
    auto method = arg(argc, argv, "method", std::string("hillClimbing"));
    auto tabu_size = arg(argc, argv, "tabu_size", 100);

    int minWeight = 1;
    int maxWeight = 10;
    int binSize = 15; //binSize > maxRange
    const int quantity = 500;
    std::vector<int> data;

    if(fname==""){
        std::cout<<"Wpisz każdą daną po enterze"<<std::endl;
        int fewfwef;
        while(std::cin >> fewfwef){
             data.push_back(fewfwef);
        }
    } else{
        data = loadProblem(fname);
    }
    for (int i = 0; i < data.size(); ++i) {
        std::cout << data[i]<<std::endl;
    }



    //data = dataGenerator(data, minWeight, maxWeight, quantity);
    //std::cout << howManyBin(data, binSize, quantity) << std::endl;


//    if (method == "all") {
//        hillClimbing(data, binSize, quantity, iterations);
//        hillClimbingrandom(data, binSize, quantity, iterations);
//        tabuSearch(data, binSize, quantity, tabu_size, iterations);
//        simulatdAnnealing(data, binSize, quantity, iterations);
//    } else     if (method == "hillClimbing") {
//        hillClimbing(data, binSize, quantity, iterations);
//    } else     if (method == "hillClimbingrandom") {
//        hillClimbingrandom(data, binSize, quantity, iterations);
//    } else     if (method == "tabu") {
//        tabuSearch(data, binSize, quantity, tabu_size, iterations);
//    } else     if (method == "simulatedAnnealing") {
//        simulatdAnnealing(data, binSize, quantity, iterations);
//    }

    return 0;



}