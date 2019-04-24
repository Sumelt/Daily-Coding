/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
using namespace std;

//动态规划 自顶向下 
class Solution {
public:
    int jumpFloor(int number) {
        if( number == 0 )
        	return 0;
       	int arr[ 1000 ] = { 0 };
       	int i = 3;
       	arr[ 1 ] = 1;
       	arr[ 2 ] = 2;
       	if( number > 2 ) {
			for( i; i <= number; ++i )
				arr[ i ] = arr[ i - 1 ] + arr[ i - 2 ];	
			return arr[ i - 1 ];      	
   		}
       	else return arr[ number ];	     	
    }
};

int main(int argc, char *argv[])
{
	Solution oj;
	cout << oj.jumpFloor( 2 );
	return 0;
}