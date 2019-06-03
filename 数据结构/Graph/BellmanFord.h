#ifndef __BELLMANFORD_H__
#define __BELLMANFORD_H__

#include <iostream>
#include <algorithm>
#include <cassert>
#include <vector>

template<typename Graph, typename Weight>
class BellmanFord{
private:
	Graph &G;
	int sour;
	bool hasNegativeCycle;
	Weight *toVertexSum;
	vector<Edge<Weight>*>from;	
	Weight weightSum;

	//最后一次松弛操作 
	bool detectNegativeCycle() {
		int sumVertex = G.getPointSum();
		for( int vertexIndex = 0; vertexIndex < sumVertex; ++vertexIndex ) {
			typename Graph::adjIterator iter( G, vertexIndex );
			for( Edge<Weight>*edge = iter.begin(); 
										!iter.end(); edge = iter.next() ) {
		 		if( !from[ edge->retW() ] || 
				 	edge->retWeight() + toVertexSum[ edge->retV() ] 
					 						< toVertexSum[ edge->retW() ] ) 
				return true;					
			}
		}
		return false;		
	}
public:
	BellmanFord( Graph &graph, int s ) : G( graph ), sour( s ) {
				
		int sumVertex = graph.getPointSum();
		toVertexSum = new Weight [ sumVertex ]();
		for( int i = 0; i < sumVertex; ++i )
			from.push_back( nullptr );
			
		toVertexSum[ s ] = Weight();
		//V-1次松弛 
		for( int cnt = 1; cnt < sumVertex; ++cnt ) {
			//对图中每一个点遍历 
			for( int vertexIndex = 0; vertexIndex < sumVertex; ++vertexIndex ) {
				typename Graph::adjIterator iter( G, vertexIndex );
				//对该点的所有相连的边直接遍历 
				for( Edge<Weight>*edge = iter.begin(); 
											!iter.end(); edge = iter.next() )
				{
			 		//可以松弛，更新权值 
					 if( !from[ edge->retW() ] || 
					 	edge->retWeight() + toVertexSum[ edge->retV() ] 
						 						< toVertexSum[ edge->retW() ] ) {
						 from[ edge->retW() ] = edge;
						 toVertexSum[ edge->retW() ] = 
						 		toVertexSum[ edge->retV() ] + edge->retWeight();
					}					
				}
			}
		}
	 	hasNegativeCycle = detectNegativeCycle();			
	}

	~BellmanFord() {
		delete [] toVertexSum;
	}
	
	bool isNegativeCycle() {
		return hasNegativeCycle;//存在负权环返回真，否则返回假 
	}
	
    Weight shortestPathTo( int w ){
        assert( w >= 0 && w < G.getPointSum() );
        assert( !hasNegativeCycle );
        assert( hasPath( w ) );
        
        return toVertexSum[ w ];
    }
    
	bool hasPath( int w ) {
		assert( w >=0 && w < G.getPointSum() );
		return from[ w ] != nullptr;
	}
	
	void findPath( int w, vector<int> &vec ) {
		assert( w >=0 && w < G.getPointSum() );
		assert( !hasNegativeCycle );
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
		assert( !hasNegativeCycle );
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