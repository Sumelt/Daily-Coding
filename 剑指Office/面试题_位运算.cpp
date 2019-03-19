/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
using namespace std;

//计算二进制中1的个数
int countOne( int number )
{
	int count = 0;
	while( number != 0 ) {
		number = number & ( number - 1 );
		++count;
	}		
	return count; 
}
//O(1)时间检测整数是否是2的幂次
// 2 10
// 4 100
// 8 1000
bool judgePowerOf2( int number )
{
	if( !( number & ( number - 1 ) ) )
		return true;
	return false;
}

//将整数A改变成整数B 需要改变多少个比特位
int countChangeBit( int A, int B )
{
	int number = A ^ B;
	int count = 0;
	while( number != 0 ) {
		number = number & ( number - 1 );
		++count;
	}		
	return count; 
} 

//一个数组中某个数出现一次，其余数出现两次 找出出现1次的数字
int appearOneTime( int *array, int N )
{
	int number = 0;
	for( int i = 0; i < N; ++i )
		number = number ^ *( array + i );
	return number;
}

int main(int argc, char *argv[])
{
	int array[] = { 3, 4, 4, 5, 5 };
	cout << appearOneTime( array, 5 );
	return 0;
}