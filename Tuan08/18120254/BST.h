#ifndef _BST_H_
#define _BST_H_
#include "Node.h"
using namespace std;
class BST
{
public:
	Node* root;
	BST();
	~BST();
	void destroy_tree(Node*);
	void insert(int);
	void inorder();
	void inorder(Node* temp);
	void remove(int);
	void search(int);
};
#endif

















