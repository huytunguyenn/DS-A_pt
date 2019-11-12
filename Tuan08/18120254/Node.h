#ifndef _NODE_H_
#define _NODE_H_
#include <iostream>
using namespace std;
class Node
{
public:
	int data;
	Node* left;
	Node* right;
	Node();
	~Node();
};
#endif
