/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date: 02/09/18 17:54

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <string.h>
//#include <bits/stdc++.h>

using namespace std;

#define max 10000 

struct pin{
	double sav;
	double pic;
	double onepic;
}monpin[1000];

int cmp(struct pin a, struct pin b)
{
	if(a.onepic>b.onepic) return 1;
	 else return 0;
}

int main(int argc, char *argv[])
{
	int count,ned;
	double money = 0;	
	scanf("%d %d",&count,&ned);
	for(int i = 0; i<count; i++)
		scanf("%lf",&monpin[i].sav);
	for(int i = 0; i<count; i++)
		{
			scanf("%lf",&monpin[i].pic);
			monpin[i].onepic = monpin[i].pic / monpin[i].sav;
		}
	sort(&monpin[0], &monpin[0]+count, cmp);

	for(int i = 0; i<count;  i++)
	{
		if(ned<=0)
			break;
		if(ned<monpin[i].sav)
			money+=monpin[i].onepic * ned;
		else if(ned>=monpin[i].sav) money+=monpin[i].onepic * monpin[i].sav;
			ned-=monpin[i].sav;
	}
	printf("%.2f",money);
	return 0;
}




