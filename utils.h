#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void createCrescentList(int numberList[], int length) 
{
	int i;
	for(i = 1; i <= length; i++) 
	{
		numberList[i] = i;
	}
}

void createDecrescentList(int numberList[], int length) 
{
	int i;
	int j = length;
	for(i = 1; i <= length; i++, j--) 
	{
		numberList[i] = j;
	}
}

void createAleatoryList(int numberList[], int length) 
{
	int i;
	srand(time(NULL));
	for(i = 1; i <= length; i++) 
	{
		numberList[i] = ((rand() % length));	
	}
}

void readList(int numberList[], int length) 
{
	int i;
	printf("\n------------------------ Start ------------------------\n\n");
	for(i = 1; i <= length; i++) 
	{
		  printf("%d ", numberList[i]);
	}
	printf("\n------------------------- End -------------------------\n");
}