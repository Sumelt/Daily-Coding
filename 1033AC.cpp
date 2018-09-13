/*----------------------------------------------------------------

* @Author: Su

* @Description: 借鉴晴神的思路 

* @Creath Date: 01/09/18 10:53 

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
	string str1, str2;
    unsigned int i, j;
    getline(cin, str1);
    cin>>str2;
    
    bool HashTable[128] = {false};
    
    for(i = 0;i<str1.length(); i++)
		{
			if(str1[i]>='A'&&str1[i]<='Z')
			{
				HashTable[str1[i]] = true;
				HashTable[str1[i]+32] = true;
			}
			else HashTable[str1[i]] = true;	
		}
    
    for(j = 0; j<str2.length(); j++)
    {
    	if(str2[j]>='A'&&str2[j]<='Z')
    	{
    		if(HashTable[str2[j]]!=true&&HashTable['+']!=true)
    			cout<<str2[j];
		}
		else
		{
			if(HashTable[str2[j]]!=true)
				cout<<str2[j];
		}
	}
    cout<<endl;
	return 0;
}




