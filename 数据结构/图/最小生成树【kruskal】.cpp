/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 50;
int FatherIndex[ MAX ];

struct edge{
	int point1, point2;
	int cost;	
};

bool mycmp( edge a, edge b )
{
	return a.cost < b.cost;
}

int Find( int p )
{
	while( FatherIndex[ p ] != -1 )
		p = FatherIndex[ p ];
	
	return p;
}

int kruskal( int N, int sumPoint, edge *edgeArray ) //边数 顶点数 
{
	int sumWeight = 0;
	int sumEdge = 0;
	sort( edgeArray, edgeArray+N, mycmp );
	for( int i = 1; i < N; ++i )
	{
		int root1 = Find( edgeArray[ i ].point1 );
		int root2 = Find( edgeArray[ i ].point2 );
		if( root1 == -1 && root2 == -1 || root1 != root2 )
		{
			FatherIndex[ edgeArray[ i ].point2 ] = edgeArray[ i ].point1;
			sumWeight += edgeArray[ i ].cost;
			++sumEdge;
		}
		if(  sumEdge ==  sumPoint - 1 ) break;
			
	}
	return sumWeight;
}

void Input( edge *edgeArray )
{
	edgeArray[ 1 ].point1 = 1; edgeArray[ 1 ].point2 = 2; edgeArray[ 1 ].cost = 1;
	edgeArray[ 2 ].point1 = 2; edgeArray[ 2 ].point2 = 4; edgeArray[ 2 ].cost = 3;
	edgeArray[ 3 ].point1 = 4; edgeArray[ 3 ].point2 = 3; edgeArray[ 3 ].cost = 6;
	edgeArray[ 4 ].point1 = 1; edgeArray[ 4 ].point2 = 3; edgeArray[ 4 ].cost = 5;
	edgeArray[ 5 ].point1 = 1; edgeArray[ 5 ].point2 = 4; edgeArray[ 5 ].cost = 4;
}

int main(int argc, char *argv[])
{
	int N = 6;
	fill( FatherIndex, FatherIndex+MAX, -1 );
	edge array[ N ];
	Input( array );
	cout << kruskal( N, 4, array );
	return 0;
}