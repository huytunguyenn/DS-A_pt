#include "Shell.h"
int shellSort(int mang[], int n)
{
	// Bắt đầu với một khoảng cách lớn, sau đó giảm khoảng cách
	for (int khoangcach = n / 2; khoangcach > 0; khoangcach /= 2)
	{
		// Thực hiện sắp xếp chèn xen kẽ cho kích thước khoảng cách này.
		// Các phần tử khoảng cách đầu tiên a [0..gap-1] đã được sắp xếp theo thứ tự
		// tiếp tục thêm một phần tử nữa cho đến khi toàn bộ mảng là
		// khoảng cách được sắp xếp

		for (int i = khoangcach; i < n; i += 1)
		{
			// thêm a[i] vào các phần tử đã được sắp xếp khoảng cách
			// lưu a[i] trong tam và tạo một lỗ ở vị trí i
			int tam = mang[i];

			// thay đổi các phần tử được sắp xếp khoảng cách trước đó cho đến khi chính xác
			// vị trí cho a[i] được tìm thấy
			int j;
			for (j = i; j >= khoangcach && mang[j - khoangcach] > tam; j -= khoangcach)
				mang[j] = mang[j - khoangcach];

			// đặt tam (bản gốc a[i]) vào đúng vị trí của nó
			mang[j] = tam;
		}
	}
	return 0;
}