/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

class HasPtr {
public:

	friend void swap( HasPtr&, HasPtr& );
	HasPtr(const std::string &s = string())
		 : ps(new std::string(s)), i(0) { }
    HasPtr(const HasPtr& hp)
		 : ps(new std::string(*hp.ps)), i(hp.i) { cout << "YES" << endl; }
    HasPtr& operator=( HasPtr hp )
    {
//    	ps = new std::string( *hp.ps );
//    	i = hp.i;
		swap( *this, hp );
    	return *this;
	
	}
	~HasPtr() { delete ps; cout << "END" << endl; }
	void Print(){ cout << i; }
	
private:
    std::string *ps = nullptr;
    int i = 0;
};

inline void swap( HasPtr &lhs, HasPtr &rhs )
{
	using std::swap;
	swap( lhs.ps, rhs.ps );
	swap( lhs.i, rhs.i );
}

class HasPtr_value {
public:

	HasPtr_value( const std::string &s = string() )
		 : ps(new std::string(s)), i(0) { }
    HasPtr_value( const HasPtr_value& hp )
		 : ps( new std::string(*hp.ps)), i(hp.i) { }
    HasPtr_value& operator=( const HasPtr_value& hp )
    {
    	if( this == &hp)
    		return *this;
		delete ps;
		ps = new std::string( *hp.ps );
    	i = hp.i;
    	return *this;
	}
	~HasPtr_value() { delete ps; }
	void Print(){ cout << i; }
	
private:
    std::string *ps = nullptr;
    int i = 0;
};

class HasPtr_ptr {
public:

	HasPtr_ptr( const std::string &s = string() )
		 : ps( new std::string( s )), i( 0 ), count( new std::size_t( 1 )) { }
    HasPtr_ptr( const HasPtr_ptr& hp )
		 : ps( hp.ps ), i( hp.i ){ ++( *count ); }
    HasPtr_ptr& operator=( const HasPtr_ptr& hp )
    {
    	if( this == &hp ) //check 
    		return *this;
		++( *hp.count ); // add hp count
    	if( --*count == 0 ) //ower 
    	{
    		delete ps;
    		delete count;
		}	
		ps = hp.ps; //point hp.ps address
    	i = hp.i;
    	return *this;
	}
	~HasPtr_ptr()
	{
		if( --*count == 0 )
		{
			delete ps;
			delete count;
		}
	}
	void Print(){ cout << i; }
	
private:
    std::string *ps = nullptr;
    std::size_t *count = nullptr;
    int i = 0;
};


int main()
{
//	HasPtr HasPtrA("A");
//	HasPtr HasPtrB("B");
//	HasPtrA = HasPtrB;
	int N = 3;
	int  &&t = N * 2;
    return 0;
}





