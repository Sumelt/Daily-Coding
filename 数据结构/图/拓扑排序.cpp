/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool topologicalSort( vector<int> *G, int *inDegree, int N )
{
	queue<int>que;
	int sumV = 0;
	for( int i = 0; i < N; ++i )
	{
		if( inDegree[ i ] == 0 )
			que.push( i );
	}	
	while( !que.empty() )
	{
		int top = que.front();
		cout << top << ' ';
		que.pop();
		++sumV; //记录入队的节点数 
		for( int i = 0; i < G[ top ].size(); ++i )
		{
			int nextIndex = G[ top ][ i ];
			--inDegree[ nextIndex ];
			if( inDegree[ nextIndex ] == 0 )
				que.push( nextIndex );
		}
	}
	if( sumV == N ) return true;
	else return false;
	
}

int main(int argc, char *argv[])
{
	int N = 5;
	int inDegree[ N ] = { 0 };
	vector<int> Gvec[ N ];
	
	Gvec[ 0 ].push_back( 1 );
	++inDegree[ 1 ];
	Gvec[ 1 ].push_back( 2 );
	++inDegree[ 2 ];
	Gvec[ 2 ].push_back( 3 );
	++inDegree[ 3 ];
	Gvec[ 2 ].push_back( 4 );
	++inDegree[ 4 ];
	
	cout << endl << topologicalSort( Gvec, inDegree, N );
	return 0;
}