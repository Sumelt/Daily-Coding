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
#include "./Edge.h"
#include "./lazyPrim.h"
#include "./prim.h"
using namespace std;

namespace AdjacencyMatrix {
template<typename Weight>
class Densegraph{
	//friend class adjIterator;
	private:
		int sumPoint;
		int countEdge;
		bool directed; 
		vector< vector< Edge<Weight>* > >graph;
	public:
		Densegraph( int count, bool	directed ) {
			this->sumPoint = count;
			this->countEdge = 0;
			this->directed = directed;
			
			for( int i = 0; i < count; ++i ) 
				graph.push_back( vector< Edge<Weight>* >( count, nullptr ) );
				//初始化图为彼此不连通 				
		}
		~Densegraph() {
			
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
			if( hasEdge( v, w ) ) //两点已经存在边了，删除旧的边，新增新边 
			{
				delete graph[ v ][ w ];
				graph[ v ][ w ] = new Edge<Weight>( v, w, weight );
				if( !directed ) {
					delete graph[ w ][ v ];
					graph[ w ][ v ] = new Edge<Weight>( w, v, weight );
				}
			}
			//两点原来不存在边	
			graph[ v ][ w ] = new Edge<Weight>( v, w, weight );
			if( !directed )//如果是无向图 
				graph[ w ][ v ] = new Edge<Weight>( w, v, weight );;//彼此都要连接
				 
			++countEdge;//边数加1 
		}
		
		bool hasEdge( int v, int w ) {
			assert( v >= 0 && v < sumPoint );
			assert( w >= 0 && w < sumPoint );
			
			return ( graph[ v ][ w ] != nullptr );
		}
		
		void show() {
			cout << "Densegraph graph show: " << endl;
			for( int i = 0; i < sumPoint; ++i ) {
				cout << "vertex" << i << ": ";
				for( int index = 0; index < graph[ i ].size(); ++index ) {
					if( graph[ i ][ index ] )//两节点不为空 
						cout << ( graph[ i ][ index ] )->retWeight() << " ";
					else cout << "NULL ";
				}					
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
	adjIterator( Densegraph<Weight> &graph, int v ) : G( graph ){
		assert( v >= 0 && v < G.sumPoint );
		this->v = v;
		this->index = -1;
		
	}
	~adjIterator() {
		
	}
	
	Edge<Weight>* begin() {
		index = -1;
		return next();
	}
	
	Edge<Weight>* next() {
		for( index +=1; index < G.getPointSum(); ++index )
			if( G.graph[ v ][ index ] != nullptr )
				return G.graph[ v ][ index ];
		return nullptr;
	}

	bool end() {
				return index >= G.getPointSum();
			}
		};
	};
}

//测试最小生成树算法 
using AdjacencyMatrix::Densegraph;
template<typename Weight>
void MinSpanTree( Densegraph<Weight>&graph ) {
	//LazyPrim<Densegraph<double>, double>primTree( graph );//最小生成树 
	Prim<Densegraph<double>, double>primTree( graph );//最小生成树 
	vector<Edge<Weight>>treePath = primTree.retAllEdge();//最小生成树的路径 
	
	for( int i = 0; i < treePath.size(); ++i )
		cout << treePath[ i ].retV() << " : " << treePath[ i ].retW() 
				<< " weight: " << treePath[ i ].retWeight() << endl;
				
	cout << "weightSum: " << primTree.retWeightSum();
}

//打开测试数据文本 
void openfileGraph( string &filePath, int sumPoint )
{
	using namespace graphFile;
	using namespace AdjacencyMatrix;

	Densegraph<double> graph( sumPoint, false );//表示一个权值类型为double的图 
	readWeightGraph<Densegraph<double>, double> gFile( graph, filePath );
	MinSpanTree( graph );
	//graph.show();
	//cout << graph.getPointSum();
	
}

int main(int argc, char *argv[])
{
	
	int sumPoint = 8;
	string filename = "./testWeightG1.txt";
	openfileGraph( filename, sumPoint );	
	
	return 0;
}