/*
 *最小生成树算法 
 */

#ifndef __PRIM_H__
#define __PRIM_H__

#include <queue>
#include <vector>
#include <cassert>
#include "./minHeap.h"

template<typename Graph, typename Weight>
class Prim {
private:
	Graph &G;
	bool *visted;
	MinIndexHeap<Weight>minHeap;
	vector<Edge<Weight>*>toEgde;//该点对应的边  
	vector<Edge<Weight>>saveEdge;
	Weight weightSum;
		
	void vistVertex( int v ) {
		assert( !visted[ v ] );
		visted[ v ] = true;
		
		typename Graph::adjIterator iter( G, v );
		for( Edge<Weight>*edge = iter.begin(); !iter.end(); edge = iter.next() )
			if( !visted[ edge->retOtherVertex( v ) ] ) {
				int w = edge->retOtherVertex( v );
				if( !toEgde[ w ] ) {
					toEgde[ w ] = edge;
					minHeap.insert( w, edge->retWeight() );
				}					
				else if( edge->retWeight() < toEgde[ w ]->retWeight() ) {
					toEgde[ w ] = edge;
					minHeap.change( w, edge->retWeight() );
				}					
			}				
	}
	
public:
	Prim( Graph &graph ) : G( graph ), minHeap( graph.getPointSum() ) {
		visted = new bool[ graph.getPointSum() ]();
		for( int i = 0; i < graph.getPointSum(); ++i )
			toEgde.push_back( nullptr );			
		this->weightSum = 0;
		
		vistVertex( 0 );
		
		while( !minHeap.isEmpty() ) {
			int w = minHeap.popMinIndex();
//			cout << "pop:" << w << endl;
			assert( toEgde[ w ] );
			saveEdge.push_back( *toEgde[ w ] );//说明是横切边，加入最小生成树中
			weightSum += toEgde[ w ]->retWeight();
			vistVertex( w );//下次访问该点 
		}
		//minHeap.test();
	}
	~Prim() {
		delete []visted;
	}
	vector<Edge<Weight>> retAllEdge() {
		return saveEdge;
	}
	Weight retWeightSum() {
		return weightSum;
	}
	
};


#endif