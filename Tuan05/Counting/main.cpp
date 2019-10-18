#include "Counting.h"

int main()
{
	cout << "COUNTING SORT" << endl;
	//1000 phần tử
	int a[1000];
	cout << endl << "1000 phan tu" << endl;
	int arr_size = sizeof(a) / sizeof(a[0]);
	//Mảng số từ bé đến lớn.
	GenerateSortedData(a, 1000);
	clock_t start = clock();// hàm bất đầu đếm thời gian thực hiện chương trình
	countingSort(a, arr_size);
	clock_t finish = clock();// hàm đếm thời gian kết thúc
	double duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "Thoi gian sort mang tu be den lon: " << setprecision(9) << fixed << duration << endl;
	//Mảng số từ lớn đến bé.
	GenerateReverseData(a, 1000);
	start = clock();// hàm bất đầu đếm thời gian thực hiện chương trình
	countingSort(a, arr_size);
	finish = clock();// hàm đếm thời gian kết thúc
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "Thoi gian sort mang tu lon den be: " << setprecision(9) << fixed << duration << endl;
	//Mảng số ngẫu nhiên.
	GenerateRandomData(a, 1000);
	start = clock();// hàm bất đầu đếm thời gian thực hiện chương trình
	countingSort(a, arr_size);
	finish = clock();// hàm đếm thời gian kết thúc
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "Thoi gian sort mang ngau nhien: " << setprecision(9) << fixed << duration << endl;
	//Mảng số đã được sắp xếp 1 phần.
	GenerateNearlySortedData(a, 1000);
	start = clock();// hàm bất đầu đếm thời gian thực hiện chương trình
	countingSort(a, arr_size);
	finish = clock();// hàm đếm thời gian kết thúc
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "Thoi gian sort mang sap xep 1 phan: " << setprecision(9) << fixed << duration << endl;

	//5000 phần tử
	int b[5000];
	cout << endl << "5000 phan tu" << endl;
	arr_size = sizeof(b) / sizeof(b[0]);
	//Mảng số từ bé đến lớn.
	GenerateSortedData(b, 5000);
	start = clock();// hàm bất đầu đếm thời gian thực hiện chương trình
	countingSort(b, arr_size);
	finish = clock();// hàm đếm thời gian kết thúc
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "Thoi gian sort mang tu be den lon: " << setprecision(9) << fixed << duration << endl;
	//Mảng số từ lớn đến bé.
	GenerateReverseData(b, 5000);
	start = clock();// hàm bất đầu đếm thời gian thực hiện chương trình
	countingSort(b, arr_size);
	finish = clock();// hàm đếm thời gian kết thúc
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "Thoi gian sort mang tu lon den be: " << setprecision(9) << fixed << duration << endl;
	//Mảng số ngẫu nhiên.
	GenerateRandomData(b, 5000);
	start = clock();// hàm bất đầu đếm thời gian thực hiện chương trình
	countingSort(b, arr_size);
	finish = clock();// hàm đếm thời gian kết thúc
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "Thoi gian sort mang ngau nhien: " << setprecision(9) << fixed << duration << endl;
	//Mảng số đã được sắp xếp 1 phần.
	GenerateNearlySortedData(b, 5000);
	start = clock();// hàm bất đầu đếm thời gian thực hiện chương trình
	countingSort(b, arr_size);
	finish = clock();// hàm đếm thời gian kết thúc
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "Thoi gian sort mang sap xep 1 phan: " << setprecision(9) << fixed << duration << endl;

	//10000 phần tử
	int c[10000];
	cout << endl << "10000 phan tu" << endl;
	arr_size = sizeof(c) / sizeof(c[0]);
	//Mảng số từ bé đến lớn.
	GenerateSortedData(c, 10000);
	start = clock();// hàm bất đầu đếm thời gian thực hiện chương trình
	countingSort(c, arr_size);
	finish = clock();// hàm đếm thời gian kết thúc
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "Thoi gian sort mang tu be den lon: " << setprecision(9) << fixed << duration << endl;
	//Mảng số từ lớn đến bé.
	GenerateReverseData(c, 10000);
	start = clock();// hàm bất đầu đếm thời gian thực hiện chương trình
	countingSort(c, arr_size);
	finish = clock();// hàm đếm thời gian kết thúc
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "Thoi gian sort mang tu lon den be: " << setprecision(9) << fixed << duration << endl;
	//Mảng số ngẫu nhiên.
	GenerateRandomData(c, 10000);
	start = clock();// hàm bất đầu đếm thời gian thực hiện chương trình
	countingSort(c, arr_size);
	finish = clock();// hàm đếm thời gian kết thúc
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "Thoi gian sort mang ngau nhien: " << setprecision(9) << fixed << duration << endl;
	//Mảng số đã được sắp xếp 1 phần.
	GenerateNearlySortedData(c, 10000);
	start = clock();// hàm bất đầu đếm thời gian thực hiện chương trình
	countingSort(c, arr_size);
	finish = clock();// hàm đếm thời gian kết thúc
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "Thoi gian sort mang sap xep 1 phan: " << setprecision(9) << fixed << duration << endl;

	//30000 phần tử
	int d[30000];
	cout << endl << "30000 phan tu" << endl;
	arr_size = sizeof(d) / sizeof(d[0]);
	//Mảng số từ bé đến lớn.
	GenerateSortedData(d, 30000);
	start = clock();// hàm bất đầu đếm thời gian thực hiện chương trình
	countingSort(d, arr_size);
	finish = clock();// hàm đếm thời gian kết thúc
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "Thoi gian sort mang tu be den lon: " << setprecision(9) << fixed << duration << endl;
	//Mảng số từ lớn đến bé.
	GenerateReverseData(d, 30000);
	start = clock();// hàm bất đầu đếm thời gian thực hiện chương trình
	countingSort(d, arr_size);
	finish = clock();// hàm đếm thời gian kết thúc
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "Thoi gian sort mang tu lon den be: " << setprecision(9) << fixed << duration << endl;
	//Mảng số ngẫu nhiên.
	GenerateRandomData(d, 30000);
	start = clock();// hàm bất đầu đếm thời gian thực hiện chương trình
	countingSort(d, arr_size);
	finish = clock();// hàm đếm thời gian kết thúc
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "Thoi gian sort mang ngau nhien: " << setprecision(9) << fixed << duration << endl;
	//Mảng số đã được sắp xếp 1 phần.
	GenerateNearlySortedData(d, 30000);
	start = clock();// hàm bất đầu đếm thời gian thực hiện chương trình
	countingSort(d, arr_size);
	finish = clock();// hàm đếm thời gian kết thúc
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "Thoi gian sort mang sap xep 1 phan: " << setprecision(9) << fixed << duration << endl;

	//100000 phần tử
	int e[100000];
	cout << endl << "100000 phan tu" << endl;
	arr_size = sizeof(e) / sizeof(e[0]);
	//Mảng số từ bé đến lớn.
	GenerateSortedData(e, 100000);
	start = clock();// hàm bất đầu đếm thời gian thực hiện chương trình
	countingSort(e, arr_size);
	finish = clock();// hàm đếm thời gian kết thúc
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "Thoi gian sort mang tu be den lon: " << setprecision(9) << fixed << duration << endl;
	//Mảng số từ lớn đến bé.
	GenerateReverseData(e, 100000);
	start = clock();// hàm bất đầu đếm thời gian thực hiện chương trình
	countingSort(e, arr_size);
	finish = clock();// hàm đếm thời gian kết thúc
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "Thoi gian sort mang tu lon den be: " << setprecision(9) << fixed << duration << endl;
	//Mảng số ngẫu nhiên.
	GenerateRandomData(e, 100000);
	start = clock();// hàm bất đầu đếm thời gian thực hiện chương trình
	countingSort(e, arr_size);
	finish = clock();// hàm đếm thời gian kết thúc
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "Thoi gian sort mang ngau nhien: " << setprecision(9) << fixed << duration << endl;
	//Mảng số đã được sắp xếp 1 phần.
	GenerateNearlySortedData(e, 100000);
	start = clock();// hàm bất đầu đếm thời gian thực hiện chương trình
	countingSort(e, arr_size);
	finish = clock();// hàm đếm thời gian kết thúc
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "Thoi gian sort mang sap xep 1 phan: " << setprecision(9) << fixed << duration << endl;

	system("pause");
	return 0;
}