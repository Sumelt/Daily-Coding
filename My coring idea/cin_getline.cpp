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
	//getline(cin,a); //���Իس����س����� 
	//cin.get();  //ֻ��һ���ַ����������ַ��������ַ����ڻ������������س� 
	//getline(cin,a) ;
	//while();
	//if(a[0]=='\n')printf("yes");
	//cin>>a;
	if(getline(cin, a, '#'))
		cout<<"return true";
	cout<<a;
	return 0;
}




