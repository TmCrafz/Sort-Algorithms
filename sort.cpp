#include <iostream>

void printArray(int container[], int n);

void swap(int container[], int posA, int posB);

/* *
 * Selection Sort has a max runtime of O(n^2)
 * */
void selectionSort(int container[], int n);

int main()
{
	int arr[] = { 8, 2, 1, 3, 6 };	
	size_t arrSize = sizeof(arr) / sizeof(int);
	selectionSort(arr, arrSize);
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
	}
}
