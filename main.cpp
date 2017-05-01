#include <iostream>
#include "BEpsilon.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    BEpsilonTree<int,int,5> tree;
    tree.insert(1,2);
    return 0;
}