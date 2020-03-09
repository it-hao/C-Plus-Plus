/*
	Name:
	Author: Hao Shen
	Time: 3/8/2020
	Description: 在其他数都出现k次的数组中，找到只出现一次的数字 
*/
#include<iostream>
#include<cstring>
using namespace std;

// 十进制数转化为 K 进制数 
int *getKSysNumFromNum(int value, int k){
	int *res = new int[32];
	memset(res, 0, sizeof(int) * 32);
	int index = 0;
	while(value){
		res[index++] = value % k;
		value /= k;
	}
	return res;
}

void setExclusiveOr(int e0[], int value, int k){
	int *currKSysNum = new int[32]; 
	memset(currKSysNum, 0, sizeof(int) * 32);
	currKSysNum = getKSysNumFromNum(value, k);
	for(int i = 0; i < 32; i++){
		e0[i] = (e0[i] + currKSysNum[i]) % k;
	}
}
// 将 K 进制数变为十进制数 
int getNumFromKSysNum(int e0[], int k){
	int res = 0;
	for(int i = 31; i >= 0; i--){
		res = res * k + e0[i];
	} 
	return res;
}

int onceNum(int arr[], int len, int k){
	int *e0 = new int[32];
	memset(e0, 0, sizeof(int) * 32);
	for(int i = 0; i < len; i++){
		setExclusiveOr(e0, arr[i], k);
	}

	int res = getNumFromKSysNum(e0, k);
	return res;
} 

int main(){
	int arr[] = {1, 1, 2, 2, 3, 3, 4, 4, 10}; 
	cout<<"输出结果："<<onceNum(arr, 9, 2);
	return 0;
}


