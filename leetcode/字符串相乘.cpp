/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <forward_list>
using namespace std;

string multiply(string num1, string num2) {
	int num1Length = num1.size(), num2Length = num2.size();
	vector<int>array( num1Length + num2Length, 0 ); //存放结果的容器 
	forward_list<int>ls; // 进位操作的链表 
	string str; //返回的字符串 
	int j = 0, resIndex = 0;
	for( int i = 0; i < num1Length; ++i ) //模拟手工除法 
		for( j = 0, resIndex = i; j < num2Length; ++j, ++resIndex )
			array[ resIndex ] += ( num1[ i ] - '0' ) * ( num2[ j ] - '0' );
	 
 	//满十进位 
 	for( int i = resIndex - 1; i > 0; --i ) {
 		array[ i - 1 ] += array[ i ] / 10; //进位 
 		ls.insert_after( ls.before_begin(), array[ i ] % 10  ); //取余得到个位，使用链表插入较快 
 	}
 	ls.insert_after( ls.before_begin(), array[ 0 ] ); //第 0 位的结果 
 	
	while( !ls.empty() && ls.front() == 0 ) ls.pop_front();  //结果存在多个 0的处理 
 	if( ls.empty() ) return "0"; //全为 0 则直接返回 0 
 	else {
	 	for( auto start = ls.begin(); start != ls.end(); ++start )  //转换成字符串 
	 		str += to_string( *start );	 		
	 }
 	return str;
}

int main(int argc, char *argv[])
{
	cout << multiply( "123", "456" );
	return 0;
}

/*
123 * 456
	4 5 6  -->//第一次循环 
	  8 10 12 -->//第二次循环 
 ---------------------
    4 13 16 12
------------------------- 
         12 15 18  -->//第三次循环 
--------------------------------
	4 13 28 27 18 */
	
//18 进位 1 于 8
//27+1 进位 2 于 8
//28+2 进位 3 于 0
//13+3 进位 1 余 6 
// 4+1 = 5
// 5 6 0 8 8 