/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#define INF 0x3fffffff
//67108863 表示无穷大
using namespace std;

int array[6][6] = {0}; //存的是边的权值 

void Dijkstra(int begin, int N , int end)
{
	int path[ N+1 ] = {0};
	bool visted[ N+1 ] = {false};
	int distance[ N+1 ]; //源到该点的距离 
	fill( distance, distance+N+1, INF ); //表示源点到各点距离都是无穷大
	distance[ begin ] = 0; //自己到自己距离为0 
	path[ begin ] = -1; //源的上一个节点不存在
	
	while( true )
	{
		int MinDisIndex = -1, MinDis = INF;
		for( int i = 1; i <= N; ++i )
		{
			if( !visted[i] && distance[ i ] < MinDis ) //找到未访问节点中最小的距离节点 
			{
				MinDisIndex = i;
				MinDis = distance[ i ];
			}		
		}
		
		if( MinDisIndex == -1 ) break; //全部访问完或者是个孤立的节点 
		visted[ MinDisIndex ] = true; //表示已经访问过 
		for( int i = 1; i <= N; ++i ) //循环后该点的所有邻接点的距离都已经更新S 
		{
			if( !visted[ i ] && array[ MinDisIndex ][ i ] !=0 
				&& distance[ MinDisIndex ] + array[ MinDisIndex ][ i ] < distance[ i ]) 
				//源点到 MinDisIndex的距离加上array[ MinDisIndex ][ i ]的距离小于
				//源值接到distance[i]的距离则更新 
			{
				distance[ i ] = distance[ MinDisIndex ] + array[ MinDisIndex ][ i ];//更新最短距离S 
				path[ i ] = MinDisIndex;
			} 
		}
	}
		
	while( path[ end ] != -1 ) //终点到起点经过的节点 
	{
		cout << end << ' ';
		end = path[ end ];
	}
	cout << begin << endl;
	for( int i = 1; i <= N; ++i )
		cout << distance[ i ] << ' ';
	if( end > begin )
		cout << endl << distance[ end+1 ];
	else cout << endl << distance[ end-1 ];
}


int main(int argc, char *argv[])
{
	array[ 3 ][ 1 ] = 4;
	array[ 3 ][ 5 ] = 5;
	array[ 1 ][ 4 ] = 2;
	array[ 1 ][ 2 ] = 3;
	array[ 2 ][ 4 ] = 1;
	array[ 4 ][ 5 ] = 4;
	Dijkstra( 3, 5, 4 );
	
	return 0;
}
