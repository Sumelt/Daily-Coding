/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <cstring>
using namespace std;

void replaceSpace(char *str,int length) {
	char *prPtr = str; char *lastPtr = nullptr; //开始指针 和扩展后的指针下标 
	int spaceCount = 0; char *stopaddres = nullptr; //空格个数 停止地址 
	if( str == nullptr || length <= 0) return;	//边界条件 
	for( ; *prPtr != '\0'; ++prPtr )
		if( *prPtr == ' ' ){
			++spaceCount;
			if( spaceCount == 1 )
				stopaddres = prPtr; //在第一个空格的前一个地址停下 
		} 	
	if( prPtr - str + 2 * spaceCount > length || spaceCount <= 0 ) return;	//有无超越给定空间 
	lastPtr = prPtr + ( 2 * spaceCount ); 
	while( prPtr != stopaddres - 1 )
	{
		if( *prPtr != ' ' ) *lastPtr-- = *prPtr--;		
		else{
			*lastPtr-- = '0';
			*lastPtr-- = '2';
			*lastPtr-- = '%';
			--prPtr;
		}
	}
}

int main(int argc, char *argv[])
{
	char *str = "HELLO WORLD\0";
	replaceSpace( str, 20 );
	//cout << str;
	return 0;
}