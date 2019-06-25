/*----------------------------------------------------------------

* @Author: Su

* @Description: ÄÚÁªº¯Êı²âÊÔ 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <string>

#define sq(x) x*x 

using namespace std;

inline double square(double x)
{
	return x*x;
}

int main(int argc, char *argv[])
{
	int a = 3;
	int b = 3; 
	cout<<square(++a)<<endl;
	cout<<sq(b++)<<endl;
	cout<<b;
	return 0;
}




