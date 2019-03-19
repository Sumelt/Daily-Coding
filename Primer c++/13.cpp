/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <array>
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
		auto newp= new std::string( *hp.ps ); //keep saft
		delete ps;
		ps = newp;
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

class strExample{
private :
public :
	static int number;
	strExample( int value ){
		number = value;
		cout << "call struct function\n";
	}
	strExample(){
		cout << "call default struct function\n";
	}
	strExample( const strExample& Example ) {
		number = Example.number;
		cout << "call Copy struct function\n";
	}
//	strExample( const strExample& Example ) = delete;
//	strExample& operator=( const strExample& ) = delete;
//	strExample& operator=( const strExample&& ) noexcept = delete;
//	strExample( strExample&& ) noexcept = delete;
	
	~strExample(){
		cout << "call destruct function\n";
	}
};
int strExample::number = 3 ;

int main()
{
//	HasPtr HasPtrA("A");
//	HasPtr HasPtrB("B");
//	HasPtrA = HasPtrB;
//	int N = 3;
//	int *ptr = &N;
//	array<int, 1>ary = { 1 };
//	
//	int &&rightReference = N * 3; //运算表达式返回的是值 
//	int &&rightReference2 = N++; //后置递增递减返回的是值 

	//int &leftReference = N; //左值引用  
//	int &leftReference2 = *ptr; //解引用返回的是对象 
//	int &leftReference3 = ary.at( 0 ); //数组下标返回的是个对象
//	int &leftReference4 = --N; //前置递增递减返回的是个对象 
//	const int &leftReference5 = N * 3; //const的左值引用可以绑定一个值 
	//strExample ex1( 1 );
//	strExample ex2 ( 1 );
//	strExample ex1 = strExample( 1 );
	//cout << ex1.number << endl;
	//strExample ex2(strExample( 1 ));
	
	
	
	
//	cout << strExample::number;
	//double p = 3.14;
 	//int &t = p;


	int *p = new int(100);
	cout << sizeof( *p ) << ' ' << *p;
    return 0;
}





