﻿/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <cassert>
#include "./queue.h"
#include "./loopQueue.h"
using namespace std;
int main(int argc, char *argv[])
{
	LoopQueue<int>que;	
	for( int i = 0; i < 10; ++i )
		que.Push( i );
	que.Print();
	que.Push( 20 );
	que.Print();
	que.Pop();
	que.Print();
	cout << que.Front() << endl;
	cout << que.Size() << endl;
	cout << que.IsFull() << endl;
	return 0;
}