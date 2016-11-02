#include <iostream>

void printArray(int container[], int n);

void swap(int container[], int posA, int posB);

/* *
 * */
void selectionSort(int container[], int n);

void insertionSort(int container[], int n);

int main()
{
	int arr[] = { 5, 9, 2, 12, 3, 7, 8, 14, 4, 1 };	
	size_t arrSize = sizeof(arr) / sizeof(int);
	//selectionSort(arr, arrSize);
	insertionSort(arr, arrSize);
	printArray(arr, arrSize);	
	return 0;
}

void printArray(int container[], int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << container[i] << " ";
	}
	std::cout << std::endl;
}

void swap(int container[], int posA, int posB)
{
	int a = container[posA];
	container[posA] = container[posB];
	container[posB] = a;
}

void selectionSort(int container[], int n)
{
	// We go from left to right and check for every element if there is a smaller one
	for(int i = 0; i < n - 1; i++)
	{
		// Here we dont have compared the actual number with the others
		// so we assume that the element with index i is the smallest
		int min_i = i;
		// We only look at the elements at i + 1 because elements behind i are already sorted
		// and at start we have already set i as the smallest element(min_i)
		for (int j = i + 1; j < n; j++)
		{
			// If the actual element is smaller then actual min element
			// its the new smallest element
			if (container[j] < container[min_i])
			{
				min_i = j;
			}
		}
		// Swap the acutal element with the smallest one
		swap(container, min_i, i);
		printArray(container, n);
	}
}

void insertionSort(int container[], int n)
{
	// We go from left to right (start by element 1) and compare the element with
	// the elements left of and swap it with the element left of it when its smaller.
	// We do this as long there is a smaller element and we not arrive on the left side
	// if the field.
	for (int i = 1; i < n; i++)
	{
		int j = i;
		// Swap the elements when the left element is smaller then the acutal one.
		// If the left element is not smaller the actual element is on its right position.
		while((j > 0) && (container[j] < container[j -1]))
		{
			swap(container, j , j - 1);
			j--;
			printArray(container, n);
		}
	}
}
