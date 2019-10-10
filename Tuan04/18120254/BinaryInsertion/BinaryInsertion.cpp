#include "BinaryInsertion.h"
void binaryinsertionSort(int a[], int n)
{
	int l, r, m, i;
	int x;//lưu giá trị a[i] tránh bị ghi đè khi dời chỗ các phần tử.  
	for (int i = 1; i < n; i++)
	{
		x = a[i]; l = 0;
		r = i - 1;
		while (l <= r) // tìm vị trí chèn x 
		{
			m = (l + r) / 2;
			// tìm vị trí thích hợp m   
			if (x < a[m]) r = m - 1;
			else l = m + 1;
		}
		for (int j = i - 1; j >= l; j--)
			a[j + 1] = a[j];// dời các phần tử sẽ đứng sau x  
		a[l] = x;  // chèn x vào dãy  }
	}
}