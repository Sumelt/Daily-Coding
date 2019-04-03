/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
using namespace std;

int findAppearingOneTime( int *array, int n )
{
	int bitArray[ 32 ] = { 0 };//存储二进制每一位出现的次数
	
	for( int i = 0; i < n; ++i )
	{
		int andBit = 1;//不断右移判断每一位
        //从最低位开始
		for( int bitIndex = 31; bitIndex >= 0; --bitIndex ) {
			if( ( andBit & array[ i ] ) != 0 ) //这里一定注意关系运算符比位与符优先级还要高
				bitArray[ bitIndex ] += 1;//保存该位出现的次数
			andBit <<= 1; 
		}
	}	
	int res = 0;
    //从最高位开始
	for( int i = 0; i < 32; ++i ) {
		res <<= 1;
		res += bitArray[ i ] % 3;//除去能被3整除的次数，剩下的就是只出现一次的位数
	}
	return res;
}

int main(int argc, char *argv[])
{
	int array[  ] = {
		2, 2, 2, 3
	};
	cout << findAppearingOneTime( array, 4 );
	return 0;
}