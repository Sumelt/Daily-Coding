/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
//#include<bits/stdc++.h>
#include <vector>
#include <cassert>
using namespace std;

class MaximumCommonDivisor {
private:
	//欧几里得 
	int gcd1 ( int number1, int number2 ) {
		if( number1 % number2 == 0 )
			return number2;
		return gcd1( number2, number1 % number2 );
	} 
	//更相减损术
	int gcd2 ( int number1, int number2 ) {
		if( number1 == number2 ) 
			return number1;
		return gcd2( abs( number1 - number2 ), min( number1, number2 ) );
	} 	
	//欧几里得 +  更相减损术
	int gcd3 ( int number1, int number2 ) {
		if( number1 == number2 ) 
			return number1;
		//确保number1始终大于number2 
		if( number1 < number2 ) 
			return gcd3( number2, number1 );
			
		if( !( number1 & 0x01 ) && !( number2 & 0x01 ) ) 
			return gcd3( number1 >> 1, number2 >> 1 ) << 1;
		else if( !( number1 & 0x01 ) ) 
			return gcd3( number1 >> 1, number2 );
		else if( !( number2 & 0x01 ) ) 
			return gcd3( number1, number2 >> 1 );			
		else return gcd3( number1 - number2, min( number1, number2 ) ); 
	} 
public:
	int getMaximumCommonDivisor( int number1, int number2 ) {
		return gcd3( max( number1, number2 ), min( number1, number2 ) );
	}
};

int main(int argc, char *argv[])
{
	MaximumCommonDivisor oj;
	cout << oj.getMaximumCommonDivisor( 99, 66 );
	return 0;
}