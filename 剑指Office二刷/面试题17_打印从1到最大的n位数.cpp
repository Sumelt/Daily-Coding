/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <cassert>
#include <cstring>
using namespace std;

void Print( char* array, int length ) {
	if( array == nullptr || length == 0 )
		return;
	bool flag = true;
	for( int i = 0; i < length; ++i ) {
		if( flag && array[ i ] != '0' )//找到第一位不为0的数值后开始打印 
			flag = false;
		if( !flag )
			cout << array[ i ];
	}
	cout << endl;
}
//------------方法1 
void outPutCode( char* array, int length, int index ) {
	if( index == length - 1 ) {
		Print( array, length );//已经递归到最后一位了，则输出当前的数组 
		return;
	}
	
	for( int i = 0; i < 10; ++i ) {
		array[ index + 1 ] = i + '0';
		outPutCode( array, length, index + 1 );//继续递归下一位 
	}	
}
//向外提供的公开接口 
void outPutMaxNumber( int n ) {
	if( n == 0 )
		return;
	
	char *array = new char[ n + 1 ]();
	array[ n ] = '\0';
	
	//控制首位 
	for( int i = 0; i < 10; ++i ) {
		array[ 0 ] = i + '0';
		outPutCode( array, n, 0 );//从首位开始向下一位递归 
	}
		
	delete []array;
}

//----------------方法2

bool outPutCode( char* array ) {
	bool over = false;
	int carry = 0;
	int length = strlen( array );
	for( int i = length	- 1; i >= 0; --i ) {
		int number = array[ i ] - '0' + carry;
		if( i == length - 1 )
			++number;
		//结果为10 
		if( number >= 10 ) {
			//判断当前是否为首位，是则表示溢出 
			if( i== 0 )
				over = true;
			//否则还在正常进位当中 
			else {
				number -= 10;
				carry = 1;
				array[ i ] = number + '0';
			}	
		}
		//此++操作没有发生进位 
		else {
			array[ i ] = number + '0';
			break;//进行打印操作 
		}
	}
	return over;
}

void outPutMaxNumber_2( int n ) {
	if( n == 0 )
		return;
	
	char *array = new char[ n + 1 ]();
	memset( array, '0', n );
	array[ n ] = '\0';
	
	while( !outPutCode( array ) )
		Print( array, n );
	
	delete []array;
}

int main(int argc, char *argv[])
{
	outPutMaxNumber_2( 2 );
	return 0;
}