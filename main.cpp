#include <iostream>
#include <vector>
#include "BEpsilon.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    BEpsilonTree<int,int,3> tree;
    tree.insert(1,1);
    tree.insert(2,2);
    tree.insert(3,3);
    tree.insert(4,4);
    vector<int> results = tree.rangeQuery(1,2);

    for(int i=0 ;i<results.size();i++){
        cout << "value: " << results[i] << " ";
    }
    return 0;
}