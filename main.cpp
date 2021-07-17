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

    tree->Vertices();
    tree->TreeHeight();

    tree->PrintTree();
    tree->Delete(3);
    tree->Delete(5);

    tree->PrintTree();

    tree->Insert(5);
    tree->PrintTree();

    tree->PrintRoot();
    tree->TreeHeight();

    BST* tree2 = new BST;

    tree2->Insert(10);
    tree2->Insert(7);
    tree2->Insert(6);
    tree2->Insert(8);
    tree2->Insert(5);
    tree2->Insert(9);
    tree2->Insert(11);

    tree2->Vertices();
    tree2->TreeHeight();
    tree2->Reconstruct(nullptr);
    tree2->PrintRoot();
}
