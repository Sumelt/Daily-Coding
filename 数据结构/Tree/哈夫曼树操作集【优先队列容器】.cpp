/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <queue>
#include <vector> 
using namespace std;

int main(int argc, char *argv[])
{
	int array[] = {3,1,2,5,4};
	int i,j;
	int res = 0; //哈夫曼树的带权路径值 
	priority_queue< int, vector<int>, greater<int> >pque;  //最小堆
	for( int i = 0; i < ( sizeof(array)/sizeof(*array) ); ++i )
		pque.push( array[ i ] );
	while( pque.size() > 1 )
	{
		i = pque.top();
		pque.pop();
		j = pque.top();
		pque.pop();
		pque.push( j + i );
		res += i +j;
	}
	cout << res;
	return 0;
}

