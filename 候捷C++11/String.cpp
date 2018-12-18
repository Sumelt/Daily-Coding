/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <string.h>
#include "String.h"

class ostream;

int main(int argc, char *argv[])
{
	String *p = new String("Hello");
	delete p;
	return 0;
}

inline String::String(const char* cstr)
{
	if(cstr){
		m_data = new char[strlen(cstr)+1];
		strcpy(m_data, cstr);
	}
	else{
		m_data = new char[1];
		*m_data = '\0';
	}

}

inline String::String(const String& str)
{
	m_data = new char[strlen(str.m_data)+1];
	strcpy(m_data, str.m_data);
	
}

inline String& String::operator =(const String& str)
{
	if(this == &str)
		return *this;
		
	delete[] m_data;
	m_data = new char[strlen(str.m_data)+1];
	strcpy(m_data, str.m_data);
	return *this;
}

inline String::~String()
{
	delete[] m_data;
}

inline ostream& operator << (ostream& os, const String& str)
{
	os<< str.get_c_str();
	return os;
}

String *p = new String[3];
delete[] p;

