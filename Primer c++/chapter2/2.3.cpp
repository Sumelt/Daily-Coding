/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
using namespace std;

//int a; 
int main(int argc, char *argv[])
{
	
//	unsigned u = 10, u2 = 42;
//	cout<< u2 - u <<endl; // 42 - 10 = 32
//	cout<< u - u2 <<endl; //-32 % 2^32 = 4294967264
//	
//	int i = 10, i2 = 42;
//	cout<< i2 - i <<endl; // 42 - 10 = 32
//	cout<< i - i2 <<endl; //10 - 42 = -32
//	cout<< i2 - u <<endl; // (unsigned)42 - 10 = 32
//	cout<< u - i <<endl; //10 - 10 = 0
	
//	int b = 3;
//	//
//	int &y = b;
//	int *p = nullptr; 
//	cout <<*p<<' '<<y;
	//cout<< a << b; 
//	const static int a = 3;
//	constexpr int b = a;
//	constexpr int c = 4;
//	const int *p = &a;//ture
//	const int *p = &b; //ture
//	int *pt = &a; //true
//	int *pt = &b; //error
//	int *const pr = &a; //ture
//	int *const pr = &b; //error
//	const int *const pk = &a; //true
//	const int *const pk = &b; //true
//	constexpr const int *ptr = &a;
	//const auto &a = 42;
	double pt = 23.0;
	const int i = 0, *ptr = &i;
	const int ci = 0, &cj = ci;
	decltype( ci ) x = 0;
	decltype( cj ) y = x;
	decltype(( ci )) e = x;
	decltype( *ptr ) c = x;
	using mydouble = double*;
	mydouble pk = &pt;
	//mydouble pk = 23.0;
	return 0;
}



