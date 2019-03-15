/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
using namespace std;

//对于 char类型的字符串，字符串中都带有'\0'作为结束标志
bool matchCore(char* str, char* pattern)
{
	if( *str == '\0' && *pattern == '\0' ) //全部匹配完成
		return true;
 	
 	if( *str != '\0' && *pattern == '\0' )//匹配失败
 		return false;
 	
    //******模式第二个字符是'*'，有着多种情况处理**********//
 	if( *( pattern + 1 ) == '*' ) {
		//它们相等或者是模式字符为'.'可以进入下轮匹配
        if( *pattern == *str || ( *pattern == '.' && *str != '\0') )
			return matchCore( str + 1, pattern + 2 )  //它们相等，彼此下移
            	|| matchCore( str, pattern + 2 ) //它们不相等，但是*可以表示它前面字符出现0次
				|| matchCore( str + 1, pattern );//它们相等，但是*还可以表示它前面字符出现多次
		
        else return matchCore( str, pattern + 2 );
        //它们不相等，并且模式字符也不是'.'但是模式字符的后一位是'*'，表示可以它前面的字符可以出现0次则可以进行下一轮匹配
	}
	
    //********模式目标串的后一个不是*，这样容易很多**********//
    else {
		if( *str != '\0' && (*str == *pattern || *pattern == '.') ) //它们相等，或者是模式字符为'.'都可以进行下一轮匹配，因为'.'匹配任意字符
			return matchCore( str + 1, pattern + 1 );
		else return false;//它们不相等并且模式字符不是'.'，直接匹配失败
	}
}

bool match(char* str, char* pattern)
{
	if( str == nullptr || pattern == nullptr )
		return false;
	return matchCore( str, pattern );
}

int main(int argc, char *argv[])
{

	return 0;
}