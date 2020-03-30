/*  
	C++ implementation MergeSort 
	����汾�ǲ��÷ǵݹ���ʽ
	��Ȼ�ϲ�����
	��������Ҫһ������pass()���Ӻ������ú���ͨ��һ��ɨ�裬������ǰ�������Ѿ���������������Ϣ��¼��rec[]�����У�
	Ȼ�󷵻�ԭ��������Ȼ���еĸ����� 
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
    //��rec[]��һ��β�ͣ���������
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
        //num=2˵���Ѿ��ź�����
        //ÿѭ��һ�Σ�����һ��pass()����
        // i + 2 < num ��ʼûд�����������merge()�����У�Ȼ����merge����������Ŀռ��Ǹ����������� 
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
