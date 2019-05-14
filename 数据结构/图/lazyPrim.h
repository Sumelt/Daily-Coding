/*
 *最小生成树 懒惰算法 
 */

#ifndef __LAZYPRIM_H__
#define __LAZYPRIM_H__

#include <queue>
#include <vector>
#include <cassert>

template<typename Graph, typename Weight>
class LazyPrim{
private:
	Graph &G;
	bool *visted;
	vector<Edge<Weight>>saveEdge;
	Weight weightSum;
	
	struct cmp {
		bool operator()( Edge<Weight>&p, Edge<Weight>&q ) {
			return p.retWeight() > q.retWeight();
		}		
	};
	
	priority_queue< Edge<Weight>,vector<Edge<Weight>>, cmp > minHeap;
	
	void vistVertex( int v ) {
		assert( !visted[ v ] );
		visted[ v ] = true;
		
		typename Graph::adjIterator iter( G, v );
		for( Edge<Weight>*edge = iter.begin(); !iter.end(); edge = iter.next() )
			if( !visted[ edge->retW() ] )
				minHeap.push( *edge );//最小堆中压入和改点相连的边 
	}
	
public:
	LazyPrim( Graph &graph ) : G( graph ) {
		visted = new bool[ graph.getPointSum() ]();
		weightSum = 0;
		vistVertex( 0 );
		
		while( !minHeap.empty() ) {
			Edge<Weight> top = minHeap.top();
			minHeap.pop();
			
			if( visted[ top.retW() ] && visted[ top.retW() ] )//两点都访问过了 
				continue;
			else {
				saveEdge.push_back( top ); //其中有一点没有访问过，该边是横切边
				weightSum += top.retWeight();
			}  
			
			//下次访问该横切边中一端没有访问过的点 
			if( !visted[ top.retW() ] )
				vistVertex( top.retW() );
			else vistVertex( top.retV() );			
		}
	}
	~LazyPrim() {
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