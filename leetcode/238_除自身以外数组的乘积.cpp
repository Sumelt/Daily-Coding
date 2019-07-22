/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <vector> 
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
   if( nums.size() <= 0 ) return vector<int>();
   
	vector<int>vec( nums.size(), 1 );
   	for( int i = 1; i < nums.size(); ++i )
		vec[ i ] = nums[ i - 1 ] * vec[ i - 1 ];
		
	for( int i = nums.size() - 2, temp = 1; i >= 0; --i ) {		
		temp *= nums[ i + 1 ];
		vec[ i ] *= temp;
	}
	
	return vec;    
}

int main(int argc, char *argv[])
{
	
	return 0;
}