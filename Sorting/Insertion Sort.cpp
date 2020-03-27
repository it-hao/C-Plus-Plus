// C++ program to implement insertion sort 
#include <iostream>
using namespace std; 
  
void insertSort(int *a, int n) 
{
	for(int i = 1; i < n; i ++)
	{
		int temp = std::move(a[i]);
		int j = i;
		for( ; j > 0 && a[j - 1] > temp ; j --)
			a[j] = std::move(a[j - 1]);
		
		a[j] = std::move(temp);
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
    
    insertSort(arr, len); 
  
    cout << "Sorted array\n";
    show(arr, len); 
  
    return 0; 
} 
