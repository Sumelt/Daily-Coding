/*----------------------------------------------------------------

* @Author: Su

* @Description: ��������˼· 

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
	int n,i, j;
	string str;
	string temp;
	
	cin>>str>>n;
	for(int cnt = 1; cnt<n; cnt++)
	{
		for(i =0; i<str.length(); i=j){
			for(j=i; j<str.length()&&str[i]==str[j]; j++); //���ѭ�������� 
			temp+=to_string((str[i]-'0')*10+j-i);  //��ֵҲ������ 
		}
		str = temp;
		temp.clear();
	}
	cout<<str;
	return 0;
}




