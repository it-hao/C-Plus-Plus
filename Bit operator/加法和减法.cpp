/*
	Name:  
	Author: Hao Shen
	Time: 3/8/2020
	Description: 用位运算实现加法和减法的操作 (程序员面试宝典) 
*/
#include<iostream>
using namespace std;
int addOp(int a, int b){
	int sum = 0;
	while(b){
		sum = a ^ b; 	// 没有进位的  位对位 相加； 
		b = (a & b) << 1; 	//计算每一位的进位  然后左移； 
		a = sum;
	}
	return sum;
} 

int minusOp(int a, int b){
	// 先进行取反操作
	int _b = addOp(~b, 1);	
	return addOp(a, _b);
}
int main(){
	int a = 10;
	int b = 10;
	cout<<addOp(a, b)<<","<<minusOp(a, b);
	return 0;
}


