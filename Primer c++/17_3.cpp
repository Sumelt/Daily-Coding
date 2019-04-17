/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <random>
#include <ctime>
using namespace std;


int main(int argc, char *argv[])
{
	default_random_engine e;
	//uniform_real_distribution<double> u( 0, 1 );
	bernoulli_distribution b( 0.6 );
	int t = 0;
	int f = 0;
	for( int i = 0; i < 100000; ++i ) {
		if( b( e ) )
			++t;
		else ++f;
	}
	cout << (double)t / 10000 << ' ' << ( double )f / 10000;
	
	return 0;
}