// C++ program to implement heap sort 
// �������ݽṹ���㷨���� C++ �汾 

#include <algorithm>
#include <iostream>
using namespace std;
const int SIZE = 100;
int a[SIZE];

// �ڵ� i ����ڵ� 
int leftChild(int i){
	return i * 2 + 1;
}

// �����Ķѻ����������˽����Ĵ��� 
void heapify(int *a, int i, int n) {
	// i �ǿ�ʼ���˵�λ�ã�n�Ƕ���ѵ��߼���С
	int child;
	int tmp;
	for(tmp = std::move(a[i]); leftChild(i) < n; i = child){
		child = leftChild(i);
		// child != n - 1  ��ʱ��ʾ������ڵ㣬a[n]�Ѿ��ǴӶѶ������������������� 
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

// ������ 
void heapsort(int *a, int n) {
    for (int i = n - 1; i >= 0; --i) {
        swap(a[0], a[i]);
        heapify(a, 0, i);
    }
}

// �������� 
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
