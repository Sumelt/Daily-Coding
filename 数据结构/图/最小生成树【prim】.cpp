/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
using namespace std;
#define INF 0x3ffffff 
const int MAX = 10;
int array[ MAX ][ MAX ];
int path[ MAX ];

int prim( int N )
{
	int distance[ MAX ]; //表示到集合的距离
	int sumWeight = 0;
	bool visted[MAX];
	fill( distance, distance+MAX, INF );
	//fill( path, path+MAX, -1 );
	fill( visted, visted+MAX, false );
	distance[ 1 ] = 0; // 根节点 
	while( true )
	{
		int MinWeightIndex = -1;
		int MinWeight = INF;
		for( int i = 1; i < N; ++i )
		{
			if( !visted[ i ] && distance[ i ] < MinWeight )
			{
				MinWeightIndex = i;
				MinWeight = distance[ i ];
			}
		}
		if( MinWeightIndex < 0 ) break; //全部访问完或者剩下的是孤立节点
		visted[ MinWeightIndex ] = true;
		sumWeight += distance[ MinWeightIndex ];
		for( int i = 1; i < N; ++i )
		{
			if( !visted[ i ] && array[ MinWeightIndex ][ i ]!=0 
				&& array[ MinWeightIndex ][ i ] < distance[ i ]  )
			{
				distance[ i ] = array[ MinWeightIndex ][ i ];
				path[ i ] = MinWeightIndex;
			}
		} 
	}
	return sumWeight;
}

void Input() //边权为0表示不联通 
{
	array[ 1 ][ 2 ] = 1;
	array[ 2 ][ 1 ] = 1;
	array[ 2 ][ 4 ] = 3;
	array[ 4 ][ 2 ] = 3;
	array[ 1 ][ 4 ] = 4;
	array[ 4 ][ 1 ] = 4;
	array[ 1 ][ 3 ] = 5;
	array[ 3 ][ 1 ] = 5;
	array[ 3 ][ 4 ] = 6;
	array[ 4 ][ 3 ] = 6;
}

int main(int argc, char *argv[])
{
	Input();
	cout << prim( 5 );
	return 0;
}