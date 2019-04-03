/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
	vector<int>vec1;
	vector<int>vec2;

public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
		if( data.size() == 0 )
			return;		
		int andRes = 0;
		for( int index = 0; index < data.size(); ++index )
			andRes ^= data[ index ]; //全部数异或操作后的结果
        
		int firstTrueIndex = 0;
		int andBit = 1;
		while( ( andRes & andBit ) != andBit ) //找到第一位为1的二进制位数的位置
			andBit <<= 1;
		firstTrueIndex = andBit;
		
		for( int i = 0; i < data.size(); ++i ) {
			if( ( firstTrueIndex & data[ i ] ) == firstTrueIndex )//利用该位置进行分割
				vec1.push_back( data[ i ] );
			else vec2.push_back( data[ i ] ); 
		}
		
		for( int i = 0; i < vec1.size(); ++i )
			*num1 ^= vec1[ i ];	
		for( int i = 0; i < vec2.size(); ++i )
			*num2 ^= vec2[ i ];		
    }
};


int main(int argc, char *argv[])
{
	int num1 = 0, num2 = 0;
	Solution oj;
	oj.FindNumsAppearOnce( { 1,1, 2, 4, 5, 5 }, &num1, &num2 );
	cout << num2 <<' ' << num1;
	return 0;
}