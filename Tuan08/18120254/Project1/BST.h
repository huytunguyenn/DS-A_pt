#ifndef _BST_H_
#define _BST_H_
#include "NODE.h"
class BST
{
public:
	NODE* root;
	BST();
	virtual ~BST();
	void DeleteTree(NODE*);
	void Insert(int );
	void Inorder(NODE*);
	void Inorder_trav();
	void Remove(int);
	NODE* Delete(NODE*);
	NODE* SearchNode(NODE*,int);
	NODE* Search(int);
	void SearchNodeAll(NODE*, int,bool&);
	void SearchAll(int,bool&);
};
#endif

