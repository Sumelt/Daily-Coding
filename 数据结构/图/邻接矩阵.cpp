/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <cassert>
#include "../random_number.h"
#include "../openFile.h"
#include "./components.h"
using namespace std;

namespace AdjacencyMatrix {
class Densegraph{
	//friend class adjIterator;
	private:
		int sumPoint;
		int countEdge;
		bool directed; 
		vector<vector<bool>>graph;
	public:
		Densegraph( int count, bool	directed ) {
			this->sumPoint = count;
			this->countEdge = 0;
			this->directed = directed;
			
			for( int i = 0; i < count; ++i ) 
				graph.push_back( vector<bool>( count, false ) );//初始化图为彼此不连通 
				
		}
		~Densegraph() {
			
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
			if( hasEdge( v, w ) ) //两点已经存在边了 
				return;
				
			graph[ v ][ w ] = true;
			if( !directed )//如果是无向图 
				graph[ w ][ v ] = true;//彼此都要连接
				 
			++countEdge;//边数加1 
		}
		
		bool hasEdge( int v, int w ) {
			assert( v >= 0 && v < sumPoint );
			assert( w >= 0 && w < sumPoint );
			
			return graph[ v ][ w ];
		}
		
		void show() {
			cout << "Densegraph graph show: " << endl;
			for( int i = 0; i < sumPoint; ++i ) {
				cout << "vertex" << i << ": ";
				for( int index = 0; index < graph[ i ].size(); ++index )
					cout << graph[ i ][ index ] << " ";
				cout << endl;
		}
	}		
		
	//迭代器类 ，遍历于某个点相连的所有点 
class adjIterator{
//friend class Densegraph;
private:
	int index;
	int v;
	Densegraph &G;
public:
	adjIterator( Densegraph &graph, int v ) : G( graph ){
		assert( v >= 0 && v < G.sumPoint );
		this->v = v;
		this->index = -1;
		
	}
	~adjIterator() {
		
	}
	
	int begin() {
		index = -1;
		return next();
	}
	
	int next() {
		for( index +=1; index < G.getPointSum(); ++index )
			if( G.graph[ v ][ index ] )
				return index;
		return -1;
	}

	bool end() {
				return index >= G.getPointSum();
			}
		};
	};
}

void inputNumber( int sumPoint, int sumEdge )
{
	using namespace AdjacencyMatrix;
	
	srand( time(NULL) );//设置随机种子 
	
	Densegraph graph( sumPoint, false );
	for( int i = 0; i < sumEdge; ++i ) {
		int a = rand() % sumPoint; //产生从 0 到 sumPoint - 1的随机数 
		int b = rand() % sumPoint;
		
		graph.addEdge( a, b ); //两者建立一条边 
	}
	//从0点开始迭代 
	for( int v = 0; v < sumPoint; ++v ) {
		cout << v << " : ";
		Densegraph::adjIterator adj( graph, v );
		for( int w = adj.begin(); !adj.end(); w = adj.next() )
			cout << w << ' ';
			
		cout << endl;
	}	
}

void openfileGraph( string &filePath, int sumPoint )
{
	using namespace graphFile;
	using namespace AdjacencyMatrix;

	Densegraph graph( sumPoint, false );
	readGraph<Densegraph> gFile( graph, filePath );
	component<Densegraph>comp( graph );
	cout << comp.getCcount();	
	//graph.show();
	
}

int main(int argc, char *argv[])
{
	
	int sumPoint = 6;
	string filename = "./testG2.txt";
	openfileGraph( filename, sumPoint );	
	
	return 0;
}