/*  C++ implementation QuickSort */
#include <iostream>
using namespace std;
// 这种是还可以通过“荷兰国旗问题”进行优化 
int partition(int *a, int low, int high)
{
	int i, j;
	i = j = low;
	int pivot = a[high];
	// 通过游标i进而将a[low, high-1]分成两部分，一部分是已经处理的，都小于 pivot 的, 即：a[low, i-1]
	// 另一部分是处未理的，即：a[i, high-1]	我们每次都从未处理的区域取出一个去和 pivot 比较， 如果小
	// 于的话，就将其放到处理区域的尾部，最后 i 就是那个分界点。 
	for(; j < high; j ++)
	{
		if(a[j] < pivot)
		{
			if(i != j)
			{
				swap(a[i], a[j]);
			}
			i ++;
		}
	}
	swap(a[i], a[high]);
	return i;
}
// 这种是经常使用的 
//int partition(int *a, int low, int high)
//{
//	int pivot = a[low];
//	
//	while(low < high)
//	{
//		while (low < high && a[high] > pivot)	high --;
//		a[low] = a[high];
//		
//		while (low < high && a[low] < pivot)		low ++;
//		a[high] = a[low];
//	}
//	
//	a[low] = pivot;
//	return low;
//   
//}

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
