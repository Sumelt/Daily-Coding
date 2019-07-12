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
    double calculation( double base, int exp ) {
        if( exp == 0 )
            return 1.0;
        if( exp == 1 )
            return base;
        double res = calculation( base, exp >> 1 );
        res *= res;
        
        if( exp & 0x01 )
            res *= base;
        return res;
    }
    double Power(double base, int exponent) {
        //error input
        if( base == 0 && exponent < 0 )
            return 0.0;
        int absExp = abs( exponent );
        double res = calculation( base, absExp );
        return ( exponent < 0 ? 1.0 / res : res );
    }
};

int main(int argc, char *argv[])
{
	
	return 0;
}