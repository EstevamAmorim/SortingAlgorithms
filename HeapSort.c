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

void buildMaxHeap(int numberList[]) 
{
    int i;

    for(i = floor(LENGTH/2) - 1; i >= 0; i--) 
    {
        maxHeapify(numberList, LENGTH, i);
    }
}

void heapSort(int numberList[], int last) 
{
    int i, aux;
    buildMaxHeap(numberList);

    for(i = LENGTH; i >= 1; i--) 
    {
        aux = numberList[0];
        numberList[0] = numberList[i];
        numberList[i] = aux;
        last--;
        maxHeapify(numberList, last, 0);
    }
}

int main() 
{
	int numberList[LENGTH];
    
    // createCrescentList(numberList);
	// createDecrescentList(numberList);
	createAleatoryList(numberList, LENGTH);
    readList(numberList, LENGTH);
	heapSort(numberList, LENGTH);
    readList(numberList, LENGTH);
	
    return 0;
}
