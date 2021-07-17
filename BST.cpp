#include <iostream>
#include "bst.hpp"
#include <vector>

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

void BST::BuildVector(Node* node,std::vector<Node*>* nodes){


    if (node == nullptr){
        return;
    }

    BuildVector(node->Left, nodes);
    nodes->push_back(node);
    BuildVector(node->Right, nodes);

}

void BST::BuildTree(BST* tree, std::vector<Node*>* nodes, int start, int end){

    if (start>end){
        return;
    }

    std::vector<Node*> cool = *nodes;

    int mid = (start+end)/2;
    int data = cool[mid]->Key;
    tree->Insert(data);


    BuildTree(tree, nodes, start, mid-1);
    BuildTree(tree, nodes, mid+1, end);
}

void BST::Reconstruct(Node* node){

    std::vector<Node*> nodes;
    if (node == nullptr){
        BuildVector(root, &nodes);
    }else{
        BuildVector(node, &nodes);
    }

    BST* temp_tree = new BST;
    std::cout << "VECTOR SIZE " << nodes.size() << std::endl;
    BuildTree(temp_tree, &nodes, 0, nodes.size()-1);


    // for(int i=0 ; i<nodes.size(); ++i){
    //     std::cout << nodes[i]->Key << " ";
    // }

    temp_tree->PrintRoot();
}

int BST::Max(int a, int b){
    if (a > b){
        return a;
    }else{
        return b;
    }
}

int BST::Height(Node * node){
    if (node == nullptr){
        return 0;
    }

    int rh = Height(node->Right);
    int lh = Height(node->Left);

    rh = rh + 1;
    lh = lh + 1;

    return Max(rh,lh);

}

void BST::TreeHeight(){
    std::cout << "Tree Height is " << Height(root) << std::endl;
}

int BST::Vertices(Node* node){

    // int count = 0;
    // auto next = node->Left;
    // while(next != nullptr){
    //     int a = Vertices(next->Right);
    //     count = count + a + 1;
    //     next = next->Left;
    // }

    // next = node->Right;
    // while(next != nullptr){
    //     int b = Vertices(next->Left);
    //     count = count + b + 1;
    //     next = next->Right;
    // }

    // return count+1;

    if (node == nullptr){
        return -1;
    }

    int lt = Vertices(node->Left);
    lt = lt + 1;
    int rt = Vertices(node->Right);
    rt = rt + 1;
    return lt+rt;
}

int BST::RealVertices(Node *node){
    return Vertices(node) + 1;
}

void BST::Vertices(){
    std::cout << "VERTICES " << RealVertices(root) << std::endl;
}
void BST::Balance(Node* node){
    if (Height(node)<3){
        return;
    }

    //Incomplete
    //
}
