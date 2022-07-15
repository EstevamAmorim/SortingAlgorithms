#include "utils.h"

const int LENGTH = 100;

void bubbleSort(int numbersList[]) 
{
	int i = 1;
	int j = 0;
	for (i = 0; i <= (LENGTH - 1); i++) 
	{
		for(j = LENGTH; j >=  i + 1; j--) 
		{
			if(numbersList[j] < numbersList[j - 1]) 
			{
				int auxNumber = numbersList[j];
				numbersList[j] = numbersList[j-1];
				numbersList[j - 1] = auxNumber;
			}
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
	bubbleSort(numberList);
	readList(numberList, LENGTH);
	
	return 0;
}
