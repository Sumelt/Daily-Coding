/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <queue>
using namespace std;

void StackSort( priority_queue<char, vector<char>, 
	greater<char> > *Minstack, char *array )
{
	int i = 0;
	while( !Minstack->empty() )
	{
		 array[ i++ ] = Minstack->top();
		 Minstack->pop();
	}
		
}

int main(int argc, char *argv[])
{
	char array[] = {'2','5','9','1','3','8','6','0','7','4'};
	auto start = begin( array );
	auto last = end( array );
		
	priority_queue<char, vector<char>, greater<char> >quePriority( start, last );	
	
	StackSort( &quePriority, array );
		
	start = begin( array );
	last = end( array );
	while( start != last )
		cout << *start++ << ' ';
		
	return 0;
}