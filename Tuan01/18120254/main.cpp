#include "Header.h"
int main()
{
	List l;
	int n;
	cout << "Nhap so dong vat ban muon tao: ";
	cin>>n;
	l.Input(l, n);
	l.Output(l);
	cout << "Them 1 vat nuoi vao danh sach";
	CvatNuoi p;
	cout <<"Nhap thong tin cho dong vat" << endl;
	cin >> p;
	Node* q=l.getNode(p);
	l.AddTail(l,q);
	return 0;
}