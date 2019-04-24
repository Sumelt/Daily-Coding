/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
using namespace std;

class Solution {
private:
	long long result = 0;
	bool sig = true; //true + false -
	void conversion( const char *ptr ) {		
		int signal = ( sig ? 1 : -1 );
		if( !isdigit( *ptr ) )//判断第一位是不是数字，是则跳过进入到下一位
			++ptr;
		while( *ptr != '\0' ) {//字符串扫描还未结束
			if( *ptr >= '0' && *ptr <= '9' ) {
				result = result * 10 + ( *ptr - '0' ) * signal;//累加结果
                //溢出判断
				if( result > (signed)0x7fffffff || 
						result < (signed)0x80000000 ) {
					result = 0;//溢出
					break;
				}
				++ptr;//下一位				
			}
			else {
				result = 0;//非法输入
				break;
			}			
		}		
	}
public:
    int StrToInt(string str) {
       if( str.size() == 0 )//非空判断
       		return result;     		
		if( str[ 0 ] == '+' || str[ 0 ] == '-' || isdigit( str[ 0 ] ) ) {
			sig = ( str[ 0 ] == '-' ? false : true );
			conversion( str.c_str() );
		}							
		return result;
    }
};

int main(int argc, char *argv[])
{
	Solution oj;
	cout << oj.StrToInt( string( "123" ) );
	return 0;
}