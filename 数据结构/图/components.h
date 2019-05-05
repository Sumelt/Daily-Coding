/*
 *求出图的连通分量 
 *
 */
 
#ifndef __COMPONENDTS_H__
#define __COMPONENDTS_H__

#include <cassert>
#include <cstring>

template<typename G>
class component{
private:
	int ccount; //连通分量的个数
	bool *visted; //是否访问标记
	int *id; //记录改点属于哪一个连通分量 
	G &Graph;
	void DFS( int v ) {
		visted[ v ] = true; //标记已经访问过
		id[ v ] = ccount;
		typename G::adjIterator iter( Graph, v );
		
		//遍历于该点所有相连的点 
		for( int index = iter.begin(); !iter.end(); index = iter.next() )
			if( !visted[ index ] )
				DFS( index );
	}
	
public:
	component( G &graph ) : Graph( graph ) {		
		this->ccount = 0;
		visted = new bool [ Graph.getPointSum() ]();
		id = new int [ Graph.getPointSum() ]();
		
		for( int i = 0; i < Graph.getPointSum(); ++i )
			if( !visted[ i ] ) {
				DFS( i );
				++ccount;
			}
	}
	~component() {
		delete []visted;
		delete []id;
	}
	
	int getCcount() {
		return ccount;
	}
	
	bool isConnect( int v, int w ) {
		assert( v >=0 && v < Graph.getPointSum() );
		assert( w >=0 && w < Graph.getPointSum() );
		return id[ v ] == id[ w ];
	}
};


#endif