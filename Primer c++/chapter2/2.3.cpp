/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	
	unsigned u = 10, u2 = 42;
	cout<< u2 - u <<endl; // 42 - 10 = 32
	cout<< u - u2 <<endl; //-32 % 2^32 = 4294967264
	
	int i = 10, i2 = 42;
	cout<< i2 - i <<endl; // 42 - 10 = 32
	cout<< i - i2 <<endl; //10 - 42 = -32
	cout<< i2 - u <<endl; // (unsigned)42 - 10 = 32
	cout<< u - i <<endl; //10 - 10 = 0
	return 0;
}



