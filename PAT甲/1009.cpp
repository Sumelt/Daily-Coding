/*----------------------------------------------------------------

* @Author: Su

* @Description: can not understand requirement 

* @Creath Date: 11/10/18 16:54

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>


using namespace std;

typedef struct info{
	int exp;
	double coe;
}infos;

double ans[2001] = {0};

int main(int argc, char *argv[])
{
	int ct1, ct2;
	int texp;
	double tcoe;
	infos in[1001];
	
	scanf("%d",&ct1);
	for(int i =0; i<ct1; i++)
		scanf("%d %lf",&in[i].exp, &in[i].coe);
	scanf("%d",&ct2);
	for(int i =0; i<ct2; i++)
	{
		scanf("%d %lf",&texp, &tcoe);
		for(int j =0; j<ct1; j++)
			ans[in[j].exp+texp]+= in[j].coe*tcoe;
	}
	ct1 = 0;int i = 0;
	while(i<2001)
		{if(ans[i]) ct1++; i++;}		
	cout<<ct1;
	i = 2000;
	while(i>=0)
		{if(ans[i]) printf(" %d %.1f", i, ans[i]); i--;}
		
}




