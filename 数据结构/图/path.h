/*
 *找从图中某个到另一个点的路径 
 */
 
#ifndef __PATH_H__
#define __PATH_H__

#include <cassert>
#include <stack>
#include <vector>
#include <queue>
#include <cstring>
template<typename G>
class Path{
private:
	bool *visted; //是否访问标记
	int *from;//存储路径中该点的上一个点
	G &Graph;
	
	void DFS( int v ) {
		visted[ v ] = true; //标记已经访问过
		typename G::adjIterator iter( Graph, v );
		
		//遍历于该点所有相连的点 
		for( int index = iter.begin(); !iter.end(); index = iter.next() )
			if( !visted[ index ] ) {
				from[ index ] = v; //表示i点是从v点走过来的
			 	DFS( index );
			}				
	}	
 	
public:
	Path( G &graph, int source ) : Graph( graph ) {
		visted = new bool [ Graph.getPointSum() ]();
		from = new int [ Graph.getPointSum() ]();
		
		memset( from, -1, Graph.getPointSum() );
				
		DFS( source );			 	
	}
	~Path() {
		delete []from;
		delete []visted;
	}
	
	bool hasPath( int w ) {
		assert( w >=0 && w < Graph.getPointSum() );
		return visted[ w ];
	}
	
	void findPath( int w, vector<int> &vec ) {
		assert( w >=0 && w < Graph.getPointSum() );
		int lastVertex = w;
		stack<int>stk;
	
		while( lastVertex != -1 ) {
			stk.push( lastVertex );
			lastVertex = from[ lastVertex ];
		}
		
		vec.clear();
		while( !stk.empty() ) {
			vec.push_back( stk.top() );
			stk.pop();
		}
	}
	
	void showPath( int w ) {
		assert( w >=0 && w < Graph.getPointSum() );
		
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

//BFS的运用 
template<typename G>
class ShortPath{
private:
	bool *visted; //是否访问标记
	int *from;//存储路径中该点的上一个点
	int *ord;// 记录路径中节点的次序。ord[i]表示i节点在路径中的次序
	G &Graph;	 
public:
	ShortPath( G &graph, int source ) : Graph( graph ) {
		visted = new bool [ Graph.getPointSum() ]();
		from = new int [ Graph.getPointSum() ]();
		ord = new int [ Graph.getPointSum() ]();
		
		memset( from, -1, Graph.getPointSum() );
		memset( ord, 0, Graph.getPointSum() );
		
		queue<int>que;
		que.push( source );
		visted[ source ] = true;		
		while( !que.empty() ) {
			int v = que.front();
			que.pop();
			
			typename G::adjIterator iter( Graph, v );
			for( int index = iter.begin(); !iter.end(); index = iter.next() ) {
				if( !visted[ index ] ) {
					from[ index ] = v;				
					ord[ index ] = ord[ v ] + 1;
					visted[ index ] = true;
					que.push( index );									
				}
			}			
		}
							 	
	}
	~ShortPath() {
		delete []from;
		delete []visted;
		delete []ord;
	}
	
	bool hasPath( int w ) {
		assert( w >=0 && w < Graph.getPointSum() );
		return visted[ w ];
	}
	
	void findPath( int w, vector<int> &vec ) {
		assert( w >=0 && w < Graph.getPointSum() );
		int lastVertex = w;
		stack<int>stk;
	
		while( lastVertex != -1 ) {
			stk.push( lastVertex );
			lastVertex = from[ lastVertex ];
		}
		
		vec.clear();
		while( !stk.empty() ) {
			vec.push_back( stk.top() );
			stk.pop();
		}
	}
	
	void showPath( int w ) {
		assert( w >=0 && w < Graph.getPointSum() );
		
		vector<int>vec;
		findPath( w, vec );
		
		for( int i = 0; i < vec.size(); ++i ) {
			cout << vec[ i ];
			if( i == vec.size() - 1 )
				cout << endl;
			else cout << "-> ";
		}		
	}
	
	int shortLength( int w ) {
		return ord[ w ];
	}
 };
 
 #endif