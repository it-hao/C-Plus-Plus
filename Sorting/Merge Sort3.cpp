/*  
	C++ implementation MergeSort 
	这个版本是采用非递归形式
	自然合并排序
	该排序需要一个叫做pass()的子函数，该函数通过一次扫描，将排序前数组中已经有序的子数组段信息记录在rec[]数组中，
	然后返回原数组中自然序列的个数。 
*/
#include <iostream>
#include<cstring>
using namespace std;
const int SIZE = 100;
int rec[SIZE];

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

int  pass(int arr[], int size)
{
    int num = 0;
    int biger = arr[0];
    rec[num++] = 0;
    for(int i = 1; i < size; i ++)
	{
        if(biger > arr[i])
			rec[num++] = i;
        biger=arr[i];
    }
    //给rec[]加一个尾巴，方便排序
    rec[num ++] = size;
    return num;
}

void mergeSort(int arr[], int size)
{
    int num = pass(arr, size);
    for(int i = 0; i < num; i ++)
    	cout<< rec[i]<<" ";
    while(num != 2)
	{
        //num=2说明已经排好序了
        //每循环一次，进行一次pass()操作
        // i + 2 < num 开始没写这个，进入了merge()函数中，然后在merge函数中申请的空间是负数，出错了 
        for(int i = 0; i < num && i + 2 < num; i += 2) 
            merge(arr, rec[i], rec[i+1]-1, rec[i+2]-1);
        num = pass(arr, size);
    }
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
