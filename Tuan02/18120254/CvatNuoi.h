#ifndef  _CVATNUOI_H_
#define _CVATNUOI_H_
#include <iostream>
#include <string>
using namespace std;

class CvatNuoi {
private:
	float CAN;
	string TINHtrang;
public:
	string MAso;
	string LOAI;
	CvatNuoi()
	{
		this->CAN = 0;
	}
	float getCAN();
	string getTINHtrang();
	void setCAN(float);
	void setTINHtrang(string);
	friend ostream& operator<<(ostream&, CvatNuoi);
	friend istream& operator >> (istream&, CvatNuoi&);
	friend class List;
};
#endif