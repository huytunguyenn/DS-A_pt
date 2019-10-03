#include "List.h"

void List::Init(List& l)
{
	l.pHead = l.pTail = NULL;
}
Node* List::getNode(CvatNuoi x)
{
	Node* p = new Node;
	if (p == NULL)
		return NULL;
	p->data = x;
	p->pNext = NULL;
	return p;
}
void List::AddHead(List& l, Node* p)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
		p->pNext = NULL;
	}
	else
	{
		p->pNext = l.pHead;
		l.pHead = p;
	}
}
void List::AddTail(List& l, Node* p)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
		p->pNext = NULL;
	}
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}
void List::Input(List& l, int n)
{
	CvatNuoi x;
	Init(l);
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap thong tin cho vat nuoi thu " << i + 1 << endl;
		cin >> x;
		Node* p = getNode(x);
		AddTail(l, p);
	}
}

void List::Output(List l)
{
	int i = 1;
	for (Node* p = l.pHead; p != NULL; p = p->pNext)
	{
		cout << "Thong tin vat nuoi thu " << i++ << endl << p->data << endl;
	}
}


void List::DelHead()
{
	if (pHead == NULL) {
		cout << "Danh sach rong" << endl;
	}
	else {
		pHead = pHead->pNext;
	}
}

void List::DelTail()
{
	Node* p = pHead;
	while (p->pNext->pNext != NULL)
	{
		p = p->pNext;
	}
	p->pNext = NULL;
}

void List::DelNode(int position)
{
	if (position == 0 || pHead == NULL)
	{
		DelHead(); // Nếu vị trí chèn là 0, tức là thêm vào đầu
	}
	else
	{
		int k = 1;
		Node* p = pHead;
		while (p->pNext->pNext != NULL && k != position)
		{
			p = p->pNext;
			++k;
		}
		if (k != position)
			cout << "Vi tri xoa vuot qua vi tri cuoi cung" << endl;
		else
			p->pNext = p->pNext->pNext;
	}

}
int List::SearchMAso(string ms)
{
	int position = 0;
	for (Node* p = pHead; p != NULL; p = p->pNext)
	{
		if (p->data.MAso == ms)
			return position;
		++position;
	}
	return -1;
}
void List::DelByMAso(string ms)
{
	int position = SearchMAso(ms);
	while (position != -1)
	{
		DelNode(position);
		position = SearchMAso(ms);
	}
}

void List::OutputLOAI(string loai)
{
	for (Node* p = pHead; p != NULL; p = p->pNext)
	{
		if (p->data.LOAI == loai)
		{
			cout << "Ma so: " << p->data.MAso << endl;
			cout << "Loai: " << p->data.LOAI << endl;
			cout << "Can nang: " << p->data.CAN << endl;
			cout << "Tinh trang: " << p->data.TINHtrang << endl;
		}
	}
}
void List::DatHang(string loai, float kg)
{
	float stored = 0;
	for (Node* p = pHead; p != NULL; p = p->pNext)
	{
		if (p->data.LOAI == loai && p->data.TINHtrang == "khoe")
		{
			stored += p->data.CAN;
			if (stored > kg)
			{
				stored -= p->data.CAN;
				break;
			}
			else
				cout << p->data;
		}
	}
}

void List::bubbleSortCAN()
{
	int swapped;
	struct Node *p;
	struct Node *lp = NULL;

	if (pHead == NULL)
		return;
	do
	{
		swapped = 0;
		p = pHead;

		while (p->pNext != lp)
		{
			if (p->data.CAN > p->pNext->data.CAN)
			{
				Swap(p, p->pNext);
				swapped = 1;
			}
			p = p->pNext;
		}
		lp = p;
	} while (swapped);
}

void List::Swap(Node *a, Node *b)
{
	Node* temp;
	temp = a;
	a = b;
	b = temp;
}
