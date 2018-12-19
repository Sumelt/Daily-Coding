#ifndef DELEGATION_H
#define DELEGATION_H

class StringRep;
class String {
	
	public:
		String();
//		String(const char* cstr = 0);
//		String(const String& str);
//		String& operator = (const String& str);
		~String();
		void print();
	private:
		StringRep* rep;  // pimplÄ£Ê½ £¨pointer to implementation£© 
};


#endif
/*
	Name: 
	Copyright: 
	Author: 
	Date: 19/12/18 10:22
	Description: 
*/





