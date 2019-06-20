/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int jumpFloor(int number) {
  		vector<int>array = { 0, 1, 2 };
  		
  		if( number < 3 )
  			return array[ number ];
		for( int i = 3; i <= number; ++i )
			array.push_back( array[ i - 2 ] + array[ i - 1 ] );
  		
  		return array[ number ];
    }
};

int main(int argc, char *argv[])
{
	
	return 0;
}