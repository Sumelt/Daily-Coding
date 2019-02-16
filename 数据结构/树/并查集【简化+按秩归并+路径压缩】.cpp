/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
using namespace std;
const int MaxSize = 50;
int array[ MaxSize+1 ];

int Find( int value ) //路径压缩 
{
	int Index = value; 
	if( array[ Index ] < 0 ) 
		return Index;  //找到根
	else 
		return array[ Index ] = Find( array[ Index ] );  //尾递归 
}

void Union( int value1, int value2 ) //按秩归并：树的高度 
{
	int root1 = Find( value1 );
	int root2 = Find( value2 );
	if( root1 < root2 ) //1 比 2的树高度要大，
		array[ root2 ] = root1--; //高度加 1 
	else if( root1 > root2 )
		array[ root1 ] = root2--;
	
}


void Inert_Connect( int value1, int value2 )
{
	Union( value1, value2 );
}


void Check_Connect( int value1, int value2 )
{
	int root1 = Find( value1 );
	int root2 = Find( value2 );
	if( root1 == root2 )
		cout << "yes" <<endl;
	else cout << "no" <<endl;
}


void Check_Connect_Sum( int n )
{
	int count = 0;
	for( int i = 1; i <= n; ++i )
		if( array[ i ] < 0 ) ++count;
	if( count > 0 )
		cout << "There are " << count << "components.";
	else cout << "The network is connected.";
}


int main(int argc, char *argv[])
{
	
	int N, value1, value2;
	char C;
	cin >> N;
	fill( array, array+N+1, -1 );
	for( ; N > 0; --N )
	{
		cin >> C >> value1 >> value2;
		cin.get();
		switch( C )
		{
			case 'C' : Check_Connect( value1, value2 ); break;
			case 'I' : Inert_Connect( value1, value2 ); break;
			case 'S' : Check_Connect_Sum( N ); break;
		} 
	}
	return 0;
}

