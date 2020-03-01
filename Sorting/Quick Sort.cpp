/*  C++ implementation QuickSort */
#include <iostream>
using namespace std;

int partition(int *a, int low, int high)
{
	int pivot = a[low];
	
	while(low < high)
	{
		while (low < high && a[high] > pivot)	high --;
		a[low] = a[high];
		
		while (low < high && a[low] < pivot)		low ++;
		a[high] = a[low];
	}
	
	a[low] = pivot;
	return low;
   
}

void quickSort(int *a, int low, int high)
{
    if (low < high)
    {

        int p = partition(a, low, high);

        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

void show(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << "\n";
}

// Driver program to test above functions
int main()
{
    int size;
    cout << "\nEnter the number of elements : ";

    cin >> size;

    int arr[size];

    cout << "\nEnter the unsorted elements : ";

    for (int i = 0; i < size; ++i)
    {
        cout << "\n";
        cin >> arr[i];
    }
    quickSort(arr, 0, size-1);
    cout << "Sorted array\n";
    show(arr, size);
    return 0;
}
