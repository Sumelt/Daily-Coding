/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
using namespace std;

bool judgeNumber( char *&str )
{
	bool flag = false;
	while( *str != '\0' && *str >= '0' && *str <= '9' ) {
		++str;
		flag = true;
	}
	return flag;		
}

bool judgeSignal( char *&str )
{
	if( *str == '+' || *str =='-' )
		++str;
	return judgeNumber( str ); //判断符号后再判断数字部分
}
//.123
//233.
//233.666  123.45e+6
//正确模式[-+int].[+-int] [e|E[int]] == 【A】.【B】e|E【C】
//小数里可以没有整数部分，因此A部分不是必须的
//一个数没有整数部分，那么它的小数部分一定不能为空
bool isNumeric(char* string)
{
    if( string == nullptr )
    	return false;
   	bool res = judgeSignal( string );//先判断A部分 
   	
   	if( *string == '.' ) {
		++string;
		res = judgeNumber( string ) || res; //整数部分不是必须的，所以用或
	}
	if( *string =='e' || *string == 'E' ) {
		++string;
		res = res && judgeSignal( string );//小数部分是必须的B部分和C部分都必须为真
	}
   	return res && *string == '\0';
}

int main(int argc, char *argv[])
{
	
	return 0;
}