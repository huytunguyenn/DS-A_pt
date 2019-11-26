#pragma once
#include <iostream>
using namespace std;
class AVLNODE
{
public:
	int Key;
	int bal; // thuộc tính cho biết giá trị cân bằng,  0: cân bằng, 1: lệch trái, 2: lệch phải
	AVLNODE* pLeft;
	AVLNODE* pRight;
	AVLNODE();
	~AVLNODE();
};

