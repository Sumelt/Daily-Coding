/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <typeinfo>

using namespace std;

int main(int argc, char *argv[])
{

	return 0;
}



inline const char* num_sequence::what_am_i() const
{
	return typeid ( *this ).name();
}


if(typeid( *ps ) == typeid ( Fibonacci ))
	//yes;
	
Fibonacci fib; //Fibonacci是派生类 
num_sequence *ps = &fib;  //父类指针 
if(typeid( *ps ) == typeid( Fibonacci ))
{
	Fibonacci *pf = static_cast<Fibonacci*>( ps );
	pf->gen_elems( 64 );
}

if(Fibonacci *pf = dynamic_cast<Fibonacci*>( ps ))
	pf->gen_elems( 64 );



