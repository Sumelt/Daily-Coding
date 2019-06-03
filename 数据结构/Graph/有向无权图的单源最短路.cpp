/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <queue>
using namespace std;
int array[6][6] = {0};

void Unweighted (int begin, int N , int end)
{
	int path[ 6 ] = {0}; //存储到达本节点的上一个节点 由上一个节点到达 
	int dist[ 6 ]; //源节点到本节点的距离 
	fill( dist, dist+N+1, -1 ); //初始化 
	queue<int>que;
	que.push( begin );
	dist[ begin ] = 0; //源，自己到自己距离为0 
	while( !que.empty() )
	{
		int top = que.front();
		que.pop();
		for( int i = 1; i <= N; ++i )
		{
			if( array[ top ][ i ] == 1 && dist[ i ] == -1 )
			{
				que.push( i );
				dist[ i ] = dist[ top ] + 1; //为上一个节点距离加一
				path[ i ] = top; //该节点由上一个节点到达 
			}
				
		}
	}

	while( path[ end ] != 0 ) //终点到起点经过的节点 
	{
		cout << " " << end;
		end = path[ end ];
	}
	cout <<" " << begin;
}

int main(int argc, char *argv[])
{
	array[ 3 ][ 1 ] = 1;
	array[ 3 ][ 5 ] = 1;
	array[ 1 ][ 4 ] = 1;
	array[ 1 ][ 2 ] = 1;
	array[ 2 ][ 4 ] = 1;
	array[ 4 ][ 5 ] = 1;
	Unweighted( 3, 5, 4 );
	
	return 0;
}

