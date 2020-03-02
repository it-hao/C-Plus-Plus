#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r)
{
	int n = r - l + 1;
	int *tmp = new int[n];
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
		
	delete tmp;
}

//void merge(int arr[], int l, int m, int r)
//{
//    int i, j, k;
//    int n1 = m - l + 1;
//    int n2 = r - m;
//
//    int L[n1], R[n2];
//
//    for (i = 0; i < n1; i++)
//        L[i] = arr[l + i];
//    for (j = 0; j < n2; j++)
//        R[j] = arr[m + 1 + j];
//
//    i = 0;
//    j = 0;
//    k = l;
//    while (i < n1 && j < n2)
//    {
//        if (L[i] <= R[j])
//        {
//            arr[k] = L[i];
//            i++;
//        }
//        else
//        {
//            arr[k] = R[j];
//            j++;
//        }
//        k++;
//    }
//
//    while (i < n1)
//    {
//        arr[k] = L[i];
//        i++;
//        k++;
//    }
//
//    while (j < n2)
//    {
//        arr[k] = R[j];
//        j++;
//        k++;
//    }
//}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {

        int m = l + ((r - l) >> 1);

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
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

    mergeSort(arr, 0, size - 1);

    cout << "Sorted array\n";
    show(arr, size);
    return 0;
}
