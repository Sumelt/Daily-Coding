#ifndef __DIJKSTRA_H__
#define __DIJKSTRA_H__

#include <iostream>
#include <algorithm>
#include <cassert>
#include <vector>
#include <stack>
#include "./minHeap.h"

template<typename Graph, typename Weight>
class Dijkstra{
private:
	Graph &G;
	int sour;
	bool *visted;
	Weight *toVertexSum;
	vector<Edge<Weight>*>from;
	MinIndexHeap<Weight>minHeap;	
	Weight weightSum;

public:
	Dijkstra( Graph &graph, int s ) : G( graph ), sour( s ), 
		minHeap( graph.getPointSum() )
	 {
				
		int sumVertex = graph.getPointSum();
		visted = new bool [ sumVertex ]();
		toVertexSum = new Weight [ sumVertex ]();
		for( int i = 0; i < sumVertex; ++i )
			from.push_back( nullptr );
		
		visted[ sour ] = true;
		toVertexSum[ sour ] = 0;
		minHeap.insert( sour, toVertexSum[ sour ] );
		
		while( !minHeap.isEmpty() ) {
			int v = minHeap.popMinIndex();
			visted[ v ] = true;
			typename Graph::adjIterator iter( G, v );
			for( Edge<Weight>*edge = iter.begin(); !iter.end(); edge = iter.next() ) {
				int w = edge->retOtherVertex( v );
				if( !visted[ w ] ) //该点没有被访问过
					if( !from[ w ] || edge->retWeight() + toVertexSum[ v ] < toVertexSum[ w ] ) {
						from[ w ] = edge;
						toVertexSum[ w ] = edge->retWeight() + toVertexSum[ v ];//新的权值 
						if( minHeap.contain( w ) )//最小堆中包含源点到该点的权值和 
							minHeap.change( w, toVertexSum[ w ] );//更新到该点的权值和 
						else 
							minHeap.insert( w, toVertexSum[ w ] );
				}
			}			
		}		
	}
	
	~Dijkstra() {
		delete []visted;
		delete []toVertexSum;
	}

    Weight shortestPathTo( int w ){
        assert( w >= 0 && w < G.getPointSum() );
        assert( hasPath( w ) );
        return toVertexSum[ w ];
    }
    
	bool hasPath( int w ) {
		assert( w >=0 && w < G.getPointSum() );
		return visted[ w ];
	}
	
	void findPath( int w, vector<int> &vec ) {
		assert( w >=0 && w < G.getPointSum() );
		int lastVertex = w;
		stack<int>stk;
	
		while( from[ lastVertex	 ] != nullptr ) {
			stk.push( lastVertex );
			lastVertex = from[ lastVertex ]->retOtherVertex( lastVertex );
		}
		stk.push( lastVertex );//压入源点 
		vec.clear();
		while( !stk.empty() ) {
			vec.push_back( stk.top() );
			stk.pop();
		}
	}
	
	void showPath( int w ) {
		assert( w >=0 && w < G.getPointSum() );
		
		vector<int>vec;
		findPath( w, vec );
		
		for( int i = 0; i < vec.size(); ++i ) {
			cout << vec[ i ];
			if( i == vec.size() - 1 )
				cout << endl;
			else cout << "-> ";
		}		
	}
};

#endif