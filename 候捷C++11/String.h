#ifndef __STRING_H__
#define __STRING_H__

class String {
	
	public:
		String(const char* cstr = 0);
		String(const String& str);
		String& operator = (const String& str);
		~String();
	private:
		char* m_data;
		
};

#endif

String s1();
String s2("Hello");
String s3(s1);
s3 = s2;



