/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <string.h>

using namespace std;

int main(int argc, char *argv[])
{
	string a;
	//getline(cin,a); //忽略回车，回车不存 
	//cin.get();  //只读一个字符，输入多个字符，其余字符存在缓冲区，包括回车 
	//getline(cin,a) ;
	//while();
	//if(a[0]=='\n')printf("yes");
	//cin>>a;
	if(getline(cin, a, '#'))
		cout<<"return true";
	cout<<a;
	return 0;
}




