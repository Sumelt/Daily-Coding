/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <cassert>
#include "./stackList.h"
using namespace std;
int main(int argc, char *argv[])
{
	StackList<int>stk;
	for( int i = 0; i < 9; ++i )
		stk.Push( i );
	stk.Print();
	stk.Pop();
	stk.Print();
	cout << stk.Top() << endl;
	cout << stk.Size() << endl;
	cout << stk.IsEmpty() << endl;	
	return 0;
}