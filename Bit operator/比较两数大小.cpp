/*
	Name: ��λ��������������Ĵ�С 
	Author: Hao Shen
	Time: 3/8/2020
	Description: ���ڵļ�������Թ涨 int �� long int, �� 32 λ�� ���ķ�Χ����� -2147483648 2147483647
*/
#include<iostream>
using namespace std;
// 0 1��ת 
int flip(int x){
	return x ^ 1;
}
// �жϸ����������Ǹ��� 
int sign(int x){
	return flip((x >> 31) & 1); 
}

// ������Ч��ֹ��� 
int getMax(int a, int b){
	// ��������ֻ������ |aΪ��bΪ��|  ����  |bΪ��aΪ��|
	// ���Դ�ʱ difSab = 1 ,same Sab = 0. 
	int c = a - b;
	int sa = sign(a);
	int sb = sign(b);
	int sc = sign(c);
	cout<<"a / sa = "<<a<<"/"<<sa<<endl;
	cout<<"b / sb = "<<b<<"/"<<sb<<endl;
	cout<<"c / sc = "<<c<<"/"<<sc<<endl;
	int difSab = sa ^ sb;
	int sameSab = flip(difSab);
	int returnA = difSab * sa + sameSab * sc; 
	int returnB = flip(returnA);
	return returnA * a + returnB * b;
}
int main(){
	int a = INT_MAX, b = INT_MIN;
//	int a = 4, b = 4;
	cout<< getMax(a, b);
}


