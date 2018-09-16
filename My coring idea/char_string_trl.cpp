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
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	string p = "hello";
	//const char *pr = p.c_str();
	//const char *pr = p.data();
	char pr[50];
	p.copy(pr,5,0);
	//cout<<*pr;
	//while(*pr!='\0')
		//cout<<*(pr++);
		int i = 0;
	while(*(pr+i)!='\0')
	{
		cout<<*(pr+i);
		i++;
		}	
	return 0;
}




