/* A improved version: C++ implementation Quick Sort */
#include <iostream>
using namespace std;

void insertSort(int *a, int low, int right) 
{
	for(int i = low + 1; i <= right; i ++)
	{
		int temp = std::move(a[i]);
		int j = i;
		for( ; j > low && a[j - 1] > temp ; j --)
			a[j] = std::move(a[j - 1]);
		
		a[j] = std::move(temp);
	}
} 

int median3(int *a, int low, int high){
	int mid = low + ((high - low)>>1);
	if(a[low] > a[mid]){
		std::swap(a[low], a[mid]);
	} 
	if(a[low] > a[high]){
		std::swap(a[low], a[high]);
	}
	if(a[mid] > a[high]){
		std::swap(a[mid], a[high]);
	}
	std::swap(a[mid], a[high-1]);  //注意将pivot的值至于 a[high-1]中，确保数字是 a[low] < a[mid] (a[high-1]) < a[high] 
	return a[high-1];  // 将pivot放置于 high - 1 的位置  
}
// 快速排序 
void quickSort(int *a, int low, int high)
{
	if(low + 10 <= high){
		int pivot = median3(a, low, high);
		int i = low, j = high - 1;
		for(; ;){
			// 这里要特别注意  不要 while(a[i] < pivot){ i ++; }   while(a[j] > pivot){ j --; }
			// 不然a[i]  == a[j]   == pivot  时，将陷入死循环。 
			while(a[++ i] < pivot){ }   
			while(a[-- j] > pivot){ }					
			if(i < j){
				std::swap(a[i], a[j]);
			}else{
				break;
			}
		}
		std::swap(a[i], a[high - 1]);
		quickSort(a, low, i - 1);
		quickSort(a, i + 1, high);
	}else{
		insertSort(a, low, high);
	}
}

// 快速选择 
void quickSelect(int *a, int low, int high, int k)
{
	if(low + 10 <= high){
		int pivot = median3(a, low, high);
		int i = low, j = high - 1;
		for(; ;){
			while(a[++ i] < pivot){ }   
			while(a[-- j] > pivot){ }					
			if(i < j){
				std::swap(a[i], a[j]);
			}else{
				break;
			}
		}
		std::swap(a[i], a[high - 1]);
		// 这里相当于 (k-1)<i   (k-1)>i   ===>也就是 k < i + 1  k > i + 1 
        if(k <= i){
            quickSelect(a, low, i - 1, k);
        }else if(k > i + 1){
            quickSelect(a, i + 1, high, k);
        }
	}else{
		insertSort(a, low, high);
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
//    quickSelect(arr, 0, size-1, 20);
	quickSelect(arr, 0, size-1);
    cout << "Sorted array\n";
    show(arr, size);
    return 0;
}
 
