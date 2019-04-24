/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
using namespace std;

class Solution {
private:
	int arr[ 1000 ] = { 0 };
	int cal( int number ) {
		int res = 0;
		if( number == 1 )
			return arr[ number ];
		if( arr[ number ] != 0 )//该台阶已经计算过则直接累加
			res += arr[ number ];
		res += cal( number - 1 );//再次递归
		
		return res;
	}
public:
    int jumpFloorII(int number) {
        if( number == 0 )
        	return 0;
       	arr[ 1 ] = 1;
       	arr[ 2 ] = 2;
       	
		if( number > 2 ) {			
			for( int i = 3; i <= number; ++i )
				arr[ i ] = 1 + cal( number - 1 );//计算n-1阶的跳法
			return arr[ number ];
		}			
		else return arr[ number ];
    }
};

//解法二
//直接 pow(2, number-1 );即可得到结果 
int main(int argc, char *argv[])
{
	Solution oj;
	cout << oj.jumpFloorII( 4 );	
	return 0;
}