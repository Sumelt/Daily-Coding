/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxValue = 0; int lastIndex = height.size() - 1;              
          for( int i = 0; i < lastIndex; ) 
          {
              int res = ( lastIndex - i ) * min( height[ lastIndex ], height[ i ] ); //选择最短的线段
              if( res > maxValue ) maxValue = res;
              height[ lastIndex ] >= height[ i ]? ++i : --lastIndex;
          }
        return maxValue;
    }
};

int main(int argc, char *argv[])
{
	
	return 0;
}