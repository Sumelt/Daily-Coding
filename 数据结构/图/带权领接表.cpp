/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <cassert>
#include <iomanip>
#include "../random_number.h"
#include "../openFile.h"
#include "./components.h"
#include "./Edge.h"
using namespace std;

namespace AdjacencyTable {
template<typename Weight>
class Sparsegraph {
	//friend class adjIterator;
private:
	int sumPoint;
	int countEdge;
	bool directed;
	vector< vector<Edge<Weight>* > >graph;//存放的是相连的点 
public:
	Sparsegraph( int count, bool directed )	{
		this->sumPoint = count;
		this->directed = directed;
		this->countEdge = 0;
		
		for( int i = 0; i < count; ++i )
			graph.push_back( vector<Edge<Weight>*>() );
	}
	~Sparsegraph() {
		
	}
	
	int getPointSum() {
		return sumPoint;
	}

	int getEdgeSum() {
		return countEdge;
	}
			
	void addEdge( int v, int w, Weight weight ) {			
		assert( v >= 0 && v < sumPoint );
		assert( w >= 0 && w < sumPoint );
		
		//允许重复的边存在 
//		if( hasEdge( v, w ) ) //假设不存在平行边 
//		{
//			
//			for( int i = 0; i < graph[ v ].size(); ++i )
//				
//		}
			
		graph[ v ].push_back( new Edge<Weight>( v, w, weight ) );
		if( v != w && !directed )//排除自环边&&如果是无向图 
			graph[ w ].push_back( new Edge<Weight>( w, v, weight ) );//彼此都要连接
			 
		++countEdge;//边数加1 
	}
	
	bool hasEdge( int v, int w ) {
		assert( v >= 0 && v < sumPoint );
		assert( w >= 0 && w < sumPoint );
		
		for( int i = 0; i < graph[ v ].size(); ++i )
			if( ( graph[ v ][ i ] )->retW() == w )
				return true;
		return false;
	}
	void show() {
		cout << "Sparsegraph graph show: " << endl;
		for( int i = 0; i < sumPoint; ++i ) {
			cout << "vertex" << i << ": " ;
			for( int index = 0; index < graph[ i ].size(); ++index )
				//cout << left << graph[ i ][ index ] << ' ';
				cout << "( to:" << graph[ i ][ index ]->retW() 
					<<", weight:" << graph[ i ][ index ]->retWeight()<< ") ";
			cout << endl;
		}
	}
	
	//迭代器类 
class adjIterator{
	//friend class Sparsegraph;
private:
	Sparsegraph &G;
	int v; //迭代某一点的所有相连的点 
	int index;	

public:			
	adjIterator( Sparsegraph<Weight> &graph, int v ) : G( graph ) {
		this->v = v;
		this->index = 0;
	}
	~adjIterator() {
		
	}
		
	Edge<Weight>* begin() {
		index = 0;
		if( G.graph[ v ].size() )//该点存在和其他点相连 
			return G.graph[ v ][ index ];//返回和该点第一个相连的点 
		return nullptr;
	}
	
	Edge<Weight>* next() {
		++index;
		if( index < G.graph[ v ].size() )
			return G.graph[ v ][ index ];
		return nullptr;
	}
	
	bool end() {
				return index >= G.graph[ v ].size();		
			}		
		};
	};
}


void openfileGraph( string &filePath, int sumPoint )
{
	using namespace graphFile;
	using namespace AdjacencyTable;

	Sparsegraph<double> graph( sumPoint, false );
	readWeightGraph<Sparsegraph<double>, double> gFile( graph, filePath );
	graph.show();
}

int main(int argc, char *argv[])
{
	using namespace AdjacencyTable;
	
	//int sumPoint = 20;//20个点 
	//int sumEdge = 100;//一百条边 
	int sumPoint = 8;
	string filename = "./testWeightG1.txt";
	openfileGraph( filename, sumPoint );
	
	return 0;
}