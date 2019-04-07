/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
using namespace std;

class Solution {
public:
    int Add(int num1, int num2)
   	{
		int andRes = num1 & num2 << 1; //考虑进位
		int XORes = num1 ^ num2;//不考虑进位
		while( andRes != 0 ) { //不再产生进位时跳出
			num1 = XORes;
			num2 = andRes;//拿到进位的情况
			XORes = num1 ^ num2;//累加进位
			andRes = ( num1 & num2 ) << 1;
		}
		return XORes;
    }
};

int main(int argc, char *argv[])
{
	
	return 0;
}