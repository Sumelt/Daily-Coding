/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
using namespace std;


void ShellSortUp( char *array, int N )
{
	int Increment[] = { 1, 5, 19 };
	int IncremenCount = sizeof(Increment) / sizeof( *Increment ); //增量的个数 
	for( ; IncremenCount > 0; --IncremenCount ) //控制增量 
	{
		int IncrementNumber = Increment[ IncremenCount - 1 ];

		for( int startIndex = IncrementNumber ; startIndex < N; startIndex += IncrementNumber ) //能摸的牌数 
		{
			char tmp = array[ startIndex ];
			int trueIndex = startIndex;			
			for( ; trueIndex >= IncrementNumber && tmp > array[ trueIndex - IncrementNumber ]; 
					trueIndex -= IncrementNumber )
				array[ trueIndex ] = array[ trueIndex - IncrementNumber ];
			array[ trueIndex ] = tmp;
		} 
			
	}
}

//原始希尔排序 
void ShellSort( char *array, int N )
{
	for( int up = 8; up >= 1; up /= 2 )
	{
		for( int i = up; i < N; i += up ) //能摸的牌个数 
		{
			char temp = array[ i ]; //摸第二张 
			int index = i;			
			for( ; index >= up && temp > array[ index - up ]; index -= up  ) //和上一张比较 
				array[ index ] = array[ index - up ];
			array[ index ] = temp;
		}
	}
	
}

int main(int argc, char *argv[])
{
	char array[] = {'2','5','9','1','3','8','6','0','7','4'};
	ShellSortUp( array, sizeof( array )/ sizeof( *array ) );
	
	auto start = begin( array );
	auto last = end( array );
	while( start != last )
		cout << *start++ << ' ';
		
	return 0;
}