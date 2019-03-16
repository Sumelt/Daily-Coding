/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <array>
using namespace std;

bool mycmp( const int &numb1, const int &numb2 )
{
	return numb1 < numb2;
}

int main(int argc, char *argv[])
{
	array<int, 10>ary = { 1, 2, 3, 5, 5, 4, 7, 4, 8, 2 };
	static int value = 3;
	int size = 2;
	auto start = ary.begin();
	auto last = ary.end();	
	//string str1("hello"); string str2( "world " );
	//cout << accumulate( ary.cbegin(), ary.cend(), 0 );
	//cout << accumulate( str2.cbegin(), str2.cend(), str1 );
	//fill( ary.begin(), ary.end(), 0 );
	
	//stable_sort( ary.begin(), ary.end() );
	auto lambda1 = [ & ]( const int &number )->bool {
		return number > size;
	};
	auto lambda2 = [ ]( const int &number ) { //自动推倒返回类型 
		cout << number <<' ';
	};
	auto lambda3 = [ ]( const int &number ) {
		if( value > number ) return -1;
		else return 0;
	};
	auto lambda4 = [  ]( int value ){ cout << "lambda\n"; }; //捕获列表必须存在 
	
//	sort( start, last, mycmp );
	auto fg = find_if( start, last, lambda1 );
//	for_each( fg, last, lambda2 );
//	transform( start, last, start, lambda3 );
	lambda4(3); 
/*************************************/	
//	start = ary.begin();
//	last = ary.end();
//	
//	while( start != last )
//		cout << *start++ << ' ';
	
	return 0;
}