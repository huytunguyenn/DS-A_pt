#pragma once
#include <iostream>
#include <list>
using namespace std;
class Cnode
{
public:
	string LABEL;
	list<Cnode*> LISTn;
	bool CHECKED;
	Cnode(string);
};

