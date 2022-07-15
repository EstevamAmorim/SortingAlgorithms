#include <limits.h>
#include "utils.h"

const int LENGTH = 100;

void merge(int numberList[], int first, int middle, int last) 
{
	int aux1 = middle - first + 1;
	int aux2 = last - middle;

	int left[aux1 + 1];
	int rigth[aux1 + 1];

	int i, j;

	for(i = 1; i <= aux1; i ++) 
	{
		left[i]  = numberList[first + i - 1];
	}

	for(j = 1; j <= aux2; j ++) 
	{
		rigth[j] = numberList[middle + j];
	}

	left[aux1 + 1] = INT_MAX;
	rigth[aux2 + 1] = INT_MAX;

	i = 1;
	j = 1;

	int k;

	for(k = first; k <= last; k++) 
	{
		if(left[i] <= rigth[j]) 
		{
			numberList[k] = left[i];
			i = i + 1;
		} else 
		{
			numberList[k] = rigth[j];
			j = j + 1;
		}
	}
}

void mergeSort(int numberList[], int first, int last) 
{
	if (first < last) 
	{
		int middle = (first + last)/2;
		mergeSort(numberList, first, middle);
		mergeSort(numberList, middle + 1, last);
		merge(numberList, first, middle, last);
	}
}

int main() 
{
	int numberList[LENGTH];
	// createCrescentList(numberList);
	// createDecrescentList(numberList);
	createAleatoryList(numberList, LENGTH);
	readList(numberList, LENGTH);
	mergeSort(numberList, 1, LENGTH);
	readList(numberList, LENGTH);

	return 0;
}
