/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date: 29/08/18 22:07

----------------------------------------------------------------*/

#include <iostream>
#include <string>
#include <algorithm>
#include <string.h>
#include <unordered_set>
#include <unordered_map>

using namespace std;

std::unordered_set<char> transform(string str)
{
	std::unordered_set<char> str2;
	transform(str.begin(),str.end(),str.begin(),::tolower);
	for(int i = 0; i<str.length(); i++)
		{
			str2.insert(str[i]);
		}
	std::unordered_set<char>::iterator it;
	for(it = str2.begin(); it!=str2.end(); it++)
		cout<<*it;
	cout<<endl;

	str2.erase('_');



	return str2;
}

int main(int argc, char *argv[])
{
	string str,instr;
	std::unordered_set<char> str2,instr2;
	unordered_map<char,bool> str3;
	cin>>str;
	cin>>instr;
	//reverse(str.begin(),str.end());
	//reverse(instr.begin(),instr.end());
	str2 = transform(str);
	instr2 = transform(instr);
	for(std::unordered_set<char>::iterator it = str2.begin(); it!=str2.end(); it++)
		str3[*it] = false;
	for(std::unordered_set<char>::iterator it = instr2.begin(); it!=instr2.end(); it++)
		{
			if(str3.find(*it)!=str3.end())
				str3[*it] = true;
		}

	for(unordered_map<char,bool>::iterator it = str3.begin(); it!=str3.end(); it++)
		{
			if(it->second==0)
				{
					if(it->first>='a'&&it->first<='z')
						printf("%c",toupper(it->first));
					else cout<<it->first;
				}

		}
	return 0;
}



/*
	Name:
	Copyright:
	Author:
	Date: 28/08/18 22:04
	Description:
*/

