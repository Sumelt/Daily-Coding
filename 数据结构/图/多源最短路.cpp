/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
using namespace std;
#define INF 10000 //表示无穷大 
#define MAX 10
int array[ MAX ][ MAX ]; //存的是边的权值
int path[ MAX ][ MAX ]; //存 i 到 J 的中间节点SS 

void Floyd( int N )
{	
	fill( path[0], path[0]+MAX*MAX, -1 ); //初始化 
	for( int k = 1; k < N; ++k )
		for( int i = 1; i < N; ++i )
			for( int j = 1; j < N; ++j )
				if( array[ i ][ k ]!=INF && array[ k ][ j ]!=INF && 
					array[ i ][ k ] + array[ k ][ j ] < array[ i ][ j ] )
				{
					array[ i ][ j ] = array[ i ][ k ] + array[ k ][ j ];
					path[ i ][ j ] = k;
				}			
}

void Print( int i, int j )
{
	if( path[ i ][ j ] == -1 )
	{
		cout << j << i; return;
	}
	else {
		cout << j; Print( i, path[ i ][ j ] );
	}
}

int main(int argc, char *argv[])
{
	int N = 6; 
	fill( array[0], array[0]+MAX*MAX, INF ); //分配了多少空间的矩阵就要全部初始化 
	array[ 3 ][ 1 ] = 1;
	array[ 3 ][ 5 ] = 5;
	array[ 1 ][ 4 ] = 1;
	array[ 1 ][ 2 ] = 3;
	array[ 2 ][ 4 ] = 1;
	array[ 4 ][ 5 ] = 1;
	Floyd( N );
	Print( 3, 5 ); // 3到 5的中间节点S 
	cout << endl;
	for( int i = 1; i < N; ++i ) //路径矩阵 
	{
		for( int j = 1; j < N; ++j )
			cout << path[ i ][ j ] <<' ';
		cout << endl;
	}

	return 0;
}