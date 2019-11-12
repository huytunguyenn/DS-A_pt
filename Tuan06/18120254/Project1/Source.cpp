#include "Header.h"
void ReadSV(ifstream &FileVao, SinhVien &Sv) {
	getline(FileVao, Sv.MSSV, '\t');
	getline(FileVao, Sv.Ho, '\t');
	getline(FileVao, Sv.Ten, '\t');
	string DiemTam;
	getline(FileVao, DiemTam, '\n');
	for (int i = 0; i < DiemTam.length(); i++) {
		if (DiemTam[i] == ',')
			DiemTam[i] = '.';
	}
	Sv.Diem = atof(DiemTam.c_str());
}
void ReadFile(ifstream &FileVao, list<SinhVien>&DSSV) {
	while (FileVao.eof() == false) {
		SinhVien SvTam;
		ReadSV(FileVao, SvTam);
		DSSV.push_back(SvTam);
	}
}
void XuatList(list<SinhVien>DSSV) {
	list<SinhVien>::iterator it;
	for (it = DSSV.begin(); it != DSSV.end(); it++) {
		cout << "MSSV: " << it->MSSV << endl;
		cout << "Ho: " << it->Ho << endl;
		cout << "Ten: " << it->Ten << endl;
		cout << "Diem: " << it->Diem << endl;
	}
}
void LinkedListtoArray(list<SinhVien>DSSV, vector<SinhVien>&MSV) {
	list<SinhVien>::iterator it;
	for (it = DSSV.begin(); it != DSSV.end(); it++) {
		MSV.push_back(*it);
	}
}
void ArraytoLinkedList(vector<SinhVien>&MSV, list<SinhVien>&DSSV) {
	for (int i = 0; i < MSV.size(); i++) {
		DSSV.push_back(MSV[i]);
	}
}
//bubble sort
void bubbleSort(vector<SinhVien>&Mang, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i; j < n; j++) {
			if (Mang[j].Diem < Mang[i].Diem) {
				SinhVien Tam;
				Tam.Diem = Mang[i].Diem;
				Tam.Ho = Mang[i].Ho;
				Tam.MSSV = Mang[i].MSSV;
				Tam.Ten = Mang[i].Ten;
				Mang[i].Diem = Mang[j].Diem;
				Mang[i].Ho = Mang[j].Ho;
				Mang[i].MSSV = Mang[j].MSSV;
				Mang[i].Ten = Mang[j].Ten;
				Mang[j].Diem = Tam.Diem;
				Mang[j].Ho = Tam.Ho;
				Mang[j].MSSV = Tam.MSSV;
				Mang[j].Ten = Tam.Ten;
			}
		}
	}
}
//flash sort
void insertionSort(vector<SinhVien>&Mang, int n){
	int i, j;
	float key;
	for (i = 1; i < n; i++)
	{
		key = Mang[i].Diem;
		j = i - 1;
		while (j >= 0 && Mang[j].Diem > key)
		{
			Mang[j + 1] =Mang[j];
			j = j - 1;
		}
		Mang[j + 1].Diem = key;
	}
}
void flashSort(vector<SinhVien>&Mang, int length){
	if (length == 0) return;

	int m = (int)((0.2 * length) + 2);

	float min, max;
	int maxIndex;
	min = max = Mang[0].Diem;
	maxIndex = 0;

	for (int i = 1; i < length - 1; i += 2)
	{
		float small;
		float big;
		int bigIndex;

		if (Mang[i].Diem < Mang[i + 1].Diem)
		{
			small = Mang[i].Diem;
			big = Mang[i + 1].Diem;
			bigIndex = i + 1;
		}
		else
		{
			big = Mang[i].Diem;
			bigIndex = i;
			small = Mang[i + 1].Diem;
		}

		if (big > max)
		{
			max = big;
			maxIndex = bigIndex;
		}

		if (small < min)
		{
			min = small;
		}
	}

	if (Mang[length - 1].Diem < min)
	{
		min = Mang[length - 1].Diem;
	}
	else if (Mang[length - 1].Diem > max)
	{
		max = Mang[length - 1].Diem;
		maxIndex = length - 1;
	}

	if (max == min)
	{
		return;
	}

	vector<SinhVien>L;

	for (int t = 1; t <= m; t++)
	{
		L[t].Diem = 0;
	}

	double c = (m - 1.0) / (max - min);
	int K;
	for (int h = 0; h < length; h++)
	{
		K = ((int)((Mang[h].Diem - min) * c)) + 1;
		L[K].Diem += 1;
	}
	for (K = 2; K <= m; K++)
	{
		L[K].Diem = L[K].Diem + L[K - 1].Diem;
	}

	float temp = Mang[maxIndex].Diem;
	Mang[maxIndex] = Mang[0];
	Mang[0].Diem = temp;

	int j = 0;
	K = m;
	int numMoves = 0;

	while (numMoves < length)
	{
		while (j >= L[K].Diem)
		{
			j++;
			K = ((int)((Mang[j].Diem - min) * c)) + 1;
		}

		float evicted = Mang[j].Diem;

		while (j < L[K].Diem)
		{
			K = ((int)((evicted - min) * c)) + 1;

			float location = L[K].Diem - 1;

			float temp = Mang[location].Diem;
			Mang[location].Diem = evicted;
			evicted = temp;

			L[K].Diem -= 1;
			numMoves++;
		}
	}

	int threshold = (int)(1.25 * ((length / m) + 1));
	const int minElements = 30;

	for (K = m - 1; K >= 1; K--)
	{
		float classSize = L[K + 1].Diem - L[K].Diem;

		if (classSize > threshold && classSize > minElements)
		{

			flashSort(Mang, classSize);
		}
		else
		{
			if (classSize > 1)
			{
				insertionSort(Mang, classSize);
			}
		}
	}
}
//merge sort
void merge(vector<SinhVien>&Mang, int l, int m, int r){
	// Gộp hai mảng con Mang[l...m] và Mang[m+1..r]
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	/* Tạo các mảng tạm */
	vector<SinhVien>L;
	vector<SinhVien>R;

	/* Copy dữ liệu sang các mảng tạm */
	for (i = 0; i < n1; i++)
		L[i] = Mang[l + i];
	for (j = 0; j < n2; j++)
		R[j] = Mang[m + 1 + j];

	/* Gộp hai mảng tạm vừa rồi vào mảng Mang*/
	i = 0; // Khởi tạo chỉ số bắt đầu của mảng con đầu tiên
	j = 0; // Khởi tạo chỉ số bắt đầu của mảng con thứ hai
	k = l; // IKhởi tạo chỉ số bắt đầu của mảng lưu kết quả
	while (i < n1 && j < n2)
	{
		if (L[i].Diem <= R[j].Diem)
		{
			Mang[k] = L[i];
			i++;
		}
		else
		{
			Mang[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy các phần tử còn lại của mảng L vào Mang nếu có */
	while (i < n1)
	{
		Mang[k] = L[i];
		i++;
		k++;
	}

	/* Copy các phần tử còn lại của mảng R vào Mang nếu có */
	while (j < n2)
	{
		Mang[k] = R[j];
		j++;
		k++;
	}
}
/* l là chỉ số trái và r là chỉ số phải của mảng cần được sắp xếp */
void mergeSort(vector<SinhVien>&Mang, int l, int r){
	if (l < r)
	{
		// Tương tự (l+r)/2, nhưng cách này tránh tràn số khi l và r lớn
		int m = l + (r - l) / 2;

		// Gọi hàm đệ quy tiếp tục chia đôi từng nửa mảng
		mergeSort(Mang, l, m);
		mergeSort(Mang, m + 1, r);

		merge(Mang, l, m, r);
	}
}
//quick sort
void quickSort(vector<SinhVien>&Mang, int l, int r){
	srand(time(NULL));  //khoi tao tham so ham rand()
	int key = Mang[l + rand() % (r - l + 1)].Diem;  //lay khoa la gia tri ngau nhien tu a[l] -> a[r]
	//int key = Mang[(l+r)/2];
	int i = l, j = r;

	while (i <= j)
	{
		while (Mang[i].Diem < key) i++;       // tim phan tu ben trai ma >=key
		while (Mang[j].Diem > key) j--;       // tim phan tu ben trai ma <=key
		if (i <= j)
		{
			if (i < j)  // doi cho 2 phan tu [i], [j].
			{
				SinhVien Tam;
				Tam.Diem = Mang[i].Diem;
				Tam.Ho = Mang[i].Ho;
				Tam.MSSV = Mang[i].MSSV;
				Tam.Ten = Mang[i].Ten;
				Mang[i].Diem = Mang[j].Diem;
				Mang[i].Ho = Mang[j].Ho;
				Mang[i].MSSV = Mang[j].MSSV;
				Mang[i].Ten = Mang[j].Ten;
				Mang[j].Diem = Tam.Diem;
				Mang[j].Ho = Tam.Ho;
				Mang[j].MSSV = Tam.MSSV;
				Mang[j].Ten = Tam.Ten; }
			i++;
			j--;
		}
	}
	//bay gio ta co 1 mang : a[l]....a[j]..a[i]...a[r]
	if (l < j) quickSort(Mang, l, j);   // lam lai voi mang a[l]....a[j]
	if (i < r) quickSort(Mang, i, r); // lam lai voi mang a[i]....a[r]
}
//radix sort
float getMax(vector<SinhVien>&Mang, int n) {
	int LonNhat = Mang[0].Diem;
	for (int i = 1; i < n; i++)
		if (Mang[i].Diem > LonNhat)
			LonNhat = Mang[i].Diem;
	return LonNhat;
}
void countSort(vector<SinhVien>&Mang, int n, int exp){
	vector<SinhVien>output;
	int i;
	vector<SinhVien>count;

	for (i = 0; i < n; i++)
		count[(((int)Mang[i].Diem / exp) % 10)].Diem++;

	for (i = 1; i < 10; i++)
		count[i].Diem += count[i - 1].Diem;

	for (i = n - 1; i >= 0; i--){
		output[count[((int)Mang[i].Diem / exp) % 10].Diem - 1].Diem = Mang[i].Diem;
		count[((int)Mang[i].Diem / exp) % 10].Diem--;
	}

	for (i = 0; i < n; i++)
		Mang[i] = output[i];

}
void radixSort(vector<SinhVien>&Mang, int n) {

	float m = getMax(Mang, n);

	for (int exp = 1; m / exp > 0; exp *= 10)
		countSort(Mang, n, exp);
}
//selection sort
void selectionSort(vector<SinhVien>&Mang, int n) {
	int i, j, chiso_benhat;
	// Di chuyển ranh giới của mảng đã sắp xếp và chưa sắp xếp
	for (i = 0; i < n - 1; i++) {
		// Tìm phần tử nhỏ nhất trong mảng chưa sắp xếp
		chiso_benhat = i;
		for (j = i + 1; j < n; j++)
			if (Mang[j].Diem < Mang[chiso_benhat].Diem)
				chiso_benhat = j;
		// Đổi chỗ phần tử nhỏ nhất với phần tử đầu tiên
		// HoanVi(mang[chiso_benhat], mang[i]);
		SinhVien Tam;
		Tam.Diem = Mang[i].Diem;
		Tam.Ho = Mang[i].Ho;
		Tam.MSSV = Mang[i].MSSV;
		Tam.Ten = Mang[i].Ten;
		Mang[i].Diem = Mang[chiso_benhat].Diem;
		Mang[i].Ho = Mang[chiso_benhat].Ho;
		Mang[i].MSSV = Mang[chiso_benhat].MSSV;
		Mang[i].Ten = Mang[chiso_benhat].Ten;
		Mang[chiso_benhat].Diem = Tam.Diem;
		Mang[chiso_benhat].Ho = Tam.Ho;
		Mang[chiso_benhat].MSSV = Tam.MSSV;
		Mang[chiso_benhat].Ten = Tam.Ten;
	}
}
//heap sort
void heapify(vector<SinhVien>&Mang, int n, int i){
	int LonNhat = i;
	int l = 2 * i + 1; // left = 2*i + 1 
	int r = 2 * i + 2; // right = 2*i + 2 

	if (l < n && Mang[l].Diem > Mang[LonNhat].Diem)
		LonNhat = l;

	if (r < n && Mang[r].Diem > Mang[LonNhat].Diem)
		LonNhat = r;

	if (LonNhat != i){
		//HoanVi(Mang[i], Mang[LonNhat]);
		SinhVien Tam;
		Tam.Diem = Mang[i].Diem;
		Tam.Ho = Mang[i].Ho;
		Tam.MSSV = Mang[i].MSSV;
		Tam.Ten = Mang[i].Ten;
		Mang[i].Diem = Mang[LonNhat].Diem;
		Mang[i].Ho = Mang[LonNhat].Ho;
		Mang[i].MSSV = Mang[LonNhat].MSSV;
		Mang[i].Ten = Mang[LonNhat].Ten;
		Mang[LonNhat].Diem = Tam.Diem;
		Mang[LonNhat].Ho = Tam.Ho;
		Mang[LonNhat].MSSV = Tam.MSSV;
		Mang[LonNhat].Ten = Tam.Ten;

		heapify(Mang, n, LonNhat);
	}
}
void heapSort(vector<SinhVien>&Mang, int n){
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(Mang, n, i);

	for (int i = n - 1; i >= 0; i--)
	{
		//HoanVi([0],[i]);
		SinhVien Tam;
		Tam.Diem = Mang[i].Diem;
		Tam.Ho = Mang[i].Ho;
		Tam.MSSV = Mang[i].MSSV;
		Tam.Ten = Mang[i].Ten;
		Mang[i].Diem = Mang[0].Diem;
		Mang[i].Ho = Mang[0].Ho;
		Mang[i].MSSV = Mang[0].MSSV;
		Mang[i].Ten = Mang[0].Ten;
		Mang[0].Diem = Tam.Diem;
		Mang[0].Ho = Tam.Ho;
		Mang[0].MSSV = Tam.MSSV;
		Mang[0].Ten = Tam.Ten;

		heapify(Mang, i, 0);
	}
}