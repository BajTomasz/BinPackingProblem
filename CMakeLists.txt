cmake_minimum_required(VERSION 3.20)
project(BinPackingProblem)

set(CMAKE_CXX_STANDARD 17)

add_executable(BinPackingProblem
        main.cpp
        dataGenerator.cpp
        hillClimbing.cpp
        howManyBin.cpp
        tabuSearch.cpp
        )
