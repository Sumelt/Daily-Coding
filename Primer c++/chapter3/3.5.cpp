/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <iterator> 
#include <vector> 
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
//	const int array[] = {1, 2, 3, 4};
//	auto beg = begin( array );
//	auto last = end( array );
//	while( beg!=last ){
//		cout <<*beg <<endl;
//		beg++;
//	}
//	vector<vector<int>> array(5);
//	cout<<array.size();
//	for( auto inx : array )
//		cout <<inx<<' ';
//	const vector<int>array{1, 2, 3, 5, 8, 9, 13};
//	const int adm = 3;
//	auto beg = array.begin();
//	auto end = array.end();
//	auto mid = array.begin() + ( end - beg )/2;
//	while( mid != end && *mid != adm )
//	{
//		if( *mid > adm)
//			end = mid;
//		else
//			beg = mid + 1;
//		mid = beg + ( end - beg )/2;
//	}
//	if( *mid == adm )
//		cout <<*mid;
//	int a = 3;
//	int *p = &a;
//	int ia[] = {1, 2, 3};
//	decltype(ia) array = {5, 6, 7};
//	*array = *p;
//	char c_str[] = "Hello wolrd";
//	string str;
//	str = c_str;
//	string str2 = str + c_str;

	const int array[][3] = { {1,3,5}, {6, 7, 8} };
	for( auto &inxi : array )
		for( auto inxj : inxi)
			cout << inxj<<' ';

	for( auto &inxi : array )
		for( auto inxj = begin( inxi ); inxj != end( inxi ); inxj++ )
			cout <<*inxj <<' ' ;
			
	using int_array = int[4];
	typedef int int_array[4]; //int_array->int_array[4][4] 
	
	return 0;
}




