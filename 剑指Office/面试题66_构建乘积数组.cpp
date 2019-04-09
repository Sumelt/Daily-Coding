/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
using namespace std;

void arrayProduct( const vector<int>vec1, vector<int>vec2 )
{
	int size1 = vec1.size();
	int size2 = vec2.size();
	
	if( size2 > 1 && size1 == size2 ) { //给定的空间相等并且空间大小至少为2		
        //自上而下
        vec2[ 0 ] = 1;
		for( int i = 1; i < size2; ++i )
			vec2[ i ] = vec2[ i - 1 ] * vec1[ i - 1 ];
		
        //自下而上
		vec2[ size2 - 1 ] = 1;
		for( int i = size2 - 2; i >= 0; --i )
			vec2[ i ] *= vec2[ i + 1 ] * vec1[ i + 1 ];
	}	
}

int main(int argc, char *argv[])
{
	
	return 0;
}