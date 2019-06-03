/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <cassert>
#include "./queue.h"
using namespace std;
int main(int argc, char *argv[])
{
	Queue<int>que;
	
	for( int i = 0; i < 10; ++i )
		que.push( i );
	que.print();
//	que.push( 11 );
//	cout << que.front() << endl;
//	que.pop();
	cout << que.getSize() << endl;
	que.print();
	return 0;
}