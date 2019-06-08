/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <cassert>
#include "./linkList.h"

int main(int argc, char *argv[])
{
	List<int>list;	
	for( int i = 0; i < 10; ++i )
		list.InsertBack( i );
	list.Insert( 20, 3 );
	list.Print();
	cout << list.Find( 5 ) << endl;
	cout << list.Get( 4 ) << endl;
	list.remove( 3 );
	list.Print();
	list.removeFront();
	list.Print();
	list.removeBack();
	list.Print();
	return 0;
}