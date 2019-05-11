/*
 *最小生成树的另一种实现算法 
 */
#ifndef __KRUSKAL_H__
#define __KRUSKAL_H__

#include "./minHeap.h"
namespace UFversion {
class UnionFind{
private:
	int count;
	int *array;
	int *rank;//高度 
	int *sz;//规模 
	
	//按秩归并 优化一：按数量规模归并 
	void UnionElementExtent( int p, int q ) {
		int proot = find( p );			
		int qroot = find( q );
		
		if( proot == qroot )
			return;
		
		if( sz[ proot ] < sz[ qroot ] ) {
			array[ proot ] = qroot;//连接根节点 
			sz[ qroot ] += sz[ proot ];
		}
		else {
			array[ qroot ] = proot;//连接根节点 
			sz[ proot ] += sz[ qroot ];				
		}
		
	}
	//按秩归并 优化二：按高度归并
	void UnionElementHight( int p, int q ) {
		int proot = findOptimization2( p );			
		int qroot = findOptimization2( q );
		
		if( proot == qroot )
			return;
			
		if( rank[ proot ] > rank[ qroot ] )
			array[ qroot ] = proot;
		else if( rank[ qroot ] > rank[ proot ] )
			array[ proot ] = qroot;
		else //rank[ qroot ] == rank[ proot ]
		{
			array[ qroot ] = proot;//连接根节点
			rank[ qroot ] +1; //变成下一层了 
		}
	}
		
 	//路径压缩 跳跃连接 
	int findOptimization1( int element ) {
	    assert( element >= 0 && element < count );
	    
	    while( element != array[ element ] ) {
	        array[ element ] = array[ array[ element ] ];//跳跃一个节点后再连接父节点
	        element = array[ element ];
	    }
	    return array[ element ];
	}
	//路径压缩 全部节点直接连接根根节点 
	int findOptimization2( int element ) {
		if( element == array[ element ] ) //最后一层的递归 
			return element;
		
		array[ element ] = findOptimization2( element );
		return array[ element ]; //其余层的递归返回结果 
	}

	int findNOTOptimization( int element ) {
		assert( element >= 0 && element < count );
		while( element != array[ element ] )
			element = array[ element ];//不断追溯最后的根节点 
		
		return array[ element ];
	}	
		
public:
	UnionFind( int size ) {
		count = size;
		array = new int[ size ]();
		sz = new int[ size ]();
		rank = new int[ size ]();
		
		for( int i = 0; i < size; ++i ) {
			array[ i ] = i;
			sz[ i ] = 1;
			rank[ i ] = 1;
		}				
	}
	~UnionFind() {
		delete []array;
		delete []sz;
		delete []rank;
	}
	
	int find( int element ) {
		return findOptimization1( element );
	}
	
	void unionElement( int p, int q ) {
		UnionElementExtent( p, q );
	}
	
	bool isConnect( int element1, int element2 ) {
			return findOptimization1( element1 ) 
					== findOptimization1( element2 );
		}
	};	
}

template<typename Graph, typename Weight>
class Kruskal {
private:
	Graph &G;
	MinIndexHeap<Edge<Weight>>minHeap;//存放边的最小堆 
	vector<Edge<Weight>*>toEgde;//该点对应的边  
	vector<Edge<Weight>>saveEdge;
	UFversion::UnionFind unionFind;
	Weight weightSum;
		
public:
	Kruskal( Graph &graph ) : G( graph ),
		minHeap( graph.getEdgeSum() ), unionFind( graph.getEdgeSum() ) {
		int sumVertex = graph.getPointSum();
		for( int i = 0; i < sumVertex; ++i ) {
			typename Graph::adjIterator iter( G, i );
			for( Edge<Weight>*edge = iter.begin(); !iter.end(); edge = iter.next() )
				if( edge->retV() < edge->retW() )
					minHeap.insert( *edge );
		}
		
		while( !minHeap.isEmpty() && saveEdge.size() < sumVertex - 1 ) {
			Edge<Weight> top = minHeap.popMinItem();
						
			if( !unionFind.isConnect( top.retV(), top.retW() ) ) {
				unionFind.unionElement( top.retV(), top.retW() );
				saveEdge.push_back( top );
				weightSum += top.retWeight();
			}
		}
	}
	~Kruskal() {
	
	}
	
	vector<Edge<Weight>> retAllEdge() {
		return saveEdge;
	}
	Weight retWeightSum() {
		return weightSum;
	}
	
};

#endif