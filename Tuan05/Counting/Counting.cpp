#include "Counting.h"
void countingSort(int input[], int n)
{

	int *output=new int[n]; 
	int max = input[0];
	int min = input[0];

	for (int i = 1; i < n; i++)
	{
		if (input[i] > max)
			max = input[i];
		else if (input[i] < min)
			min = input[i]; 
	}

	int k = max - min + 1; 

	int *count_array=new int[k];
	fill_n(count_array, k, 0); 

	for (int i = 0; i < n; i++)
		count_array[input[i] - min]++; 
	for (int i = 1; i < k; i++)
		count_array[i] += count_array[i - 1];


	for (int i = 0; i < n; i++)
	{
		output[count_array[input[i] - min] - 1] = input[i];
		count_array[input[i] - min]--;
	}
	for (int i = 0; i < n; i++)
		input[i] = output[i]; 
	delete[]output;
	delete[]count_array;
}