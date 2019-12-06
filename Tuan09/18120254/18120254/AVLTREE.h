#ifndef _AVL_H_
#define _AVL_H_
#include <iostream>
using namespace std;
class AVLNODE{
public:
	int key;
	int height;
	AVLNODE* left;
	AVLNODE* right;
	AVLNODE() {};
	~AVLNODE() {};
};

class AVLTREE{
public:
	AVLNODE* root;
	AVLTREE();
	~AVLTREE();
	void RemoveAll(AVLNODE*);
	AVLNODE* CreateNode(int);
	AVLNODE*  LeftRotate(AVLNODE*);
	AVLNODE*  RightRotate(AVLNODE*);
	AVLNODE* Insert(AVLNODE* node, int key);
	void InsertNode(int key);
	void Traverse(AVLNODE*);
	void LNR();
};
#endif
