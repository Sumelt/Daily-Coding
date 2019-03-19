/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	int array[] = { 6, 1, 2, 5, 4, 3, 9, 7, 10, 8 };
	int length = sizeof( array )/sizeof( *array );
			
	qSort( array, 0, length - 1 );
	
	auto start = begin( array );
	auto last = end( array );
	while( start != last )
		cout << *start++ << " ";
				
	return 0;
}
