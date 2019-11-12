#ifndef _HEADER_H_
#define _HEADER_H_
#include "SinhVien.h"
#include <time.h>
void ReadSV(ifstream &FileVao, SinhVien &Sv);
void ReadFile(ifstream &FileVao, list<SinhVien>&DSSV);
void XuatList(list<SinhVien>DSSV);
void LinkedListtoArray(list<SinhVien>DSSV, vector<SinhVien>&MSV);
void ArraytoLinkedList(vector<SinhVien>&MSV, list<SinhVien>&DSSV);
//bubble sort
void bubbleSort(vector<SinhVien>&Mang, int n);
//flash sort
void insertionSort(vector<SinhVien>&Mang, int n);
void flashSort(vector<SinhVien>&Mang, int n);
//merge sort
void merge(vector<SinhVien>&Mang, int l, int m, int r);
void mergeSort(vector<SinhVien>&Mang, int l, int r);
//quick sort
void quickSort(vector<SinhVien>&Mang, int l, int r);
//radix sort
float getMax(vector<SinhVien>&Mang, int n);
void countSort(vector<SinhVien>&Mang, int n, int exp);
void radixSort(vector<SinhVien>&Mang, int n);
//selection sort
void selectionSort(vector<SinhVien>&Mang, int n);
//heap sort
void heapify(vector<SinhVien>&Mang, int n, int i);
void heapSort(vector<SinhVien>&Mang, int n);
#endif
