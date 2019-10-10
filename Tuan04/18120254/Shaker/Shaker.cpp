#include "Shaker.h"
void shakerSort(int a[], int n)
{
	int i, j, k;
	for (i = 0; i < n;)
	{
		// Giai đoạn đầu tiên để tăng giá trị cao nhất đến chỉ mục chưa được sắp xếp cao nhất.
		for (j = i + 1; j < n; j++)
		{
			if (a[j] < a[j - 1])
				HoanVi(a[j], a[j - 1]);
		}
		// Giảm chỉ số cao nhất. 
		n--;

		// Giai đoạn thứ hai để giảm giá trị thấp nhất xuống chỉ mục chưa sắp xếp thấp nhất.
		for (k = n - 1; k > i; k--)
		{
			if (a[k] < a[k - 1])
				HoanVi(a[k], a[k - 1]);
		}
		// Tăng chỉ số thấp nhất.
		i++;
	}
}