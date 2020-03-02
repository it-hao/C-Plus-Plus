/*  C++ implementation radixSort */
#include <iostream>
#include <cmath>
using namespace std;
void radixSort(int a[], int n)
{
	int output[n];
	int max = 0;
	
	for (int i = 0; i < n; ++i)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
	}
	int maxdigits = 0;
	while (max)
	{
		maxdigits ++;
		max /= 10;
	}
	for(int j = 0; j < maxdigits; j ++)
	{
		int  t = pow(10, j);
			
		int k = 0;
		for(int p = 0; p < 10; p ++)
		{
			for(int i = 0; i < n; i++)
				if(a[i] % (10 * t) / t == p)
					output[k ++] = a[i];
		}
		
		for(int i = 0; i < n; i++)
		{
			a[i] = output[i];
		} 
	} 
}
void show(int a[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << ",";
	}
	cout << endl;
}

int main(int argc, char const *argv[])
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
    radixSort(arr, size);
    cout << "Sorted array\n";
    show(arr, size);
	return 0;
}
