
/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
using namespace std;

//非递归
void _Merge( int *array, int *tempArray, int Lfirst, int mid, int Rlast )
{
	int Llast = mid - 1;
	int Rfirst = mid;
	int tp = Lfirst; //暂存开始位置，不然最后赋值回去再次有开销 
	
	while( Lfirst <= Llast && Rfirst <= Rlast )
	{
		if( array[ Lfirst ] <= array [ Rfirst ] )
			tempArray[ tp++ ] = array[ Lfirst++ ];
		else tempArray[ tp++ ] = array[ Rfirst++ ];		
	}
	
	while( Lfirst <= Llast ) 
		tempArray[ tp++ ] = array[ Lfirst++ ];
	while( Rfirst <= Rlast ) 
		tempArray[ tp++ ] = array[ Rfirst++ ];
	
	for( int i = 0; i < tp; ++i, --Rlast )  //巧妙赋值,前部分操作都只在对应暂存空间 操作 
		array[ Rlast ] = tempArray[ Rlast ];
}

void NRMerSort( int *array, int N ) 
{
	int *tempArray = new int[ N ]; //临时空间
	int i = 0;
	for( int length = 1; length < N; length *= 2 ) //length 为一个序列的长度 
	{ 
		for( i = 0; i < N  - (2 * length); i += 2*length ) // i 为能取得的下标 ，不是循环的次数 
		{
			cout << "i " << i  << " length " << length <<endl;
			_Merge( array, tempArray, i, i + length, i + 2 * length - 1 );			
		}
			
		if( i + length < N ) //还剩下两个区间可以合并，一个区间长度满足length，另一个区间不满足 
		{
			cout << "other " << endl;
			cout << "i " << i  << " length " << length <<endl;
			_Merge( array, tempArray, i, i + length, N - 1 );
		}
			
		else; //还剩一个区间，但该区间长度不满足一个length 
	}
	
	delete tempArray;
}

int main(int argc, char *argv[])
{
	int array[]	= {	10, 8, 9, 4, 7, 2, 1 };
	int sumN = sizeof( array )/ sizeof( *array );
	NRMerSort( array, sumN );
	
	auto bg = begin( array );
	auto ed = end( array );
	while( bg != ed ) 
		cout << *bg++ << ' ';	
		
	return 0;
}
