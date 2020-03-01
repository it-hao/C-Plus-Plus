// C++ program to implement selection sort 
#include <iostream>
using namespace std; 
  
void SelectSort(int *a, int n) 
{
	for(int i = 0; i < n; i ++) 
	{
		int minIndex = i;
		for(int j = i + 1; j < n; j ++)
		{
			if(a[minIndex] > a[j]){
				minIndex = j;
			}
		}
		if(minIndex != i) 
			swap(a[i], a[minIndex]);
	}
} 

void show(int *a, int len)
{
    int i;
    for (i = 0; i < len; i++)
        cout << a[i] << "\n";
}

// driver function to test the algorithm 
int main() 
{ 
	int len;
    cout << "\nEnter the number of elements : ";

    cin >> len;

    int arr[len];

    cout << "\nEnter the unsorted elements : ";

    for (int i = 0; i < len; ++i)
    {
        cout << "\n";
        cin >> arr[i];
    }
    
    SelectSort(arr, len); 
  
    cout << "Sorted array\n";
    show(arr, len); 
  
    return 0; 
} 
