/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
using namespace std;

//记忆化搜索 
class Solution {	
private:
	vector<int>memo;
public:
    
    int calWay( int n ) {
    	if( n == 0 || n == 1 )
    		memo[ n ] =  1;
   		else if( memo[ n ] == -1 )
   			memo[ n ] = calWay( n - 1 ) + calWay( n - 2 );
   			
	   	return memo[ n ];
    }   
	int climbStairs(int n) {
		memo = vector<int>( n + 1, -1 );
        return calWay( n );
    }
};

//动态规划 
class Solution {
private:
	vector<int>memo;
public:
    int climbStairs(int n) {
        memo = vector<int>( n + 1, -1 );
        memo[ 0 ] = 1;
        memo[ 1 ] = 1;
        
        for( int i = 0; i <= n; i++ )
        	memo[ i ] = memo[ i - 1 ] + memo[ i - 2 ];
       	return memo[ n ];
    }
};

int main(int argc, char *argv[])
{
	Solution oj;
	cout << oj.climbStairs(2);
	return 0;
}