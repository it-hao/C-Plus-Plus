// C++ program to implement heap sort 

#include <algorithm>
#include <iostream>
using namespace std;
const int SIZE = 100;
int a[SIZE];
// 不断地上浮和下沉  构成堆化 
void heapify(int *a, int i, int n) {
    int largest = i;
    const int l = 2 * i + 1;
    const int r = 2 * i + 2;

    if (l < n && a[l] > a[largest])
        largest = l;

    if (r < n && a[r] > a[largest])
        largest = r;

    if (largest != i) {
        swap(a[i], a[largest]);
		heapify(a, largest, n);
    }
}

// 堆排序 
void heapsort(int *a, int n) {
    for (int i = n - 1; i >= 0; --i) {
        swap(a[0], a[i]);
        heapify(a, 0, i);
    }
}

// 构建最大堆 
void build_maxheap(int *a, int n) {
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(a, i, n);
    }
}

int main() {
    int n;
    cout << "Enter number of elements of array\n";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cout << "Enter Element " << i << endl;
        cin >> a[i];
    }

    build_maxheap(a, n);
    heapsort(a, n);
    cout << "Sorted Output\n";
    for (int i = 0; i < n; ++i) {
    	cout << a[i] << std::endl;
    }

    getchar();
}
