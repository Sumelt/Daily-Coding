/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <array>
#include <forward_list>
using namespace std;

int main(int argc, char *argv[])
{
	vector<int> vec = { 1, 2, 3, 4 };
	vector<int> vec2 = { 5, 6, 7, 8 };
	array<int, 3>i = { 5, 6, 7 };
	array<int, 3>j = { 9, 16, 17 };
//	auto p = vec.emplace( vec.begin(), 3 );
//	auto p = i.front();
//	p = 99;
//	cout << i.front();
//	auto p = vec.insert(vec.begin(), vec.begin(), vec.end());
//	for ( auto inx : vec )
//		cout << inx;
//	vec2.assign( vec.begin(), vec.end());

//	forward_list<int>flist = {1,2,3,4,5,6,7,8,9};
//	
//	auto fp = flist.before_begin();
//	auto cur = flist.begin();
//	while( cur != flist.end() )
//	{
//		if( *cur % 2 )
//			cur = flist.erase_after( fp );
//		else{
//			fp = cur;
//			++cur;
//		} 
//	}
//	for( auto inx : flist )
//		cout << inx;
		
//	vector<int>flist = {1,2,3,4,5,6,7,8,9};
//	auto cur = flist.begin();
//	while( cur != flist.end() )
//	{
//		if( *cur % 2 ){
//			cur = flist.insert( cur, *cur );
//			cur += 2;
//		}
//		else{
//			cur = flist.erase( cur );
//		} 
//	}
//	for( auto inx : flist )
//		cout << inx;
//	vec.reserve( 9 );
//	vec.shrink_to_fit();
//	cout << vec.size() << ' ' << vec.capacity() << endl;
//	string river( "Mississippi" );
//	cout << river.find_last_of( "is" ) << endl;  //10
//	cout << river.find_last_not_of( "is" ) << endl; //9
//	string s2 = "pi = 3.14";
	//auto d = stod( s2.substr( s2.find_first_of( "+-.0123456789" ) ) );
//	cout << s2.find_first_of( "+-.0123456789" );//d;

	string::value_type str;
	return 0;
}




