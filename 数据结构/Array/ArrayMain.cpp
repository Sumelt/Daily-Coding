/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include "./array.h"

int main(int argc, char *argv[])
{
	Array<int> ary( 8 );
	for( int i = 0; i < 8; ++i )
		ary.push_front( i );
	ary.remove_back();
	ary.remove_back();
	ary.remove_back();
	ary.remove_back();
	ary.remove_back();
	ary.remove_back();
	ary.print();
//	ary.set( 2, 900 );
//	ary.print();
//	cout << ary.find( 2 );
//	ary.remove_front();
//	ary.print();
//	ary.remove_back();
//	ary.print();
	return 0;
}