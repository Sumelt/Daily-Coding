/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date: 08/09/18 21:41

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
	int n, j;
	char c;
	scanf("%d %c", &n,&c);
	if(n%2!=0)
		j = n/2+1;
	else j = n/2;
	for(int i = 0; i<n; i++)
		printf("%c",c);
	cout<<endl;
	for(int i = 0; i<j-2; i++)
		{
			printf("%c",c);
			for(int i =0; i<n-2; i++)
				cout<<' ';
			printf("%c",c);
			cout<<endl;
		}
	for(int i = 0; i<n; i++)
		printf("%c",c);
	return 0;
}




