#ifndef _LIST_H_
#define _LIST_H_
#include "CvatNuoi.h"
#include "Node.h"

class List {
	Node *pHead;
	Node *pTail;
	int n;
public:
	List()
	{
		pHead = pTail = NULL;
		n = 0;
	}
	void Init(List& l);
	Node* getNode(CvatNuoi);
	void AddHead(List&, Node*);
	void AddTail(List&, Node*);
	void Input(List&, int);
	void Output(List);
	void DelHead();
	void DelTail();
	void DelNode(int);
	int SearchMAso(string);
	void DelByMAso(string);
	void OutputLOAI(string);
	void DatHang(string, float);
	void bubbleSortCAN();
	void Swap(Node *, Node *);
};
#endif
