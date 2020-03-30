/*  
	C++ implementation MergeSort 
	这个版本是采用非递归形式 
*/
#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r)
{
	int n = r - l + 1;
	int tmp[n];
	int i, j, k;
	for(i = l, j = m + 1, k = 0; i <= m && j <= r;)
	{
		if(arr[i] <= arr[j])
			tmp[k++] = arr[i++];
		else
			tmp[k++] = arr[j++];
	}
	if(i == m + 1)
	{
		for(; j <= r;)
			tmp[k++] = arr[j++];
	}else
	{
		for(; i <= m;)
			tmp[k++] = arr[i++];
	}
	
	for(i = l; i < n + l; i++)
		arr[i] = tmp[i - l];
}

void mergeSort(int arr[], int n)
{
	// 设置开始合并区间是2，然后逐渐放大2倍，知道超出数组长度 
   int s = 2;
   while(s <= n){
   		int i = 0;
   		while(i + s <= n){
   			merge(arr, i, i + s/2 - 1, i + s - 1);
			i += s;	
		}
		// 合并剩余部分，例如如果是出现奇数个数，会有多余出现 
		merge(arr, 0, i + s/2 - 1 , n-1);
		s *= 2;
   }
   // 最后再合并一次 
   merge(arr, 0, s/2 - 1 , n - 1);
}

void show(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << A[i] << "\n";
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

    mergeSort(arr, size);

    cout << "Sorted array\n";
    show(arr, size);
    return 0;
}
