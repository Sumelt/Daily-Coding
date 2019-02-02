/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class HasPtr {
public:
    //HasPtr() = default;//= delete;
	HasPtr(const std::string &s = string() ) : ps(new std::string(s)), i(0) { }
    HasPtr(const HasPtr& hp) : ps(new std::string(*hp.ps)), i(hp.i) { }
    HasPtr& operator=( const HasPtr& hp )
    {
    	ps = new std::string( *hp.ps );
    	i = hp.i;
    	//cout << "test";
    	return *this;
	}
	~HasPtr() { delete ps; }
	void Print(){
		cout << i;
	}
	
private:
    std::string *ps = nullptr;
    int i = 0;
};

int main()
{
	
    return 0;
}

/*
---main
    X *px = new X; //X() { std::cout << "X()" << std::endl; };
    f(*px, *px);
    delete px; //~X() { std::cout << "~X()" << std::endl; }
----
struct X {
    X() { std::cout << "X()" << std::endl; }
    X(const X&) { std::cout << "X(const X&)" << std::endl; }
    X& operator=(const X&) { std::cout << "X& operator=(const X&)" << std::endl; return *this; }
    ~X() { std::cout << "~X()" << std::endl; }
};

void f(const X &rx, X x) //X(const X&) { std::cout << "X(const X&)" << std::endl; }\
		// ~X() { std::cout << "~X()" << std::endl; } 
{
    std::vector<X> vec;
    vec.reserve(2);
    vec.push_back(rx); //X(const X&) { std::cout << "X(const X&)" << std::endl; } // ~X() { std::cout << "~X()" << std::endl; }
    vec.push_back(x); //X(const X&) { std::cout << "X(const X&)" << std::endl; } // ~X() { std::cout << "~X()" << std::endl; }
}
*/
