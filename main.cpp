#include <iostream>
#include <vector>
#include "BEpsilon.h"

void printVector(vector<int> vector) {
    for (int i = 0; i < vector.size(); i++) {
        cout << "value: " << vector[i] << " ";
    }
    cout << endl;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    BEpsilonTree<int, int, 3> tree;
    tree.insert(1, 1);
    tree.insert(2, 2);
    tree.insert(3, 3);
    tree.insert(4, 4);
    printVector(tree.rangeQuery(1, 1));
    printVector(tree.rangeQuery(1, 2));
    printVector(tree.rangeQuery(1, 3));
    printVector(tree.rangeQuery(1, 4));
    printVector(tree.rangeQuery(2, 2));
    printVector(tree.rangeQuery(2, 3));
    printVector(tree.rangeQuery(2, 4));
    printVector(tree.rangeQuery(3, 3));
    printVector(tree.rangeQuery(3, 4));
    printVector(tree.rangeQuery(4, 4));
    return 0;
}

