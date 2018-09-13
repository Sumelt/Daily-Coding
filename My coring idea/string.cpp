/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <string>
using namespace std;
int main(int argc, char *argv[])
{
	string str,str2;
	str = "my name is su";
	str2 = "hello,i love you";
	string str3;
	cout<<str <<endl;
	printf("%s\n",str.c_str());
	string::iterator it = str.begin();
	for(it;it!=str.end();it++)
		cout<<*it;
	cout<<endl;
	str+=',';
	str+=str2;
	cout<<str <<endl;
	cout<<(str!=str2? "yes":"no");
	cout<<endl<<str.length()<<endl;
	cout<<str.size()<<endl;
	str3.insert(str3.begin(),str2.begin(),str2.end());
	str2.insert(0,"economy,");
	cout<<str2<<endl<<str3;
	str3.erase(0,1);
	str3.erase(str3.begin()+1);
	str3.erase(str3.begin()+4,str3.end()-1);
	cout<<endl<<str3;
	cout<<endl<<str.substr(0,6);
	cout<<endl<<str.find("name");
	cout<<endl<<str.find("su",9);
	cout<<endl<<str.replace(0,3,"*");
	cout<<endl<<str.replace(str.end()-3,str.end(),"&");
	return 0;
}

