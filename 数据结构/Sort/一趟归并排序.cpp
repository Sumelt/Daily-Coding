/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
using namespace std;

//非递归 核心要求两子序列是有序的 
void Merge( int *array, int Lindex, int Rindex, int Rend )
{
	int sumN = Rend - Lindex + 1; //元素个数
	int *tempArray = new int[ sumN ]; //临时空间 
	int tempBeginIndex = 0; //临时空间的开始下标 
	int Lend = Rindex - 1; //左结束边界 
	 
	while( Lindex <= Lend && Rindex <= Rend ) 
	{
		if( array[ Lindex ] >= array[ Rindex ] ) 
			tempArray[ tempBeginIndex++ ] = array[ Lindex++ ];
		else tempArray[ tempBeginIndex++ ] = array[ Rindex++ ];
	}
	while( Lindex <= Lend )
		tempArray[ tempBeginIndex++ ] = array[ Lindex++ ];
	while( Rindex <= Rend )
		tempArray[ tempBeginIndex++ ] = array[ Rindex++ ];
			
	for( int i = 0; i < sumN; ++i, --Rend )
		array[ Rend ] = tempArray[ Rend ];
	delete tempArray;
}

int main(int argc, char *argv[])
{
	int array[]	= {	12, 99, 77, 7, 2, 3 };
	int N = sizeof( array )/sizeof( *array );
	int mid = ( N - 1 ) >> 1;
	Merge( array, 0, mid, N );
	auto start = begin( array );
	auto last = end( array );
	while( start != last )
		cout << *start++ << ' ';
		
	return 0;
}