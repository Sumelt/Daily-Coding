/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include "./stack.h"
using namespace std;
int main(int argc, char *argv[])
{
	Stack<int>stk;
	for( int i = 0; i < 9; ++i )
		stk.push( i );
	stk.print();
	stk.pop();
	stk.print();
	cout << stk.top();
	cout << stk.getSize() << endl;
	cout << stk.isEmpty() << endl;
	return 0;
}