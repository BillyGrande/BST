#include <iostream>
#include "bst.hpp"

using namespace std;

int main(){
    BST* tree = new BST;

    tree->Insert(6);
    tree->Insert(4);
    tree->Insert(7);

    tree->Insert(3);
    tree->Insert(10);

    tree->PrintTree();
}
