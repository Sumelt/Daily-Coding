/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

/*
class Base {
private:
public:
	Base() = default;
	virtual void out() = 0;
	 //~Base() = default; 
	 //virtual ~Base() = default; 
	virtual	~Base()  {
	 	cout << "base printf" << endl;
 	} 
};

class derive : public Base {
public:
	//virtual ~derive();
	~derive() = default; 
	virtual void out()  {
		cout << "hello world!!" << endl;
	}
};

int main(int argc, char *argv[])
{
	Base *bptr = new derive();
	//bptr->~Base();
	bptr->out();
	
	return 0;
}
*/

int main() {
	int ary[ 5 ] = { 1, 2, 3, 4, 5 };
	cout << ( ary + 2 )[ 1 ] << endl;
} 