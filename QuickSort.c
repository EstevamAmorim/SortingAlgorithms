#include "utils.h"

const int LENGTH = 100;

int partitionArray(int numberList[], int first, int last)
{
	int aux = numberList[last];
	int i = first - 1;
	int j;

	for(j = first; j <= last - 1; j++)
	{
		if(numberList[j] < aux)
		{
			i = i + 1;
			int exchange = numberList[i];
			numberList[i] = numberList[j];
			numberList[j] = exchange;
		}
	} 

	int exchange = numberList[i + 1];
	numberList[i + 1] = numberList[last];
	numberList[last] = exchange;
	return i + 1;
}

void quicksort(int numberList[], int first, int last)
{
	if(!(first < last)) return;
	
	int middle = partitionArray(numberList, first, last);
	quicksort(numberList, first, middle - 1);
	quicksort(numberList, middle + 1, last);
}

int main() 
{
	int numberList[LENGTH];

	// createCrescentList(numberList);
	// createDecrescentList(numberList);
	createAleatoryList(numberList, LENGTH);
	readList(numberList, LENGTH);
	quicksort(numberList, 1, LENGTH);
	readList(numberList, LENGTH);

	return 0;
}
