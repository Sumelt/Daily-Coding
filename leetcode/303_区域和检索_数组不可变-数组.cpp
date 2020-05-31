/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class NumArray {
private:
	int *sum;
public:
    NumArray(vector<int>& nums) {
		if( nums.size() > 0 ) {
			sum = new int [ nums.size() + 1 ]();
			for( int i = 1; i < nums.size() + 1; ++i )
				sum[ i ] = sum[ i - 1 ] + nums[ i - 1 ];
		}
    }
    
    int sumRange(int i, int j) {
		return sum[ j + 1 ] - sum[ i ];
    }
};

int main(int argc, char *argv[])
{
	
	return 0;
}