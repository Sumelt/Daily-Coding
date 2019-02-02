/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include "Delegation.h"

using namespace std;

//namespace{
	class StringRep{
		
		friend class String;
	public:
		//StringRep(const char* s);
		//~StringRep();
		void print();
		int count;
		char* rep;
			
	};	
//}

void StringRep::print()
{
	cout<<"TEST";
}

void String::print()
{
	rep->print();
}

String::String()
{
	rep = new StringRep;
}

String::~String()
{
	delete rep;
}

int main(int argc, char *argv[])
{
	String *T = new String();
	String pk(T);
	T->print();
	
	return 0;
}




