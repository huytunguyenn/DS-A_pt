#ifndef _NODE_H_
#define _NODE_H_
#include "SINHvien.h"
class SvNODE
{
public:
	SINHvien info;
	SvNODE* pNext;
	SvNODE();
	SvNODE(SINHvien a, SvNODE* ptr = NULL) 
	{
		info = a;
		pNext = ptr;
	}
	friend class SvLIST;
};

#endif