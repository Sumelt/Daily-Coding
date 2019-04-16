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
   		 //自上而下
   		for( int i = 1; i < A.size(); ++i ) 
   			vec[ i ] = vec[ i - 1 ] * A[ i - 1 ];
		//自下而上
		int saveRes = A[ A.size() - 1 ];
		for( int i = A.size() - 2; i >= 0; --i ) {
			vec[ i ] *= saveRes;
			saveRes *= A[ i ];
		}			
		return vec;
    }
};



int main(int argc, char *argv[])
{
	Solution oj;
	oj.multiply( { 1,2,3,4,5 } );
	return 0;
}