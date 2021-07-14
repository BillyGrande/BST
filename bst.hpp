#ifndef BST_hpp
#define BST_hpp

#include <iostream>

class Node{
    public:
        int Key;
        Node* Left;
        Node* Right;
        Node* Parent;
        int Height;
        bool deleted = false;
};

class BST {
    private:
        Node* root = nullptr;

    protected:
        Node* Insert(Node* node, int key);
        void PrintTree(Node* node);
        Node* Delete(Node* node, int key);

    public:

        void PrintTree();
        void Insert(int key);
        void Delete(int key);
        void PrintRoot();
};


#endif
