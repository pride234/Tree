//
// Created by LIFE on 13.05.2015.
//
#include "Tree.h"
#include <stdio.h>


//---------------------------------------------------------------------------

Tree::Tree() {
    root = 0;
}
//---------------------------------------------------------------------------

Tree::Tree(Tree &T) {
	Node* root = T.root;
	if (root->GetRight() != 0) CopyTree(root->GetRight());
	if (root->GetLeft()  != 0) CopyTree(root->GetLeft());
}
//---------------------------------------------------------------------------

Node* Tree::CopyTree(Node *tmp) {
	if (tmp == 0) return 0;
	Node* newnode = new Node;
	newnode->EnterValue(tmp->GetValue());
	newnode->SetLeft(CopyTree(tmp->GetLeft()));
	newnode->SetRight(CopyTree(tmp->GetRight()));
	return newnode;
}

//---------------------------------------------------------------------------

bool Tree::AddNode(int k) {
    if (root == 0) {
        Node *node = new Node;
        node->EnterValue(k);
        root = node;
        return true;
    }
    if (root->GetValue() <= k) {
        if (root->GetRight()) {
            return Add(root->GetRight(), k);
        }
        else {
            Node* node = new Node;
            node->EnterValue(k);
			root->SetRight (node);
            return 1;
        }
    }
    else if (root->GetValue() > k){
        if (root->GetLeft()) {
			Node* node = root->GetLeft();
            return Add(node, k);
        }
        else{
            	Node* node = new Node;
				node->EnterValue(k);
				root->SetLeft(node);
				return 1;
			}
		}
}
//---------------------------------------------------------------------------

bool Tree::Add(Node *tmp, int k) {
		if (tmp->GetValue() <= k) {
				if (tmp->GetRight()) {
						return Add(tmp->GetRight(), k);
				}
				else {
						Node *node = new Node;
						node->EnterValue(k);
						tmp->SetRight(node);
						return 1;
				}
		}
		else if (tmp->GetValue() > k) {
				if (tmp->GetLeft()) {
						return Add(tmp->GetLeft(), k);
				}
				else {
						Node *node = new Node;
						node->EnterValue(k);
						tmp->SetLeft(node);
						return 1;
				}
		}
}
//---------------------------------------------------------------------------
Node* Tree::Search(int K) {
	if (root->GetValue() == K) return root;
	if (root->GetValue() > K) {
		if (root->GetRight() != 0) {
			return search(root->GetRight(), K);
		}
		else return 0;
	}
	else {
		if (root->GetLeft() != 0) {
			return search(root->GetLeft(), K);
		}
		else return 0;
	}
}
//---------------------------------------------------------------------------
Node* Tree::search(Node* tmp, int v) {
	if (tmp->GetValue() == v) return tmp;
	if (tmp->GetValue() > v) {
		if (tmp->GetRight() != 0) {
			return search(tmp->GetRight(), v);
		}
		else return 0;
	}
	else {
		if (tmp->GetLeft() != 0) {
			return search(tmp->GetLeft(), v);
		}
		else return 0;
	}
}
//---------------------------------------------------------------------------
void Tree::DelNode(int K) {
	Node* tmp = Search(K);
	if (tmp == 0) {
		printf("There's no NOde with your number");
		return;
	}
	if (tmp->GetRight() != 0) {
		KillChildren(tmp->GetRight());

	}
	if (tmp->GetLeft() != 0){
		KillChildren(tmp->GetLeft());
	}
	delete tmp;
}
//---------------------------------------------------------------------------
void Tree::KillChildren(Node *tmp) {
	if (tmp->GetRight() != 0) KillChildren(tmp->GetRight());
	if (tmp->GetLeft()  != 0) KillChildren(tmp->GetLeft());
	delete tmp;
}
//---------------------------------------------------------------------------
Tree::~Tree() {
	KillChildren(root);
}
Tree &Tree::operator=(const Tree &T) {
	KillChildren(root);
	root = T.root;
	if (root->GetRight() != 0) CopyTree(root->GetRight());
	if (root->GetLeft()  != 0) CopyTree(root->GetLeft());
	return *this;
}

void print_Tree(Node* p, int level, ostream& s)
{
	if(p)
	{
		print_Tree(p->GetLeft(),level + 1, s);
		for(int i = 0;i< level;i++) cout << " ";
		s <<  p->GetValue() << endl;
		print_Tree(p->GetRight(), level + 1, s);
	}
}
ostream& operator<<(ostream &s, const Tree &T) {
	print_Tree(T.root, 0, s);
	return s;
}

