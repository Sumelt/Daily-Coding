/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
using namespace std;

class Solution {
public:
	int NumberOf1( int number )
	{
		int count = 0;
		while( number != 0 ) {
			number = number & ( number - 1 );
			++count;
		}
		return count; 
	}
};

int main(int argc, char *argv[])
{
	
	return 0;
}