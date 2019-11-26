#ifndef _NODE_H_
#define _NODE_H_
#include <iostream>
#include <string>
using namespace std;
class Node
{
public:
	string MaNode;
	Node* pNext1;
	Node* pNext2;
	Node* pNext3;
	Node* pNext4;
	Node* pNext5;// quy dinh duong di, neu do thi nhieu hon thi xay dung con tro
	Node() {
		pNext1 = NULL;
		pNext2 = NULL;
		pNext3 = NULL;
		pNext4 = NULL;
		pNext5 = NULL;
	};
};
#endif

