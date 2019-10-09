#include "SINHvien.h"
SINHvien::SINHvien()
{
	MSSV = '\0';
	HO = '\0';
	TEN = '\0';
	NGAYsinh = '\0';
	DIEM = 0;
}
ostream& operator<<(ostream& os,SINHvien a)
{
	cout << "MSSV: "<<a.MSSV<<endl;
	cout << "Ho: "<<a.HO<<endl;
	cout << "Ten: "<<a.TEN<<endl;
	cout << "Ngay sinh: "<<a.NGAYsinh<<endl;
	cout << "Diem: "<< setprecision(9) << fixed <<a.DIEM<<endl;
	return os;
}
istream& operator>>(istream& is, SINHvien& a)
{
	cout << "MSSV: ";
	cin >> a.MSSV;
	cin.ignore(1);
	cout << "Ho: ";
	cin >> a.HO;
	cin.ignore(1);
	cout << "Ten: ";
	cin >> a.TEN;
	cin.ignore(1);
	cout << "Ngay sinh: ";
	cin >> a.NGAYsinh;
	cout << "Diem: ";
	cin >> a.DIEM;
	return is;
}


