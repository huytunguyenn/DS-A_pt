#include "Bubble.h"
void bubbleSort(int mang[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
		// Phần tử i cuối cùng đã có sẵn
		for (j = 0; j < n - i - 1; j++)
			if (mang[j] > mang[j + 1])
				HoanVi(mang[j], mang[j + 1]);
}