// C++ program to implement bubble sort 
#include <iostream>
using namespace std; 
  
void bubbleSort(int *a, int n) 
{
	bool isSort = true;
	for(int i = 0; i < n && isSort; i ++) 
	{
		isSort = false;
		for(int j = 0; j < n - i - 1; j ++)
		{
			if(a[j] > a[j+1])
			{
				isSort = true;
				swap(a[j], a[j + 1]);
			}
		}
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
    
    bubbleSort(arr, len); 
  
    cout << "Sorted array\n";
    show(arr, len); 
  
    return 0; 
} 
