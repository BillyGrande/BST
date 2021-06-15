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
};

class BST {
    private:
        Node* root = nullptr;

    protected:
        Node* Insert(Node* node, int key);


    public:
        BST(Node* node);

        void Insert(int key);
};


#endif
