/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date:

----------------------------------------------------------------*/
#include <iostream>
#include <cstring>
#include <ctime>
using namespace std;

//标记冒泡 
void BubbleSort( char *array, int N )
{
	for( int i = 0; i < N - 1; ++i ) //循环 N -1 次 
	{
		bool flag = false; //第一遍扫描  标志位若没有发生改变 表示 序列是有序的 
		for( int j = 0; j < N - 1 - i; ++j ) // N - 1防止 最后 + 1 溢出 
		{
			if( array[ j ] > array[ j+1 ] )
			{
				swap( array[ j ], array[ j+1 ] );
				flag = true;
			}			
		}
		if( !flag ) break;
	}	
}

//鸡尾酒冒泡 
void CocktailSort( char *array, int N )
{
	int count = N;
	int Lindex = 0;
	bool flag = false;
	for( int i = 0; count > 0; ++i, count -= 2 )
	{   
		int j = Lindex;
		for( ; j < N - 1 - i; ++j ) //较大已经排好 放到最后一位
		{
			if( array[ j ] > array[ j+1 ] )
			{
				swap( array[ j ], array[ j+1 ] );
				flag = true;
			}			
		}
		if( !flag ) break;
		for( int i = j; i > Lindex; --i ) //较小已经排好 放到第一位
		{
			if( array[ i ] < array[ i-1 ] )
				swap( array[ i ], array[ i-1 ] );			
		}
		 ++Lindex; 
	}
}

int main(int argc, char *argv[])
{
	char array[] = {'2','5','9','1','3','8','6','0','7','4'};
	CocktailSort( array, sizeof( array )/ sizeof( *array ) );
	
	auto start = begin( array );
	auto last = end( array );
	while( start != last )
		cout << *start++ << ' ';
	
/*
	printf("cycle lastmax number: %d\n",how_count_lastmax);
	printf("cycle lastmin number: %d\n",how_count_firstmin);
	printf("cycle number: %d\n", sizeof( array )/ sizeof( *array ) );
	printf("Cost time: %fms\n",how_count_lastmax - how_count_firstmin );*/
	return 0;
}
