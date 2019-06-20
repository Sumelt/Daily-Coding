/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

//F(0) = 0,   F(1) = 1
//F(N) = F(N - 1) + F(N - 2), ?? N > 1.
class Solution {
private:
	long long achieveOne( int n ) {
		int array[ 2 ] = { 0, 1 };
		if( n < 2 )
			return ( n == 0 ? array[ 0 ] : array[ 1 ] );
		long long a = array[ 0 ];
		long long b = array[ 1 ];
		long long res = 0;
		for( int i = 2; i <= n; ++i ) {
			res = a + b;
			a = b;
			b = res;
		}
		return res;
	}
public:
    int fib( int N ) {
        return achieveOne( N );
    }
};

int main(int argc, char *argv[])
{
	
	return 0;
}