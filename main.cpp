#include <iostream>
#include "bst.hpp"

using namespace std;

int main(){
    BST* tree = new BST;


    tree->Insert(7);
    tree->Insert(5);
    tree->Insert(4);
    tree->Insert(5);
    tree->Insert(6);
    tree->Insert(3);
    tree->Insert(5);
    tree->Insert(10);

    tree->PrintTree();
    tree->Delete(3);
    tree->Delete(5);

    tree->PrintTree();

    tree->Insert(5);
    tree->PrintTree();

    tree->PrintRoot();
}
