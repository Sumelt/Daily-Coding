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
#include "./Path.h"
using namespace std;

namespace AdjacencyTable {
	class Sparsegraph {
		//friend class adjIterator;
	private:
		int sumPoint;
		int countEdge;
		bool directed;
		vector<vector<int>>graph;//存放的是相连的点 
	public:
		Sparsegraph( int count, bool directed )	{
			this->sumPoint = count;
			this->directed = directed;
			this->countEdge = 0;
			
			for( int i = 0; i < count; ++i )
				graph.push_back( vector<int>() );
		}
		~Sparsegraph() {
			
		}
		
		int getPointSum() {
			return sumPoint;
		}

		int getEdgeSum() {
			return countEdge;
		}
				
		void addEdge( int v, int w ) {			
			assert( v >= 0 && v < sumPoint );
			assert( w >= 0 && w < sumPoint );
			
			if( hasEdge( v, w ) ) //假设不存在平行边 
				return;
				
			graph[ v ].push_back( w );
			if( v != w && !directed )//排除自环边&&如果是无向图 
				graph[ w ].push_back( v );//彼此都要连接
				 
			++countEdge;//边数加1 
		}
		
		bool hasEdge( int v, int w ) {
			assert( v >= 0 && v < sumPoint );
			assert( w >= 0 && w < sumPoint );
			
			for( int i = 0; i < graph[ v ].size(); ++i )
				if( graph[ v ][ i ] == w )
					return true;
			return false;
		}
		void show() {
			cout << "Sparsegraph graph show: " << endl;
			for( int i = 0; i < sumPoint; ++i ) {
				cout << "vertex" << i << ": " ;
				for( int index = 0; index < graph[ i ].size(); ++index )
					cout << left << graph[ i ][ index ] << ' ';
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
	adjIterator( Sparsegraph &graph, int v ) : G( graph ) {
		this->v = v;
		this->index = 0;
	}
	~adjIterator() {
		
	}
		
	int begin() {
		index = 0;
		if( G.graph[ v ].size() )//该点存在和其他点相连 
			return G.graph[ v ][ index ];//返回和该点第一个相连的点 
		return -1;
	}
	
	int next() {
		++index;
		if( index < G.graph[ v ].size() )
			return G.graph[ v ][ index ];
		return -1;
	}
	
	bool end() {
				return index >= G.graph[ v ].size();		
			}		
		};
	};
}

void inputNumber( int sumPoint, int sumEdge )
{
	using namespace AdjacencyTable;
	srand( time(NULL) );//设置随机种子 
	
	Sparsegraph graph( sumPoint, false );
	for( int i = 0; i < sumEdge; ++i ) {
		int a = rand() % sumPoint; //产生从 0 到 sumPoint - 1的随机数 
		int b = rand() % sumPoint;
		
		graph.addEdge( a, b ); //两者建立一条边 
	}
	//从0点开始迭代 
	for( int v = 0; v < sumPoint; ++v ) {
		cout << v << " : ";
		Sparsegraph::adjIterator adj( graph, v );
		for( int w = adj.begin(); !adj.end(); w = adj.next() )
			cout << w << ' ';
			
		cout << endl;
	}	
}

void openfileGraph( string &filePath, int sumPoint )
{
	using namespace graphFile;
	using namespace AdjacencyTable;

	Sparsegraph graph( sumPoint, false );
	readGraph<Sparsegraph> gFile( graph, filePath );
	//component<Sparsegraph>comp( graph );
	//cout << comp.getCcount();
	//cout << comp.isConnect( 4, 3 );
	//graph.show();
	//Path<Sparsegraph> vertexPath( graph, 0 );
	ShortPath<Sparsegraph> vertexPath( graph, 0 );
	vertexPath.showPath( 6 );
}

int main(int argc, char *argv[])
{
	using namespace AdjacencyTable;
	
	//int sumPoint = 20;//20个点 
	//int sumEdge = 100;//一百条边 
	int sumPoint = 13;
	string filename = "./testG1.txt";
	openfileGraph( filename, sumPoint );
	
	return 0;
}