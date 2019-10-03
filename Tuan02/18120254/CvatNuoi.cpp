#include "CvatNuoi.h"

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
ostream& operator<<(ostream& os, CvatNuoi p)
{
	os << "Ma so: " << p.MAso << endl;
	os << "Loai: " << p.LOAI << endl;
	os << "Can nang: " << p.CAN << endl;
	os << "Tinh trang: " << p.TINHtrang << endl;
	return os;
}
istream &operator >> (istream &is, CvatNuoi &p)
{
	cout << "Nhap ma: ";
	is >> p.MAso;
	cin.ignore(1);
	cout << "Nhap loai: ";
	is >> p.LOAI;
	cin.ignore(1);
	cout << "Nhap can nang: ";
	is >> p.CAN;
	cin.ignore(1);
	cout << "Nhap tinh trang (khoe hoac yeu): ";
	is >> p.TINHtrang;
	cin.ignore(1);
	return is;
}
