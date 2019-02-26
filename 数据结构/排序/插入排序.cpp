/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
using namespace std;

void InsertSort( char *array, int N )
{
	for( int i = 1; i < N; ++i )
	{
		char tmp = array[ i ];
		int trueIndex = i; //当前的位置 
		for( ; trueIndex >= 1 && tmp > array[ trueIndex - 1 ]; --trueIndex )
			array[ trueIndex ] = array[ trueIndex - 1 ];
		array[ trueIndex ] = tmp; //该 步 表示正确的下标 
	}
}

int main(int argc, char *argv[])
{
	char array[] = {'2','5','9','1','3','8','6','0','7','4'};
	InsertSort( array, sizeof( array )/ sizeof( *array ) );
	
	auto start = begin( array );
	auto last = end( array );
	while( start != last )
		cout << *start++ << ' ';
		
	return 0;
}