/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
using namespace std;

double calPowerExponent( double base, int exponent )
{
	if( exponent == 0 )
		return 1;
	if( exponent == 1 )
		return base;
	double res = calPowerExponent( base, exponent >> 1 );
	res *= res; //快速乘方算法 
	
	if( exponent & 0x01 ) //幂是负数则要多乘一次基数 
		res *= base;
	return res;	
}

double Power(double base, int exponent) {
    try {
    	if( base == 0.0 && exponent < 0 )
    	throw( true );
    }
    catch( bool ) { //捕捉任何的异常 
    	cout << 0.0 << endl;	
    }
	 	
   	unsigned int absExpont = (unsigned int)abs( exponent );
   	double res = calPowerExponent( base, absExpont );
   	if( exponent < 0 ) //幂为负 
   		res = 1.0 / res; //结果为倒数 
	return res;
}

int main () {
  	cout <<Power( 0.0, -2 );
  	return 0;
}
