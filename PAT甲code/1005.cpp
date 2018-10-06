/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date: 06/10/18 16:54

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>


using namespace std;

char number[10][6] = {"zero", "one", "two", "three", "four", "five", "six", \ 
"seven", "eight", "nine"};


int main(int argc, char *argv[])
{
	string str;
	int res = 0;
	cin>>str;
	for(int i =0; i<str.length(); i++) res += str[i]-'0';
	str = to_string(res);
	for(int i =0; i<str.length(); i++)
	{
		printf("%s", number[str[i]-'0']);
		if(i<str.length()-1) cout<<' ';
	}
	return 0;
}




