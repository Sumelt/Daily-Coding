/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {	
public:
    vector<int> multiply(const vector<int>& A) {
    	if( A.size() == 0 )
    		return vector<int>();
   		
   		vector<int>vec( A.size(), 1 );
   		
   		for( int i = 1; i < A.size(); ++i ) {
		   		vec[ i ] = vec[ i - 1 ] * A[ i - 1 ];
		   		cout << vec[ i ] << ends;
		   }
   			
		cout << endl;
		for( int i = A.size() - 2; i >= 0; --i ) {
			vec[ i ] *= vec[ i + 1 ] * A[ i + 1 ];
			cout << vec[ i ] << ends;
		}
			
			
		return vec;
    }
};

void arrayProduct( const vector<int>vec1, vector<int>vec2 )
{
	int size1 = vec1.size();
	int size2 = vec2.size();
	
	if( size2 > 1 && size1 == size2 ) { //给定的空间相等并且空间大小至少为2		
        //自上而下
        vec2[ 0 ] = 1;
		for( int i = 1; i < size2; ++i )
			vec2[ i ] = vec2[ i - 1 ] * vec1[ i - 1 ];
		
        //自下而上
		vec2[ size2 - 1 ] = 1;
		for( int i = size2 - 2; i >= 0; --i )
			vec2[ i ] *= vec2[ i + 1 ] * vec1[ i + 1 ];
	}	
}

int main(int argc, char *argv[])
{
	Solution oj;
	oj.multiply( { 1,2,3,4,5 } );
	return 0;
}