# BinPackingProblem
https://en.wikipedia.org/wiki/Bin_packing_problem

It is a project with a set of metaheuristic algorithms for a BPP solution

Scripts:

To download project:

```git clone https://github.com/tomeasz/BinPackingProblem.git```

To build project and prepare structure

```
cd BinPackingProblem/scripts
./build.sh
```

To generate new data

```./generateData.sh```

To start all algorithms

```./startup.sh```

To start single algorithms

```./../build/BinPackingProblem -fname ../data/data.csv -method {method}```

You can use this methods:
- hillClimbing
- hillClimbingRandom
- tabuSearch
- simulatedAnnealing
- geneticAlgorithm

Other arguments you can use for:

```-argument value``` - syntax

|Argument | Type | Default | Describe|
|---------|------|---------|---------|
|- iterations | \<int> | 1000 | number of iteration in loops **all method**|
|- binSize | \<int> | 15 | just size of bin **all method**|
|- tabuSize | \<int> | 100 | for list size in **tabu search**|
|- uniformRealDistributionIsSet | \<bool> | false | change normal to real dist in **simulatedAnnealing**|
|- populationSize | \<int> | 400 | **in genetic algorithm**|
|- pointCrossover | \<bool> | true | true-onePointCrossover / false - twoPointCrossover **in genetic algorithm**|
|- mutationMethod | \<bool> | true | true-swapMethod / false - shuffleMethod **in genetic algorithm**|
|- printProgress | \<bool> | false |true-show best solution in each iteration / false show best solution -  **in genetic algorithm**|
|- quantity | \<int> | 500 | how long should **generate data**|
|- generateData | \<bool> | false | **generate data**|
