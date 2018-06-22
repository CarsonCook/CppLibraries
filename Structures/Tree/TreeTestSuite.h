#include <iostream>
#include <fstream>
#include "Node/BinaryNode.h"
#include "Tree.h"

using namespace std;

ofstream testOutput;

void BinaryNodeTestSuite() {
    BinaryNode<int> root(5);
    BinaryNode<int> left(2);
    BinaryNode<int> right(6);
    root.setLeft(&left);
    root.setRight(&right);
    testOutput << "Should see addresses of root then left then right, with data 5, 2, 6:" << endl;
    testOutput << root << endl << left << endl << right << endl;
}

void TreeTestSuite() {

}