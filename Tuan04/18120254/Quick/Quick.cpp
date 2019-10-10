#include "Quick.h"
//void quickSort(int a[], int dau, int cuoi) {
//	int i, j, danhdau, temp;
//	if (dau < cuoi) {
//		danhdau = dau;
//		i = dau;
//		j = cuoi;
//		while (i < j) {
//			while (a[i] <= a[danhdau] && i < cuoi)
//				i++;
//			while (a[j] > a[danhdau])
//				j--;
//			if (i < j) {
//				temp = a[i];
//				a[i] = a[j];
//				a[j] = temp;
//			}
//		}
//		temp = a[danhdau];
//		a[danhdau] = a[j];
//		a[j] = temp;
//		quickSort(a, dau, j - 1);
//		quickSort(a, j + 1, cuoi);
//	}
//}


void quickSort(int a[], int l, int r)
{
	srand(time(NULL));  //khoi tao tham so ham rand()
	int key = a[l + rand() % (r - l + 1)];  //lay khoa la gia tri ngau nhien tu a[l] -> a[r]
	//int key = a[(l+r)/2];
	int i = l, j = r;

	while (i <= j)
	{
		while (a[i] < key) i++;       // tim phan tu ben trai ma >=key
		while (a[j] > key) j--;       // tim phan tu ben trai ma <=key
		if (i <= j)
		{
			if (i < j)
				HoanVi(a[i], a[j]);  // doi cho 2 phan tu kieu int a[i], a[j].
			i++;
			j--;
		}
	}
	//bay gio ta co 1 mang : a[l]....a[j]..a[i]...a[r]
	if (l < j) quickSort(a, l, j);   // lam lai voi mang a[l]....a[j]
	if (i < r) quickSort(a, i, r); // lam lai voi mang a[i]....a[r]
}

