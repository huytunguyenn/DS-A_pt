#include "Header.h"


float CvatNuoi::getCAN()
{
	return CAN;
}
string CvatNuoi::getTINHtrang()
{
	return TINHtrang;
}
void CvatNuoi::setCAN(float x)
{
	this->CAN = x;
}
void CvatNuoi::setTINHtrang(string x)
{
	this->TINHtrang = x;
}
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
ostream& operator<<(ostream& os, CvatNuoi p)
{
	os << "Ma so: "<<p.MAso<<endl;
	os << "Loai: " << p.LOAI << endl;
	os << "Can nang: " << p.CAN << endl;
	os << "Tinh trang: " << p.TINHtrang << endl;
	return os;
}
istream &operator>>(istream &is, CvatNuoi &p)
{
	cout << "Nhap ma: ";
	is>>p.MAso;
	cin.ignore(1);
	cout << "Nhap loai: ";
	is >> p.LOAI;
	cin.ignore(1);
	cout << "Nhap can nang: ";
	is >> p.CAN;
	cin.ignore(1);
	cout << "Nhap tinh trang: ";
	is >> p.TINHtrang;
	return is;
}


void List::Input(List& l, int n)
{
	CvatNuoi x;
	Init(l);
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap thong tin cho vat nuoi thu "<<i+1<<endl;
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
		cout << "Thong tin vat nuoi thu " << i++ <<endl<<p->data<< endl;
	}
}


