/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <stack>
using namespace std;
const int n = 10;
struct node{
	int v;
	int w;	
};
vector<node>G[ n ];
int ve[ n ]; //最早开始集合 
int vl[ n ]; //最晚开始集合 
int inDegree[ n ]; //存放入度 
stack<int> topOrder; //存放逆拓扑 

bool topologicalSort()
{
	queue<int> q;
	for( int i = 0; i < n; ++i )
	{
		if( inDegree[ i ] == 0 )
			q.push( i );
	}
	while( !q.empty() )
	{
		int u = q.front();
		q.pop();
		topOrder.push( u );
		for( int i = 0; i < G[ u ].size(); ++i )
		{
			int v = G[ u ][ i ].v;
			--inDegree[ v ];
			if( inDegree[ v ] == 0 ) q.push( v ); 
			if( ve[ u ] + G[ u ][ i ].w > ve[ v ] ) //更新最早开始时间 
				ve[ v ] = ve[ u ] + G[ u ][ i ].w;
		}
	}
	if( topOrder.size() == n ) return true;
	else return false;
}

int CriticalPath()
{
	memset( ve, 0, sizeof( ve ) ); // 最早初始 时间都是 0 
	if( !topologicalSort() ) return -1;
	fill( vl, vl + n, ve[ n - 1 ] ); //最晚开始时间设置一个较大值 
	
	while( !topOrder.empty() ) //更新最晚开始时间 
	{
		int u = topOrder.top();
		topOrder.pop();
		for( int i = 0; i < G[ u ].size(); ++i )
		{
			int v = G[ u ][ i ].v;
			if( vl[ v ] - G[ u ][ i ].w < vl[ u ] )
				vl[ u ] = vl[ v ] - G[ u ][ i ].w;
		}
	}
	
	for( int u = 0; u < n; ++u ) //遍历图，输出关键点 
		for( int i = 0; i < G[ u ].size(); ++i )
		{
			int v = G[ u ][ i ].v;
			int w = G[ u ][ i ].w;
			int e = ve[ u ], l = vl[ v ] - w;
			if( e == w )
				cout << u << "->" << v;
		}
		
	return ve[ n-1 ];
}

int main(int argc, char *argv[])
{
	
	return 0;
}