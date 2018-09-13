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

const int maxn = 100;
char s[maxn][10], temp[10];
int hashtable[26*26*26+10];

int hashfunc(char s[], int len)
{
	int id = 0;
	for(int i =0; i<len; i++)
		id = id * 26 + (s[i] - 'A');
	return id;
}

int main(int argc, char *argv[])
{
	int n, m;
	scanf("%d%d",&n, &m);
	for(int i =0; i<n; i++)
	{
		scanf("%s",s[i]);
		int id = hashfunc(s[i], 3);
		hashtable[id]++;
	}
	
	for(int i =0; i<m; i++)
	{
		scanf("%s", temp);
		int id = hashfunc(temp, 3);
		cout<<hashtable[id]<<endl;
	}
	return 0;
}




