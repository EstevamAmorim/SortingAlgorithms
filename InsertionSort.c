#include "utils.h"

const int LENGTH = 100;

void insertionSort(int numbersList[]) 
{
	int j, i;

	for(j = 2; j <= LENGTH; j++) 
	{
		int key = numbersList[j];
		i = j - 1;
		
		while ((i > 0) && (numbersList[i]) > key) 
		{
			numbersList[i + 1] = numbersList[i];
			i = i - 1;
			numbersList[i + 1] = key;
		}
	}
}

int main() 
{
	int numberList[LENGTH];

	// createCrescentList(numberList);
	// createDecrescentList(numberList);
	createAleatoryList(numberList, LENGTH);
	readList(numberList, LENGTH);
	insertionSort(numberList);
	readList(numberList, LENGTH);
	
	return 0;
}
