/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MaxSize = 10001;
int N;
int array[MaxSize][MaxSize];
bool vist[ MaxSize ];
int BFS( int index )
{
	int count = 1, lever = 0;
	int last, tail;
	queue<int>que;
	vist[ index ] = true;
	last = index;
	que.push( index );
	while( !que.empty() )
	{
		int top = que.front();
		que.pop();
		for( int i = 1; i <= N; ++i )
		{
			if( array[ top ][ i ] == 1 && !vist[ i ]) //有边 
			{
				que.push( i );
				vist[ i ] = true;
				count++;
				tail = i;
			}
		}
		if( top == last ) //该层已尽 
		{
			++lever;
			last = tail;
		}
		if( lever == 6 ) break;
		
	}
	return count;
}

void BFSlist( )
{
	int count;
	for( int i = 1; i <= N; ++i )
	{
		count = BFS( i );
		fill( vist, vist+N+1, 0 ); //恢复 
		printf( "%d: %.2f%\n", i, ((double)count/N)*100 );
	}
}

int main(int argc, char *argv[])
{
	int side, index1, index2;
	cin >> N >> side;
	
	for( int i = 0; i < side; ++i )
	{
		cin >> index1 >> index2;
		array[ index1 ][ index2 ] = 1;
		array[ index2 ][ index1 ] = 1;
	}
	BFSlist();
	return 0;
}

