/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
using namespace std;

//动态规划 自底向上
class Solution {
public:
int rectCover( int n ) {
	vector<int>memo( n + 1, -1 ); //保存计算所得的结果
	memo[ 0 ] = 0;
	memo[ 1 ] = 1;
	memo[ 2 ] = 2;
	if( n < 3 )
		return memo[ n ];
	for( int i = 3; i <= n; ++i )
		memo[ i ] = memo[ i - 1 ] + memo[ i - 2 ];
	
	return memo[ n ];
	}
};



int main(int argc, char *argv[])
{
	
	return 0;
}