/*
	Name: 用位运算计算两个数的大小 
	Author: Hao Shen
	Time: 3/8/2020
	Description: 现在的计算机语言规定 int 是 long int, 是 32 位， 它的范围大概是 -2147483648 2147483647
*/
#include<iostream>
using namespace std;
// 0 1反转 
int flip(int x){
	return x ^ 1;
}
// 判断该是正数还是负数 
int sign(int x){
	return flip((x >> 31) & 1); 
}

// 可以有效防止溢出 
int getMax(int a, int b){
	// 溢出的情况只可能是 |a为正b为负|  或者  |b为负a为正|
	// 所以此时 difSab = 1 ,same Sab = 0. 
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


