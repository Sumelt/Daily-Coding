/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <cassert>
#include <stack>
#include <algorithm>
#include <array>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
		for( int i = digits.size() - 1; i >= 0; --i ) {
			digits[ i ] = ( digits[ i ] + 1 ) % 10;
			if( digits[ i ] != 0 )
				return digits;
		}
		int cnt = digits.size() + 1;
		int *ary = new int[ cnt ]();
		ary[ 0 ] = 1;
		return vector<int>( ary, ary + cnt );		
    }
};

int main(int argc, char *argv[])
{
	vector<int>array;
	cout << array.capacity();
	return 0;
}