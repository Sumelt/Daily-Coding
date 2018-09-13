/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

void cal(int * left,int *right,int i);
int main(int argc, char *argv[])
{
	int N,remainder = 0,count = 0;
	int left = 7,right = 17;
	int tempN,maxodd;
	int i,now;
	char str;
	
	scanf("%d %c",&N,&str);
	tempN = N;
	while(!(N>=left&&N<=right))
	{
		i++;
		cal(&left,&right,right-left);
	}
	if(N>=left&&N<right)
	{
		remainder =  tempN - left;
		count = left;
	}else if(N==right) 
	{
		
			remainder =  tempN - right;
			count = right;
	}
	else printf("failed\n");
	count = (count-1)/2;
	i = 3;
	while(count!=0)
	{
		count-=i;
		i+=2;		
	}
	maxodd = i-2;
	now = maxodd;
	while(now>0)
	{
		
		i = (maxodd - now)/2;
		while(i-->0)
			printf(" ");
		for(i=now;i>0;i--)
		{
			printf("%c",str);
		}
		putchar('\n');
		now -=2; 
	}
	now = 3;
	while(now<=maxodd)
	{
		i = (maxodd - now)/2;
		while(i-->0)
			printf(" ");
		for(i=now;i>0;i--)
		{
			printf("%c",str);
		}
		putchar('\n');
		now +=2; 
	}
	printf("%d",remainder);
	return 0;
}

void cal(int * left,int *right,int i)
{
	int *temp = (int*)malloc(sizeof(int));
	*temp = *right;
	*right = *right+i+4;
	*left = *temp;
}
