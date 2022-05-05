#include "dataGenerator.h"

#include <vector>
#include <string>
#include <map>
#include <iostream>



int main(int argc, char **argv) {

    int minRange = 1;
    int maxRange = 15;
    int binSize = 20; //binSize > maxRange
    int quantity = 200;
    int data [quantity];
    dataGenerator(data, minRange, maxRange, quantity);
    //std::cout << howManyBin(data, binSize, quantity) << std::endl;
    tabuSearch(data, binSize, quantity);
    //std::cout << howManyBin(data, binSize, quantity) << std::endl;
    return 0;


    /*


auto wywolywacz = [](auto f, int n) {
    for (int i = 0; i < n; i++) {
        f(i);
    }
};
    using namespace std;
    map<string, string> params;
    vector<string> arguments(argv, argv + argc);
    string paramname = "";
    for (auto argument: arguments) {
        if ((argument.size() > 0) && (argument[0] == '-')) paramname = argument.substr(1);
        else params[paramname] = argument;
    }

    for (auto[name, value]: params) {
        cout << "Argument " << name << " ma wartosc " << value << endl;
    }
    for (auto kv: params) {
        cout << "Argument " << kv.first << " ma wartosc " << kv.second << endl;
    }

    auto fun = [&](int x){
    cout << "Hej, jestem funkcja! " << x
    << " a mam argumentow " << arguments.size() << endl;
    };
    wywolywacz(fun,3);
    wywolywacz([](int w){cout << w << endl;},3);
    arguments.clear();
    wywolywacz(fun,3);
//*/

}