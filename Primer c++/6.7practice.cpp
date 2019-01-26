/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
using namespace std;

int printAdd( int Lnum, int Rnum )
{
	return Lnum + Rnum;
}

int printSub( int Lnum, int Rnum )
{
	return Lnum - Rnum;
}

int printMul( int Lnum, int Rnum )
{
	return Lnum * Rnum;
}

int printDiv( int Lnum, int Rnum )
{
	return Lnum / Rnum;
}

typedef decltype(printAdd) *myPrint;
int main(int argc, char *argv[])
{
	//vector<decltype(printAdd)*>vecptr;
//	vecptr.push_back( printAdd );
//	vecptr.push_back( printSub );
//	vecptr.push_back( printMul );
//	vecptr.push_back( printDiv );
//	for( auto indx : vecptr )
//		(*indx)( 1, 2 );
	//decltype( printDiv ) *myPrint;
	myPrint test = nullptr;
	test = printDiv;
	cout << test( 1, 2 );
	
	return 0;
}




