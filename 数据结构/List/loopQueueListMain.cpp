/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include "./loopQueueList.h"
int main(int argc, char *argv[])
{
	LoopQueueList<int>loopQue;
	for( int i = 0; i < 9; ++i )
		loopQue.Push( i );
	loopQue.Print();
	loopQue.Pop();
	loopQue.Print();
	cout << loopQue.Front() << endl;
	cout << loopQue.Size() << endl;
	cout << loopQue.IsEmpty() << endl;	
	return 0;
}