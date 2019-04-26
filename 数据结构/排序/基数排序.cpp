/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include "../random_number.h"
using namespace std;

//template <typename T>
//void sort( T *arr, int length ) {
//			
//}

int getMax( int *arr, int n ) {
	int max = arr[ 0 ];
	for( int i = 1; i < n; ++i )
		if( arr[ i ] > max )
			max = arr[ i ];
	return max;
}

void countSort( int *arr, int n, int exp ) {
	int outPut[ n ];
	int i, count[ 10 ] = { 0 };
	
	for( int i = 0; i < n; ++i ) {
		count[ ( arr[ i ]/exp )%10 ]++;
		//cout << "count[ ( arr[ i ]/exp )%10 ]: " << count[ ( arr[ i ]/exp )%10 ] << endl;
	}
	cout << "one for" << endl;
		
	for( i = 1; i < 10; ++i ) {
		count[ i ] +=count[ i - 1 ];
		//cout << "count[ i ] +=count[ i - 1 ]]: " << count[ i ] << endl;
	}
	//cout << "two for" << endl;	
		
	for( i = n - 1; i >= 0; --i ) {
		cout << "before outPut[ count[ ( arr[ i ] / exp ) % 10 ] - 1 ]: " << outPut[ count[ ( arr[ i ] / exp ) % 10 ] - 1 ] << endl;
		outPut[ count[ ( arr[ i ] / exp ) % 10 ] - 1 ] = arr[ i ];
		cout << "outPut[ count[ ( arr[ i ] / exp ) % 10 ] - 1 ]: " << outPut[ count[ ( arr[ i ] / exp ) % 10 ] - 1 ] << endl;
		count[ ( arr[ i ] / exp )%10 ]--;
		//cout << "count[ ( arr[ i ] / exp )%10 ]--: " << count[ ( arr[ i ] / exp )%10 ] << endl;
	}
	//cout << "three for" << endl;
	
	for( i = 0; i < n; ++i ) {
		arr[ i ] = outPut[ i ];
		//cout << "arr[ i ]" << arr[ i ] << ends;
	}
	//cout << "end for" << endl;	
}

void radixSort( int *arr, int n ) {
	int m = getMax( arr, n );
	for( int exp = 1; m/exp > 0; exp *= 10 )
		countSort( arr, n, exp );
}


int main(int argc, char *argv[])
{
	int length = 30;
	int *data = Generate_random_numbers( 20, 100, length );
	
	for( int i = 0; i < length; ++i )
		cout << data[ i ] << ends;
	cout << endl;
	
	radixSort( data, length );
	
	for( int i = 0; i < length; ++i )
		cout << data[ i ] << ends;
	delete []data;
	
	return 0;
}