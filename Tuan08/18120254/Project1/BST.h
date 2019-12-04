#ifndef _BST_H_
#define _BST_H_
#include <iostream>
using namespace std;
class NODE{
public:
	int key;
	NODE* left;
	NODE* right;
	NODE() {
		key = 0;
		left = NULL;
		right = NULL;
	};
	virtual ~NODE() {};
};
class BST{
public:
	NODE* root;
	BST();
	virtual ~BST();
	void DeleteTree(NODE*);
	void Insert(int );
	void Inorder(NODE*);
	void Inorder_trav();
	void FindRemove(int);
	NODE* SearchNode(NODE*,int);
	NODE* Search(int);
	void SearchNodeAll(NODE*, int,bool&);
	void SearchAll(int,bool&);
};
#endif

