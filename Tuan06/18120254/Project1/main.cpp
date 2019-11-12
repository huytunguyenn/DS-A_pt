#include "SinhVien.h"
#include "Header.h"
int main() {
	ifstream FileVao;
	FileVao.open("DanhSachSV.txt",ios_base::in);
	if (FileVao.fail())
		cout << "Khong the mo tap tin" << endl;
	list<SinhVien>DSSV;
	ReadFile(FileVao, DSSV);
	vector<SinhVien>MSV;
	LinkedListtoArray(DSSV,MSV);
	// ham sort
	bubbleSort(MSV, MSV.size());
	DSSV.clear();
	ArraytoLinkedList(MSV, DSSV);
	XuatList(DSSV);
	FileVao.close();
	system("pause");
	return 0;
}