/*  
	C++ implementation MergeSort 
	����汾�ǲ��÷ǵݹ���ʽ 
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
	// ���ÿ�ʼ�ϲ�������2��Ȼ���𽥷Ŵ�2����֪���������鳤�� 
   int s = 2;
   while(s <= n){
   		int i = 0;
   		while(i + s <= n){
   			merge(arr, i, i + s/2 - 1, i + s - 1);
			i += s;	
		}
		// �ϲ�ʣ�ಿ�֣���������ǳ����������������ж������ 
		merge(arr, 0, i + s/2 - 1 , n-1);
		s *= 2;
   }
   // ����ٺϲ�һ�� 
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
