#include "AVLTREE.h"
int main(){
	AVLTREE tree;
	int Data;
	do{
		cout<<"Nhap vao du lieu, -1 de ket thuc: ";
		cin >> Data;
		if (Data == -1)
			break;
		tree.InsertNode(Data);
	} while (Data != -1);
	cout<<endl<<"Cay AVL vua tao:"<<endl;
	tree.LNR();
	system("pause");
	return 0;
}
