#ifndef __TOPOLOGY_H__
#define __TOPOLOGY_H__

#include <queue>
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

			typename Graph::adjIterator iter( G, top );
			for( Edge<Weight>*edge = iter.begin(); !iter.end(); edge = iter.next() ) {
				int nextIndex = edge->retW();
				--inDegree[ nextIndex ];
				if( inDegree[ nextIndex ] == 0 )
					que.push( nextIndex );				
			}		
		}
	}
	
	~Topology() {
		delete [] inDegree;
	}
	
	bool isAcyclicGraph() {
		return sumPushV == G.getPointSum();
	}
};


#endif