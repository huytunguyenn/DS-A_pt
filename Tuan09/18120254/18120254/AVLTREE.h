#pragma once
#include "AVLNODE.h"
class AVLTREE
{
public:
	AVLNODE* root;
	AVLTREE();
	~AVLTREE();
	void RemoveAll(AVLNODE*&);
	AVLNODE* CreateNode(int);
	void LeftRotate(AVLNODE*&);
	void RightRotate(AVLNODE*&);
	void LeftBalance(AVLNODE*&);
	void RightBalance(AVLNODE*&);
	int InsertNode(int);
	void Traverse(AVLNODE*);
	void LNR();
};

