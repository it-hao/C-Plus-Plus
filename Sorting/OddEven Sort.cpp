/*
 C++ implementation Odd Even Sort 
eg: 			6, 2, 4, 1, 5, 9
	ÆæÊıÅÅĞò:   2, 6, 1, 4, 5, 9
	Å¼ÊıÅÅĞò£º	2, 1, 6, 4, 5, 9
	ÆæÊıÅÅĞò:   1, 2, 4, 6, 5, 9
	Å¼ÊıÅÅĞò£º	1, 2, 4, 5, 6, 9
*/
#include <iostream>
#include <vector>

using namespace std;

void oddEven(int *a, int n)
{
	bool sorted = false;
	while (!sorted)
	{
		sorted = true;
		for (int i = 1; i < n - 1; i += 2) //Odd
		{
			if (a[i] > a[i + 1])
			{
				swap(a[i], a[i + 1]);
				sorted = false;
			}
		}

		for (int i = 0; i < n - 1; i += 2) //Even
		{
			if (a[i] > a[i + 1])
			{
				swap(a[i], a[i + 1]);
				sorted = false;
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
    
    oddEven(arr, len); 
  
    cout << "Sorted array\n";
    show(arr, len); 
  
    return 0; 
} 
