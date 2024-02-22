/*
Liam Hudson
COP3502
2/22/24
*/
#include <stdio.h>
#include <stdlib.h>

// low and high hold indices
// this function performs a binary search on an array of integers in increasing size to find the index of a search value
int search(int numbers[], int low, int high, int value) 
{
    if(low < high){ // if the lowest index if less than the highest index
        int middle = (low + high) / 2; // this variable stores the index of the middle value
        if(value > numbers[middle]){ // condition if the search value if greater than the middle value
            return search(numbers, middle+1, high, value); // recursive iteration that calls the function with a new low index
        }
        else if(value < numbers[middle]){
            return search(numbers, low, middle-1, value); // recursive iteration that calls the function with a new high index
        }
        else if(numbers[middle] == value) // if the value is found, return the index
            return middle;
    } // first if statement
    return -1; // if the value is not found in the array
}

void printArray(int numbers[], int sz)
{
	int i;
	printf("Number array : ");
	for (i = 0;i<sz;++i)
	{
		printf("%d ",numbers[i]);
	}
	printf("\n");
}

int main(void)
{
	int i, numInputs;
	char* str;
	float average;
	int value;
	int index;
	int* numArray = NULL;
	int countOfNums;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &countOfNums);
		numArray = (int *) malloc(countOfNums * sizeof(int));
		average = 0;
		for (i = 0; i < countOfNums; i++)
		{
			fscanf(inFile," %d", &value);
			numArray[i] = value;
			average += numArray[i];
		}

		printArray(numArray, countOfNums);
		value = average / countOfNums;
		index = search(numArray, 0, countOfNums - 1, value);
		if (index >= 0)
		{
			printf("Item %d exists in the number array at index %d!\n",value, index);
		}
		else
		{
			printf("Item %d does not exist in the number array!\n", value);
		}

		free(numArray);
	}

	fclose(inFile);
}