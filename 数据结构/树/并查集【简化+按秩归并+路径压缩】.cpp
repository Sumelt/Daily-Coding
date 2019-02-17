/*----------------------------------------------------------------

* @Author: Su

* @Description: File Transfer

5
C 3 2 -> no 
I 3 2
C 1 5 ->no
I 4 5
I 2 4
C 3 5 ->yes
I 1 3
C 1 5 ->yes
S
      ->The network is connected.
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
	else array[ root2 ] = root1; //树高相等 
}


void Inert_Connect()
{
	int value1, value2;
	cin >> value1 >> value2;
	Union( value1, value2 );
}


void Check_Connect()
{
	int value1, value2;
	cin >> value1 >> value2;
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
	if( count > 1 )
		cout << "There are " << count << " components.";
	else cout << "The network is connected.";
}


int main(int argc, char *argv[])
{
	
	int N, value1, value2;
	char C;
	cin >> N;
	cin.get();
	fill( array, array+N+1, -1 );
	do
	{
		cin >> C;
		switch( C )
		{
			case 'C' : Check_Connect(); break;
			case 'I' : Inert_Connect(); break;
			case 'S' : Check_Connect_Sum( N ); break;
		} 
	}while( C != 'S' );
	return 0;
}

