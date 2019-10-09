#ifndef _LIST_H_
#define _LIST_H
#include "SvNODE.h"
#include <fstream>
class SvLIST
{
public:
	SvNODE* pHead, *pTail;
	SvLIST() {
		pHead = pTail = NULL;
	}
	~SvLIST();
	int isEmpty() {
		return pHead == NULL;
	}
	void addHead(SINHvien);
	void addTail(SINHvien);
	void print(SvNODE*); // de quy
	void readFile(string);
	SINHvien searchMaxDIEM();
	void Swap(SvNODE *,SvNODE *); // swap data
	void bubbleSortDIEM();
	SvNODE* middle(SvNODE*, SvNODE*);
	SvNODE* binarySearchDIEM(float);
	void writeFile(SvNODE*);
	void writeFileMax(SINHvien );
};
#endif
