/*
	Name:  
	Author: Hao Shen
	Time: 3/8/2020
	Description: ��λ����ʵ�ּӷ��ͼ����Ĳ��� (����Ա���Ա���) 
*/
#include<iostream>
using namespace std;
int addOp(int a, int b){
	int sum = 0;
	while(b){
		sum = a ^ b; 	// û�н�λ��  λ��λ ��ӣ� 
		b = (a & b) << 1; 	//����ÿһλ�Ľ�λ  Ȼ�����ƣ� 
		a = sum;
	}
	return sum;
} 

int minusOp(int a, int b){
	// �Ƚ���ȡ������
	int _b = addOp(~b, 1);	
	return addOp(a, _b);
}
int main(){
	int a = 10;
	int b = 10;
	cout<<addOp(a, b)<<","<<minusOp(a, b);
	return 0;
}


