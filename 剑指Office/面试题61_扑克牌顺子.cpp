/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
private:
   	int countZero = 0;
   	int lostNumberCount = 0;	
public:
    bool IsContinuous( vector<int> numbers ) {
        if( numbers.size() == 0 )
        	return false;
       	sort( numbers.begin(), numbers.end() );//第一步排序
       	
		for( int i = 0; i < numbers.size(); ++i )//第二步找出0号牌的个数
			if( numbers[ i ] == 0 )
				++countZero;
		
		for( int i = 1; i < numbers.size(); ++i ) {
			if( numbers[ i ] != 0 && numbers[ i - 1 ] != 0 ) {
				int res = numbers[ i ] - numbers[ i - 1 ] - 1;//相邻的牌结果为0
				if( res == -1 )//遇到相同的牌
					return false;
				else if( res != 0 )//缺少的牌数
					lostNumberCount += res;
			}							
		}      	
       	return ( lostNumberCount <= countZero ) ? true : false;      	
    }
};
int main(int argc, char *argv[])
{
	
	return 0;
}