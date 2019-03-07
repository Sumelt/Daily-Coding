/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
using namespace std;

//循环实现 
int Fibonacci2(int n) {
	int res = 0;
	int temp1 = 0, temp2 = 1;
	if( n == 0 || n == 1 ) 
		return n == 1? temp2 : temp1; 
	
	for( int i = 2; i <= n; ++i ) {		
		res = temp1 + temp2;
		temp1 = temp2;
		temp2 = res;	
	}
	return res;	
}
//尾递归
int Fibonacci3(int n, int res1, int res2) {
	if( n == 0 || n == 1 ) 
		return n == 1? res1 : 0; //这里 返回 res1 是因为 存储着结果 
	return Fibonacci3( n - 1, res2, res2 + res1 ); //从 第n 项减到  1项 的结果就是从 第 1项加到 第 n 项 
} 


//递归实现
int Fibonacci(int n) {
	if( n == 0 || n == 1 ) 
		return n == 1? 1 : 0;
	return Fibonacci( n - 1 ) + Fibonacci( n - 2 ); 
}

int main(int argc, char *argv[])
{
	cout << Fibonacci3( 39, 1, 1 ) << endl;
	cout << Fibonacci2(39); //4 * 8 = 32 bit = 2 ^32 = 2147483647
	return 0;
}