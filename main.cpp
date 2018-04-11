//============================================================================
// Name        : HashSet.cpp
// Author      : Vijay
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <unordered_set>
#include <functional>
#include "src/HashSet.h"
using namespace std;
using stringset = std::unordered_set<std::string>;

int main(int argc, char **argv) {
    HashSet<int> hset;
    cout<< argv[1];
    for(auto i = 0 ; i< stoi(argv[1]); i++)
    hset.insert(i);

    hset.print();

    hset.insert(40);

    hset.print();

    hset.insert(41);

    hset.print();

      return 0;
}
