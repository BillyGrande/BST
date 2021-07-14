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
    else if (node->Key < key){
        node->Right = Insert(node->Right,key);
        node->Right->Parent=node;
    }
    else if (node->Key > key){
        node->Left = Insert(node->Left, key);
        node->Left->Parent=node;
    }
    else{
        if (node->deleted) node->deleted=false;
    }
    return node;
}

void BST::Insert(int key){
    root = Insert(root,key);
}

void BST::PrintTree(Node * node)
{
    // Stop printing if no node found
    if(node == nullptr)
        return;

    // Get the smallest key first
    // which is in the left subtree
    PrintTree(node->Left);

    // Print the key
    std::cout << node->Key;

    if (node->deleted)
        std::cout << "X";

    std::cout << " ";

    // Continue to the greatest key
    // which is in the right subtree
    PrintTree(node->Right);
}

void BST::PrintTree()
{
    // Traverse the BST
    // from root node
    // then print all keys
    PrintTree(root);
    std::cout << std::endl;
}

Node* BST::Delete(Node* node, int key){

    if (node == nullptr){
        return nullptr;
    }

    if(node->Key == key){
        if (node->Left == nullptr && node->Right==nullptr){
            node = nullptr;
        }
        else if (node->Left == nullptr && node->Right != nullptr){
            node->Right->Parent=node->Parent;
            node = node->Right;
        }
        else if (node->Right==nullptr && node->Left != nullptr){
            node->Left->Parent=node->Parent;
            node = node->Left;
        }
        else{
            node->deleted = true;
        }
    }
    else if (node->Key < key){
        node->Right = Delete(node->Right, key);
    }else{
        node->Left = Delete(node->Left, key);
    }

    return node;
}

void BST::Delete(int key){
    root = Delete(root,key);
}

void BST::PrintRoot(){
    std::cout << root->Key << std::endl;
}
