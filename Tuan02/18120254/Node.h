#ifndef _NODE_H_
#define _NODE_H_
#include"CvatNuoi.h"

class Node {
	CvatNuoi data;
	struct Node* pNext;
	friend class List;
	Node& operator=(Node*);
};
#endif
