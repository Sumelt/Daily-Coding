/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <functional>
#include <array>
using namespace std;
using namespace std::placeholders; // _n的命名空间 
 
bool mycmp( const int &numb1, const int &numb2 )
{
	return numb1 < numb2;
}

bool check_size( const int &number, const int size )
{
	return number > size;
}

void Print( const int value1, const int value2, const int value3 )
{
	cout << value1 << endl;
	cout << value2 << endl;
	cout << value3 << endl;
}

int main(int argc, char *argv[])
{
	array<int, 10>ary = { 1, 2, 3, 5, 5, 4, 7, 4, 8, 2 };
	static int value = 3;
	int size = 5;
	auto start = ary.begin();
	auto last = ary.end();	
//	string str1("hello"); string str2( "world " );
//	cout << accumulate( ary.cbegin(), ary.cend(), 0 );
//	cout << accumulate( str2.cbegin(), str2.cend(), str1 );
//	fill( ary.begin(), ary.end(), 0 );
//	

	auto lambda1 = [ & ]( const int &number )->bool {
		return number > size;
	};
	auto lambda2 = [ ]( const int &number ) { //自动推倒返回类型 
		cout << number <<' ';
	};
	
//	auto lambda3 = [ ]( const int &number ) {
//		if( value > number ) return -1;
//		else return 0;
//	};
//	auto lambda4 = [  ]( int value ){ cout << "lambda\n"; }; //捕获列表必须存在 
	
//	sort( start, last, mycmp );

	
//	stable_sort( ary.begin(), ary.end() );
//	auto bindFunction = bind( check_size, _1, cref( size ));	
//	auto fg = find_if( start, last, bindFunction ); //绑定 
//	for_each( fg, last, lambda2 );
	
//	bindFunction( 3 ); //函数调用 
	auto bindPrint = bind( Print, _2, _1, size );
	bindPrint( -1, 3 ); // -1 被绑定到 _1位置，3被绑定到_2位置  输出为 3 -1 5 

//	transform( start, last, start, lambda3 );
//	lambda4(3); 

	
	

/*************************************/	
//	start = ary.begin();
//	last = ary.end();
//	
//	while( start != last )
//		cout << *start++ << ' ';
	
	return 0;
}