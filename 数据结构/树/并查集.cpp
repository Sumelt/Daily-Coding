/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
using namespace std;
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

void Union( setType *Set, int value1, int value2 )
{
	int root1 = Find( Set, value1 );
	int root2 = Find( Set, value2 );
	if( root1 != -1 && root2 != -1 && root2 != root1 )
		Set[ root2 ].parentIndx = root1; //把一个集合的根节点的父亲下标设置为另一个集合的父亲下标 
}

int main(int argc, char *argv[])
{
	setType Set[] = { setType( 1, -1 ), setType( 2, 0 ), setType( 3, 0 ),
		setType( 6, -1 ), setType( 8, 3), setType( 9, 3 ) };
	
	Union( Set, 2, 9 );
	
	for( int i = 0; i < 6; ++i )
	{
		cout << Set[ i ].data << ' ' << Set[ i ].parentIndx << endl; 
	}
	
	return 0;
}

