/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date: 30/08/18 20:24

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
	bool HashTable[128] = {false};
	string str1, str2;
	int i, j;
	cin>>str1;
	cin>>str2;
	transform(str1.begin(),str1.end(),str1.begin(),::toupper);
	transform(str2.begin(),str2.end(),str2.begin(),::toupper);
	for( i = 0; i<str1.length(); i++)
		{
			for( j = 0; j<str2.length(); j++)
				{
					if(str1[i]==str2[j])
						break;
				}
			if(j<str2.length())
				{
					HashTable[str1[i]] = true;
				}
			else
				{
					if(HashTable[str1[i]] == false )
						{
							cout<<str1[i];
							HashTable[str1[i]] = true;
						}
				}


		}

	return 0;
}



