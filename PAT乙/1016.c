/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
	char numb1[100],numb2[100];
	char a,b;
	int i = 0,j = 0;
	int res1 = 0,res2 = 0;
	char *p;
	 p = numb1;
	scanf("%s %c",numb1,&a);
	scanf("%s %c",numb2,&b);
	getchar();
	while(*p)
	{
		if(*p==a)
			i++;
		p++;
	}
	p = numb2;
	while(*p)
	{
		if(*p==b)
			j++;
		p++;
	}
	while(i>0||j>0)
	{
		if(i-->0)
			res1 = res1*10+a-'0';
		if(j-->0)
			res2 = res2*10+b-'0';

	}
		
	printf("%d",res1+res2);
	return 0;
}

