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
	int n;
	char str[100] = "123";
//	sscanf(str, "%d", &n); //直接由字符串转为10进制的数字 
//	cout<<n;
	n = 520;
	sprintf(str, "%d", n);
	cout<<str[0]; 
	return 0;
}




