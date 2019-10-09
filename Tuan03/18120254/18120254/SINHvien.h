#ifndef _SINHVIEN_H_
#define _SINHVIEN_H_
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class SINHvien
{
public:
	string MSSV;
	string HO;
	string TEN;
	string NGAYsinh;
	float DIEM;
	SINHvien();
	friend class SvNODE;
	friend ostream& operator<<(ostream&,SINHvien);
	friend istream& operator>>(istream&, SINHvien&);
	
};
#endif

