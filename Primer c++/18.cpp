/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <stdexcept>
#include "18.h"
using namespace std;

namespace space{
	int value;
}

namespace space{
	char c = 3;
}

namespace sp = space;


void Print() 
{
	
	try {
		throw( logic_error( "this is logic error" ) );
		cout << "OK";		
	}
	catch( bool ) {
		cout << "catch bool_error";
	}
	catch( logic_error err ) {
		cout << "catch logic_error" << endl;
		cout << err.what() << endl;
	}
}



int main(int argc, char *argv[])
{
	Print();
	return 0;
}