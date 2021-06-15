#include <iostream>
#include "bst.hpp"


Node* BST::Insert(Node* node, int key){
    if (node == nullptr){
        node = new Node;
        node->Key=key;
        node->Left=nullptr;
        node->Right=nullptr;
        node->Parent=nullptr;
    }
    else if (node->Key > key){
        node->Right = Insert(node->Right,key);
        node->Right->Parent=node;
    }
    else{
        node->Left = Insert(node->Left, key);
        node->Left->Parent=node;
    }

    return node;
}

void BST::Insert(int key){
    root = Insert(root,key);
}
