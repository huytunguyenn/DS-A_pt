#include "SvLIST.h"
int main() {
	string link;
	cout << "Nhap link: ";
	cin >> link;
	SvLIST l;
	l.readFile(link);
	l.print(l.pHead);
	cout << "SINH VIEN DIEM CAO NHAT" << endl;
	SINHvien svmax=l.searchMaxDIEM();
	cout << svmax;
	l.writeFileMax(svmax);
	cout << "Ghi file thanh cong" << endl;
	cout << "SAP XEP DANH SACH THEO DIEM" << endl;
	l.bubbleSortDIEM();
	l.print(l.pHead);
	float diem;
	cout << "Nhap diem can tim: ";
	cin >> diem;
	if (l.binarySearchDIEM(diem) == NULL)
		cout << "Khong tim thay" << endl;
	else {
		SvNODE* found = l.binarySearchDIEM(diem);
		cout << found->info;
		l.writeFile(found);
		cout << "Ghi file thanh cong" << endl;
	}
	system("pause");
	return 0;
}