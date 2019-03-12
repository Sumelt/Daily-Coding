/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <ctime>
#include <vector>
using namespace std;


//尾递归
int Fibonacci3Core(int n, int res1, int res2)
{
	if( n == 0 || n == 1 ) 
		return n == 1? res1 : 0; //这里 返回 res1 是因为 存储着结果 
	return Fibonacci3Core( n - 1, res2, res2 + res1 ); //从 第n 项减到  1项 的结果就是从 第 1项加到 第 n 项 
}

int Fibonacci3(int n) {
	return Fibonacci3Core( n, 1, 1 );
} 

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

//递归实现
int Fibonacci1(int n) {
	if( n == 0 || n == 1 ) 
		return n == 1? 1 : 0;
	return Fibonacci1( n - 1 ) + Fibonacci1( n - 2 ); 
}

//记忆化搜索  自顶向下 
int Fibonacci4Core( vector<int> *memo, int n )
{
	if( n == 0 )
		( *memo )[ n ] = 0;
	else if( n == 1 )
		( *memo )[ n ] = 1;
		
	if( ( *memo )[ n ] == -1 )
		( *memo )[ n ] = Fibonacci4Core( memo, n - 1 ) + 
			Fibonacci4Core( memo, n - 2 );
			
	return ( *memo )[ n ];
}
int Fibonacci4( int n ) {
	vector<int>memo( n + 1, -1 ); //保存计算所得的结果
	return Fibonacci4Core( &memo, n );
}

//动态规划 自底向上 
int Fibonacci5( int n ) {
	vector<int>memo( n + 1, -1 ); //保存计算所得的结果
	memo[ 0 ] = 0;
	memo[ 1 ] = 1;
	
	for( int i = 2; i <= n; ++i )
		memo[ i ] = memo[ i - 1 ] + memo[ i - 2 ];
	
	return memo[ n ];
}
 

int main(int argc, char *argv[])
{
	time_t startTime = clock();
	cout << Fibonacci4( 20 ) << endl;
	time_t endTime = clock();
	cout << "spend time: " << double( endTime - startTime ) / CLOCKS_PER_SEC << endl;

	return 0;
}