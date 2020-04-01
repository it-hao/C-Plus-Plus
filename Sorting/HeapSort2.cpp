// C++ program to implement heap sort 
// 来自数据结构与算法分析 C++ 版本 

#include <algorithm>
#include <iostream>
using namespace std;
const int SIZE = 100;
int a[SIZE];

// 节点 i 的左节点 
int leftChild(int i){
	return i * 2 + 1;
}

// 这样的堆化操作减少了交换的次数 
void heapify(int *a, int i, int n) {
	// i 是开始下滤的位置，n是二叉堆的逻辑大小
	int child;
	int tmp;
	for(tmp = std::move(a[i]); leftChild(i) < n; i = child){
		child = leftChild(i);
		// child != n - 1  此时表示的是左节点，a[n]已经是从堆顶调整下来的最大的数了 
		if(child != n - 1 && a[child] < a[child + 1]){     
			child ++;
		}
		if (tmp < a[child]){
			a[i] = std::move(a[child]);
		}else{
			break;
		}
	} 
	a[i] = std::move(tmp);
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
