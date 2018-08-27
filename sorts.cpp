#include<iostream>
using namespace std; 
//code testing all of the sorts 

void bubbleSort(int *arr, int size) {
	int temp; 
	for (int position = 1; position < size; position++)
	{
		for (int i = 0; i < size - position; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp; 
			}
		}
	}
}
void insertionSort(int *arr, int size)
{
	
	for (int position = 1; position < size; position++)
	{
		int element = arr[position];
		for (int i = position - 1; i >= 0; i--)
		{
			if (arr[i] > element)
			{
				arr[i + 1] = arr[i];
			}
			else
				break;
			arr[i] = element;
		}
	}
}
void selectionSort(int *arr, int size)
{
	int min = 0; //where we will store the minimum 

	for (int i = 0; i < size - 1; i++)
	{
		min = i;

		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[min])
				min = j;
		}
		swap(arr[min], arr[i]);
	}
}
int partition(int arr[], int low, int high)
{
	int pivot = arr[high];    // pivot is the highest number 
	int i = (low-1);  // Index of smaller element

	for (int j = low; j < high; j++)
	{
		// If current element is smaller than or
		// equal to pivot
		if (arr[j] <= pivot)
		{
			i++;    // increment index of smaller element
			swap(arr[i], arr[j]); //swap with index of smaller element 
		}
	}
	swap(arr[i + 1], arr[high]); //swap the pivot and at this point the pivot is in its sorted place 

	return (i+1); //returns the index of the sorted element 
}
void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(arr, low, high); //pi is the sorted element index

		quickSort(arr, low, pi - 1); //sort elements before the index 
		quickSort(arr, pi + 1, high); //sort the elements after the index 
	}
}
void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	/* create temp arrays */
	int *L = new int[n1];
	int *R = new int[n2];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = l; // Initial index of merged subarray
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there
	are any */
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	are any */
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}
void mergeSort(int arr[], int l, int r)
{
	if (l < r)
	{
		// Same as (l+r)/2, but avoids overflow for
		// large l and h
		int m = l + (r - l) / 2;

		// Sort first and second halves
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}
void shellSort(int arr[], int n)
{
	// Start with a big gap, then reduce the gap
	for (int gap = n / 2; gap > 0; gap /= 2)
	{
		// Do a gapped insertion sort for this gap size.
		// The first gap elements a[0..gap-1] are already in gapped order
		// keep adding one more element until the entire array is
		// gap sorted 
		for (int i = gap; i < n; i += 1)
		{
			// add a[i] to the elements that have been gap sorted
			// save a[i] in temp and make a hole at position i
			int temp = arr[i];

			// shift earlier gap-sorted elements up until the correct 
			// location for a[i] is found
			int j;
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
				arr[j] = arr[j - gap];

			//  put temp (the original a[i]) in its correct location
			arr[j] = temp;
		}
	}
}
void heapify(int arr[], int n, int i)
{
	int largest = i;  // Initialize largest as root
	int l = 2 * i + 1;  // left = 2*i + 1
	int r = 2 * i + 2;  // right = 2*i + 2

	// If left child is larger than root
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than largest so far
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// If largest is not root
	if (largest != i)
	{
		swap(arr[i], arr[largest]);

		// Recursively heapify the affected sub-tree
		heapify(arr, n, largest);
	}
}
void heapSort(int arr[], int n)
{
	// Build heap (rearrange array)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// One by one extract an element from heap
	for (int i = n - 1; i >= 0; i--)
	{
		// Move current root to end
		swap(arr[0], arr[i]);

		// call max heapify on the reduced heap
		heapify(arr, i, 0);
	}
}
int main() {

	int arr1[9] = { 9,2,45,32,657,87,5,5,24 };
	cout << "before bubbleSort" << endl;
	for (int i = 0; i < 9; i++)
	{
		cout << arr1[i] << endl;
	}

	bubbleSort(arr1, 9);
	cout << "after bubbleSort" << endl;
	for (int i = 0; i < 9; i++)
	{
		cout << arr1[i] << endl; 
	}

	cout << "before insertionSort" << endl;
	int arr2[9] = { 9,2,45,32,657,87,5,5,24 };
	for (int i = 0; i < 9; i++)
	{
		cout << arr2[i] << endl;
	}
	insertionSort(arr2, 9);
	cout << "after insertionSort" << endl;
	for (int i = 0; i < 9; i++)
	{
		cout << arr2[i] << endl;
	}

	cout << "before selectionSort" << endl; 
	int arr3[9] = { 9,5,45,32,657,87,5,2,24 };
	for (int i = 0; i < 9; i++)
	{
		cout << arr3[i] << endl;
	}
	selectionSort(arr3, 9);
	cout << "after selectionSort" << endl;
	for (int i = 0; i < 9; i++)
	{
		cout << arr3[i] << endl;
	}

	cout << "before quickSort" << endl;
	int arr4[9] = { 9,5,45,32,657,87,5,2,24 };
	for (int i = 0; i < 9; i++)
	{
		cout << arr4[i] << endl;
	}
	quickSort(arr4, 0, 8);
	cout << "after quickSort" << endl;
	for (int i = 0; i < 9; i++)
	{
		cout << arr4[i] << endl;
	}


	cout << "before mergeSort" << endl;
	int arr5[9] = { 9,5,45,32,657,87,5,2,24 };
	for (int i = 0; i < 9; i++)
	{
		cout << arr5[i] << endl;
	}
	mergeSort(arr5, 0, 8);
	cout << "after mergeSort" << endl;
	for (int i = 0; i < 9; i++)
	{
		cout << arr5[i] << endl;
	}

	cout << "before shellSort" << endl;
	int arr6[9] = { 9,5,45,32,657,87,5,2,24 };
	for (int i = 0; i < 9; i++)
	{
		cout << arr6[i] << endl;
	}
	shellSort(arr6, 9);
	cout << "after shellSort" << endl;
	for (int i = 0; i < 9; i++)
	{
		cout << arr6[i] << endl;
	}
	cout << "before heapSort" << endl;
	int arr7[9] = { 9,5,45,32,657,87,5,2,24 };
	for (int i = 0; i < 9; i++)
	{
		cout << arr7[i] << endl;
	}
	heapSort(arr7, 9);
	cout << "after heapSort" << endl;
	for (int i = 0; i < 9; i++)
	{
		cout << arr7[i] << endl;
	}
	system("pause");
	return 0; 
}
