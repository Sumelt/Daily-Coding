/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template<typename Graph, typename Weight>
class Topology {
private:
	Graph &G;
	queue<int>que;
	int *inDegree;
	int sumPushV;
public:
	Topology( Graph &graph ) : G( graph ) {
		int sumVertex = G.getPointSum();
		inDegree = new int [ sumVertex ]();
		sumPushV = int();
		
		for( int i = 0; i < sumVertex; ++i ) {
			typename Graph::adjIterator iter( G, i );
			for( Edge<Weight>*edge = iter.begin(); !iter.end(); edge = iter.next() )
				++inDegree[ edge->retW() ];	
		}
		
		for( int i = 0; i < sumVertex; ++i )
			if( inDegree[ i ] == 0 )
				que.push( i );
			
		while( !que.empty() ) {
			int top = que.front();
			que.pop();
			++sumPushV; //记录入队的节点数 
			for( int i = 0; i < G[ top ].size(); ++i ) {
				int nextIndex = G[ top ][ i ];
				--inDegree[ nextIndex ];
				if( inDegree[ nextIndex ] == 0 )
					que.push( nextIndex );
			}
		}
	
	~Topology() {
		delete [] inDegree;
	}
	
	bool isAcyclicGraph() {
		return sumPushV == G.getPointSum();
	}
};


/*
bool topologicalSort( vector<int> *G, int *inDegree, int N )
{
	queue<int>que;
	int sumV = 0;
	for( int i = 0; i < N; ++i ) {
		if( inDegree[ i ] == 0 )
			que.push( i );
	}	
	while( !que.empty() ) {
		int top = que.front();
		cout << top << ' ';
		que.pop();
		++sumV; //记录入队的节点数 
		for( int i = 0; i < G[ top ].size(); ++i ) {
			int nextIndex = G[ top ][ i ];
			--inDegree[ nextIndex ];
			if( inDegree[ nextIndex ] == 0 )
				que.push( nextIndex );
		}
	}
	if( sumV == N ) return true;
	else return false;
	
}*/

/*
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
}*/