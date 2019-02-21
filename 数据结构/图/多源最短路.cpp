/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
using namespace std;
int array[6][6] = {0}; //存的是边的权值

void Floyd( int N )
{
	int distance[ N ][ N ];
	int path[ N ][ N ];
	fill( path, path+N, -1 );
	for( int i = 1; i < N; ++i )
		for( int j = 1; j < N; ++j )
			distance[ i ][ j ] = array[ i ][ j ];
			
	for( int k = 1; k < N; ++k )
		for( int i = 1; i < N; ++i )
			for( int j = 1; j < N; ++j )
				if( distance[ i ][ k ] + distance[ k ][ j ] < distance[ i ][ j ] )
				{
					distance[ i ][ j ] = distance[ i ][ k ] + distance[ k ][ j ];
					path[ i ][ j ] = k;
				}
					
}

int main(int argc, char *argv[])
{
	array[ 3 ][ 1 ] = 4;
	array[ 3 ][ 5 ] = 5;
	array[ 1 ][ 4 ] = 2;
	array[ 1 ][ 2 ] = 3;
	array[ 2 ][ 4 ] = 1;
	array[ 4 ][ 5 ] = 4;
	Floyd( 6 );
	
	return 0;
}