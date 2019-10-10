#include "Selection.h"

void selectionSort(int mang[], int n) {
	int i, j, chiso_benhat;
	// Di chuyển ranh giới của mảng đã sắp xếp và chưa sắp xếp
	for (i = 0; i < n - 1; i++) {
		// Tìm phần tử nhỏ nhất trong mảng chưa sắp xếp
		chiso_benhat = i;
		for (j = i + 1; j < n; j++)
			if (mang[j] < mang[chiso_benhat])
				chiso_benhat = j;
		// Đổi chỗ phần tử nhỏ nhất với phần tử đầu tiên
		HoanVi(mang[chiso_benhat], mang[i]);
	}
}