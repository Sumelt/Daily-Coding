/*----------------------------------------------------------------

* @Author: Su

* @Description: �Լ����Ҵ��뻹��һ�����޷� AC��ɢ�й����ĸ����� 

* @Creath Date: 31/08/18 23:46

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

   	getline(cin, str1); //Ϊ�˷�ֹ��һ���ǿյģ�������cin >> ,��getline(cin, ...)��Դ������ 
    cin>>str2;
    bool HashTable[100000] = {false};
    for( i = 0; i<str1.length(); i++ )
    {
        for(j = 0; j<str2.length(); j++)
        {
            if(str1[i]>='A'&&str1[i]<='Z')
            {
            	if(str2[j]==str1[i])
	                HashTable[j] = true;
	            else if(str2[j]-32==str1[i])
	                HashTable[j] = true;
			}
			else
			 if(str2[j]==str1[i])
	                HashTable[j] = true;
				
        }
    }
    if(str1.find('+')==string::npos)
    {
        for(j = 0; j<str2.length(); j++)
            if(HashTable[j]==false)
                	cout<<str2[j];

    }
    else
    {
        for(j = 0; j<str2.length(); j++)
            if(HashTable[j]!=true)
                if(str2[j]>='A'&&str2[j]<='Z');
                else 
					cout<<str2[j];
    } 
	cout<<'\n';
    return 0;
}




