/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <cassert>
using namespace std;

namespace UFversion1 {
const int MaxSize = 50;
struct setType{
	int data;
	int parentIndx;
	setType( int value, int father ) : data( value ), parentIndx( father ){}
	
};

int Find( setType *Set, int value )
{
	int i = 0;
	for( i; i < MaxSize && Set[ i ].data != value; ++i );
	if( i >= MaxSize ) return -1;
	else
		while( Set[ Set[i].parentIndx ].parentIndx >= 0 )
			i = Set[i].parentIndx;
	return Set[i].parentIndx;
}

void Union( setType *Set, int value1, int value2 ) {
	int root1 = Find( Set, value1 );
	int root2 = Find( Set, value2 );
	if( root1 != -1 && root2 != -1 && root2 != root1 )
		Set[ root2 ].parentIndx = root1; //把一个集合的根节点的父亲下标设置为另一个集合的父亲下标 
	}
/*** test

	setType Set[] = { setType( 1, -1 ), setType( 2, 0 ), setType( 3, 0 ),
		setType( 6, -1 ), setType( 8, 3), setType( 9, 3 ) };
	
	Union( Set, 2, 9 );
	
	for( int i = 0; i < 6; ++i )
	{
		cout << Set[ i ].data << ' ' << Set[ i ].parentIndx << endl; 
	}

***/	
}

namespace UFversion2 {
class UnionFind{
private:
	int count;
	int *array;
	int *rank;
	int *sz;
	
	//按秩归并 
	void UnionElementExtent( int p, int q ) {
		int proot = find( p );			
		int qroot = find( q );
		
		if( proot == qroot )
			return;
		//优化一：按数量规模归并 
		if( sz[ proot ] < sz[ qroot ] ) {
			array[ proot ] = qroot;//连接根节点 
			sz[ qroot ] += sz[ proot ];
		}
		else {
			array[ qroot ] = proot;//连接根节点 
			sz[ proot ] += sz[ qroot ];				
		}
		
	}
	//优化二：按高度归并
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
			return find( element1 ) == find( element2 );
		}
	};	
}


int main(int argc, char *argv[])
{
	using namespace UFversion2;
	
	UnionFind object( 100 );
	object.unionElement( 2, 9 );
	cout << object.isConnect( 2, 9 );
	
	return 0;
}

