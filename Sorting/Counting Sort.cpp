/*  C++ implementation countSort */
#include <iostream>
#include<cstring>
using namespace std;

int getMax(int arr[], int n)
{
	int max = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > max)
			max = arr[i];
	return max;
}

int getMin(int arr[], int n)
{
	int min = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] < min)
			min = arr[i];
	return min;
}

void show(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << "\n";
}

void countSort(int *arr, int n)
{
	int max = getMax(arr, n);
	int min = getMin(arr, n);
	
	int *sortedArr = new int[n + 1];
	int count[max - min + 1];
	
	for(int i = 0; i < max - min + 1; i++)
		count[i] = 0;
	
	for (int i = 0; i < n; i++)
		count[arr[i] - min] ++;

	for (int i = 1; i < (max - min + 1); i++)
		count[i] += count[i - 1];

	for (int i = n - 1; i >= 0; i--)
	{
		sortedArr[count[arr[i] - min] - 1] = arr[i];
		count[arr[i] - min]--;
	}
	for(int i = 0; i < n; i++)
	{
		arr[i] = sortedArr[i]; 
	} 
	delete sortedArr;
}

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
	countSort(arr, size);
	show(arr, size);
	return 0;
}
