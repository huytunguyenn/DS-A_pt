#include "SvLIST.h"
SvLIST::~SvLIST(){
	for (SvNODE* p; !isEmpty();) {
		p = pHead->pNext;
		delete pHead;
		pHead = p;
	}
}
void SvLIST::addHead(SINHvien a) {
	pHead = new SvNODE(a,pHead);
	if (pTail == NULL)
		pTail = pHead;
}
void SvLIST::addTail(SINHvien a) {
	if (pTail != NULL) {		// neu danh sach khong rong
		pTail->pNext = new SvNODE(a);
		pTail = pTail->pNext;
	}
	else
		pHead = pTail = new SvNODE(a);
}
void SvLIST::print(SvNODE* p){ 
	if (p == NULL)
		return;
	else
		cout << p->info<<endl;
	print(p->pNext);
}
void SvLIST::readFile(string link) {
	ifstream fileInput(link);
	if (fileInput.fail()) {
		cout << "Khong the mo tap tin" << endl;
		return;
	}
	while (!fileInput.eof())
	{
		SINHvien temp;
		getline(fileInput, temp.MSSV, '\t');
		getline(fileInput, temp.HO, '\t');
		getline(fileInput, temp.TEN, '\t');
		getline(fileInput, temp.NGAYsinh, '\t');
		fileInput >> temp.DIEM;
		addTail(temp);
	}
}
SINHvien SvLIST::searchMaxDIEM() {
	float max = pHead->info.DIEM;
	SINHvien svmax;
	for (SvNODE*p = pHead; p != NULL; p = p->pNext) {
		if (p->info.DIEM > max) {
			max = p->info.DIEM;
			svmax = p->info;
		}
	}
	return svmax;
}
void SvLIST::Swap(SvNODE *x, SvNODE *y) {
	SINHvien temp = x->info;
	x->info = y->info;
	y->info = temp;
}
void SvLIST::bubbleSortDIEM() {
	int swapped;
	SvNODE *p;
	SvNODE *lptr = NULL;
	if (pHead == NULL)
		return;
	do{
		swapped = 0;
		p = pHead;
		while (p->pNext != lptr){
			if (p->info.DIEM > p->pNext->info.DIEM){
				Swap(p, p->pNext);
				swapped = 1;
			}
			p = p->pNext;
		}
		lptr = p;
	} while (swapped);
}
// function to find out middle element 
SvNODE* SvLIST::middle(SvNODE* start, SvNODE* last){
	if (start == NULL)
		return NULL;

	SvNODE* slow = start;
	SvNODE* fast = start->pNext;

	while (fast != last)
	{
		fast = fast->pNext;
		if (fast != last)
		{
			slow = slow->pNext;
			fast = fast->pNext;
		}
	}
	return slow;
}
// Function for implementing the Binary 
// Search on linked list 
SvNODE* SvLIST::binarySearchDIEM(float value)
{
	SvNODE* start = pHead;
	SvNODE* last = NULL;

	do
	{
		// Find middle 
		SvNODE* mid = middle(start,last);

		// If middle is empty 
		if (mid == NULL)
			return NULL;

		// If value is present at middle 
		if (mid->info.DIEM == value)
			return mid;

		// If value is more than mid 
		else if (mid->info.DIEM < value)
			start = mid->pNext;

		// If the value is less than mid. 
		else
			last = mid;

	} while (last == NULL ||
		last != start);

	// value not present 
	return NULL;
}
void SvLIST::writeFileMax(SINHvien sv) {

	ofstream fileOutput("MaxDiem.txt");
	if (fileOutput.fail()) {
		std::cout << "Ghi file that bai" << endl;
		return;
	}
	fileOutput << sv.MSSV << '\t' << sv.HO << '\t' << sv.TEN << '\t' << sv.NGAYsinh << '\t' << setprecision(9) << fixed << sv.DIEM << endl;
}
void SvLIST::writeFile(SvNODE* sv){

	ofstream fileOutput("ValueDiem.txt");
	if (fileOutput.fail()){
		std::cout << "Ghi file that bai" << endl;
		return;
	}
	fileOutput << sv->info.MSSV << '\t' << sv->info.HO << '\t' << sv->info.TEN << '\t' << sv->info.NGAYsinh << '\t' <<setprecision(9)<<fixed<< sv->info.DIEM << endl;
}
