// C++ program to implement shell sort 
#include <iostream>
using namespace std; 
  
void shellSort(int *a, int n) 
{
	for(int gap = n / 2; gap > 0 ; gap /= 2){
		for(int i = gap; i < n; i ++)
		{
			int temp = std::move(a[i]);
			int j = i;
			for( ; j >= gap && a[j - gap] > temp ; j -= gap)
				a[j] = std::move(a[j - gap]);
			
			a[j] = std::move(temp);
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
    
    shellSort(arr, len); 
  
    cout << "Sorted array\n";
    show(arr, len); 
  
    return 0; 
} 
