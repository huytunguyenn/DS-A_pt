#ifndef _NODE_H_
#define _NODE_H_	
#include <iostream>
#include <string>
#include <list>
using namespace std;
class Node{
public:
	string LABEL;
	list<Node*> LISTn;
	bool CHECKED;
	Node(string);
};
#endif

