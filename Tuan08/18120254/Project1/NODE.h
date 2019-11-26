#ifndef _NODE_H_
#define _NODE_H_
#include <iostream>
using namespace std;
class NODE
{
public:
	int key;
	NODE* left;
	NODE* right;
	NODE();
	virtual ~NODE();
};
#endif

