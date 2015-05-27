//
// Created by LIFE on 13.05.2015.
//

#ifndef LAB2_TREE_H
#define LAB2_TREE_H
#include "Node.h"
#include <iostream>
using namespace std;


class Tree {
    private:
        Node* root;
    public:
        Tree();
        Tree (int c)    {Tree* T = new Tree [c];}
        Tree(Tree& T);
        Node* CopyTree (Node* tmp);
        bool AddNode (int k);
        bool Add (Node* tmp, int k);
        Node* Search(int K);
	    Node* search (Node* tmp, int v);
        void DelNode (int K);
        void KillChildren (Node* tmp);
        Tree& operator = (const Tree& T);
        friend ostream& operator << (ostream& s, const Tree& T);
        friend istream& operator >> (istream& s, Tree& T);
    ~Tree();

};

void print_Tree(Node* p, int level, ostream& s);

#endif //LAB2_TREE_H
