#include <iostream>

void printArray(int container[], int n);

void swap(int container[], int posA, int posB);

/* *
 *	Selection Sort needs independent if the sequence is already sorted
 *	(n*(n-1)) / 2 comparisons.
 *	best-case, average-case, worst-case: (n(n-1)) / 2 = Theta(n^2)
 * */
void selectionSort(int container[], int n);

/* *
 *	worst-case: (n*(n-1)) / 2 = Theta(n^2)
 *	average-case: (n*(n-1)) / 4 = Theta(n^2)
 *	best-case: n - 1 = Theta(n)
 * */
void insertionSort(int container[], int n);

/**
 *	best-case: Theta(n)
 *	average-case: Theta(n^2)
 *	worst-case: Theta(n^2)
 * */
void bubbleSort(int container[], int n);

/**
 *	best-case: O(n*log(n))
 *	average-case: O(n*log(n))
 *	worst-case: Theta(n^2)
 * */
void quickSort(int container[], int l, int r);

// Heap Sort

void seepAway(int container[], int  i, int m);

void heapSort(int container[], int n);

// Merge Sort

void merge(int container[], int l, int m, int r);

void mergeSort(int container[], int l, int r);

int main()
{
	//int arr[] = { 5, 9, 2, 12, 3, 7, 8, 14, 4, 1 };	
	//int arr[] = { 5, 6, 2, 1, 4, 3 };
	//int arr[] = { 1, 2, 6, 5, 4, 0, 3, 7 };
	//int arr[] = { 7, 3, 6, 1, 2, 4, 5, 0 };
	int arr[] = { 6, 5, 4, 3, 2, 1 };	
	//int arr[] = { 2, 1 };
	//int arr[] = { 1, 2, 3, 5, 9, 4, 6, 7, 8, 10 };
	size_t arrSize = sizeof(arr) / sizeof(int);
	std::cout << "Before Sort: " << std::endl;
	printArray(arr, arrSize);
	//selectionSort(arr, arrSize);
	//insertionSort(arr, arrSize);
	//bubbleSort(arr, arrSize);
	//quickSort(arr, 0, arrSize - 1);
	//printArray(arr, arrSize);
	//heapSort(arr, arrSize);
	//mergeSort(arr, 0, arrSize - 1); 
	merge(arr, 0, arrSize / 2, arrSize - 1);
	std::cout << "After Sort: " << std::endl;
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
	//std::cout << "SWAPPED" << std::endl;
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
		}
	}
}

void bubbleSort(int container[], int n)
{
	// We go from left to right and compare the each element with the element right of it.
	// If the actual element is bigger then the element on the right side, we swap the element.
	// We do this as long we can go over the sequence without finding a higher element.
	bool swapped = false;
	do
	{
		swapped = false;
		for (int i = 0; i < n - 1; i++)
		{
			if (container[i] > container[i + 1])
			{
				swap(container, i, i + 1);
				swapped = true;
			}
		}
	} while(swapped);
}

void quickSort(int container[], int l, int r)
{
	// We choose a Pivot element and check if the other elements are
	// smaller or higher then the Pivot.
	// Smaller Elements come to the left side of the Pivot and higher
	// ones to the right side.( Higher one on the left side get swapped
	// with smaller ones on the right side).

	// Only run algorithm when we have more then one element to sort
	if (l < r)
	{
		// Here we use the element rightmost of the container as Pivot
		int p = container[r];
		int i = l;
		int j = r - 1;
		do
		{
			while(i <= j && container[i] <= p)
			{
				i++;
			}
			while(i <= j && container[j] >= p)
			{
				j--;
			}
			if (i < j)
			{
				swap(container, i, j);
			}	
		} while(i < j);
		// Pivot element to the middle. The pivot is now on the correct position.
		swap(container, i, r);
		// Sort the left side of the Pivot
		quickSort(container, l, i - 1);	
		// Sort the right side of the Pivot
		quickSort(container, i + 1, r);
	}
}

// Heap Sort

void sweepAway(int container[], int i, int m)
{
	while(2*i+1 <= m) 
	{
		int j = 2*i+1;
		// Compare the 2 childs and set the higher ones as j
		if ((2*i+2 <= m) && (container[2*i+1] < container[2*i+2]))
		{
			j = 2*i+2;
		}
		// Swap the higher child node with its parent when the child is higher then its parent
		if (container[i] < container[j])
		{
			swap(container, i, j);
			i = j;
		}
		else
		{
			// Break
			i = m;
		}
	}
}

void heapSort(int container[], int n)
{
	// Create Heap
	for (int i = (n/2)-1; i >= 0; i--)
	{
		sweepAway(container, i, n-1);
	}	
	// Sort
	for (int i = n-1; i > 0; i--) 
	{
		// After sweeping away the the highest Element is on the left side and the smallest on the right
		swap(container, i, 0);
		sweepAway(container, 0, i-1);
	}
}

// Merge Sort

void merge(int container[], int l, int m, int r)
{
	int arr[r - l + 1];
	int i = l;
	int j = m;
	int addPos = 0;
	
	while(i <= m - 1 && j <= r)
	{
		if (container[i] <= container[j])
		{					
			arr[addPos++] = container[i++];
		}
		else
		{			
			arr[addPos++] = container[j++];
		}
	}
	
	while(i <= m - 1) 
	{
		arr[addPos++] = container[i++];
	}
	while(j <= r)
	{
		arr[addPos++] = container[j++];
	}
	
	for (int k = 0; k < addPos; k++)
	{
		container[l + k] = arr[k];
	}	
}

void mergeSort(int container[], int l, int r)
{
	if (l < r)
	{
		int m = (l + r) / 2;
		mergeSort(container, l, m);
		mergeSort(container, m + 1, r);
		merge(container, l, m + 1, r);
	}
}
