#include "utils.h"

const int LENGTH = 100;

void maxHeapify(int numberList[], int last, int i) 
{
    int greater, aux;
    int l = 2*i;
    int r = 2*i+1;

    if(l < last && numberList[l] > numberList[i])
        greater = l;
    else greater = i;

    if(r < last && numberList[r] > numberList[greater])
        greater = r;
    
	if(greater != i) 
    {
        aux = numberList[greater];
        numberList[greater] = numberList[i];
        numberList[i] = aux;
        maxHeapify(numberList, last, greater);
    }
}

void buildMaxHeap(int numberList[], int p, int r) 
{
    int i;
    for(i = floor((p + r)/2); i >= p; i--) 
    {
        maxHeapify(numberList, r + 1, i);
    }
}

void heapSort(int numberList[], int p, int r) 
{   
    int last = r;
    int i, aux;
    buildMaxHeap(numberList, p, r);
    for(i = r; i >= p; i--) 
    {
        aux = numberList[p];
        numberList[p] = numberList[i];
        numberList[i] = aux;
        last--;
        maxHeapify(numberList, last, p);
    }
}

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

void quickHeapSort(int numberList[], int first, int last)
{
	if(first < last)
	{
        int middle = partitionArray(numberList, first, last);

        if(first < middle - 1 || last > middle + 1)
            heapSort(numberList, first, last);
        else 
        {
		    quickHeapSort(numberList, first, middle - 1);
		    quickHeapSort(numberList, middle + 1, last);
        }
	}
}

int main() {
    int numberList[LENGTH];
	// createCrescentList(numberList);
	// createDecrescentList(numberList);
	createAleatoryList(numberList, LENGTH);
	readList(numberList, LENGTH);
	quickHeapSort(numberList, 1, LENGTH);
	readList(numberList, LENGTH);
    
    return 0;
}

