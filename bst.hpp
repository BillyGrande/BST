#ifndef BST_hpp
#define BST_hpp

#include <iostream>
#include<vector>

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
                //void Reconstruct(Node* node, std::vector<Node*>* nodes);
                void BuildVector(Node* node, std::vector<Node*>* nodes);
                void BuildTree(BST* tree, std::vector<Node*>* nodes, int start, int end);
                int Height(Node* node);
                int Max(int a, int b);
                void Balance(Node* node);
                int Vertices(Node* node);
                int RealVertices(Node* node);

        public:

                void PrintTree();
                void Insert(int key);
                void Delete(int key);
                void PrintRoot();
                //Recounstruct needs to retun root node!
                void Reconstruct(Node* node);
                void TreeHeight();
                void Vertices();
};


#endif
