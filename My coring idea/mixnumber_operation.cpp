/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <string.h>
#include <set>
#include <map>
#include <string>

using namespace std;

struct bign{
	int d[1000];
	int len;
	bign(){
		memset(d, 0, sizeof(d));
		len = 0;
	}
};

bign change(char str[])
{
	bign a;
	a.len = strlen(str);
	for(int i = 0; i<a.len; i++)
		a.d[i] = str[a.len - i -1] -'0';  //高位存高位，低位存低位 
	return a;
}

int compare(bign a, bign b)
{
	if(a.len > b.len ) return 1;
	else if(a.len < b.len) return -1;
	else
	{
		for(int i = a.len-1; i>=0; i++)
		{
			if(a.d[i]>b.d[i]) return 1;
			else return -1;
		}
		return 0; //==
	}
}

bign add(bign a, bign b)
{
	int carry = 0;
	int temp;
	int i;
	bign res = bign();	
	
	for(i = 0; i<a.len||i<b.len; i++)
	{
		temp = (a.d[i] + b.d[i] +carry);
		res.d[res.len++] = temp %10;
		carry = temp / 10;
	}
	if(carry!=0)
		res.d[res.len++] = carry;
	return res;
}

bign sub(bign a, bign b)
{
	bign res = bign();
	for(int i = 0; i<a.len||i<b.len; i++)
	{
		if(a.d[i]>=b.d[i])
			res.d[res.len++] = a.d[i]-b.d[i];
		else
		{
			a.d[i+1]--;
			res.d[res.len++] = a.d[i]+10-b.d[i];
		}
	}
	while(res.len-1>=1&&res.d[res.len-1]==0)
		res.len--;
	return res;
 } 

bign multi(bign a, int b)
{
	bign res = bign();
	int carry = 0;
	for(int i = 0; i<a.len; i++)
	{
		carry = a.d[i] * b + carry;
		res.d[res.len++] = carry%10;
		carry/=10;
	}
	while(carry!=0)
	{
		res.d[res.len++] = carry%10;
		carry/=10;
	}
	return res;
}

bign divide(bign a, int b)
{
	bign res = bign();
	int temp = 0;
	res.len = a.len;
	for(int i = a.len-1; i>=0; i--)
	{
		temp = temp*10+a.d[i];
		if(temp<b) res.d[i] = 0;
		else
		{
			res.d[i] = temp/b;
			temp %=b; 
		}			
	}
	while(res.len-1>=1&&res.d[res.len-1]==0)
		res.len--;
	return res;
	
}

int main(int argc, char *argv[])
{
	bign a = change("600");
	bign b = change("100");
	bign res = divide(a,3);
	cout<<res.d[2];
	return 0;
}




