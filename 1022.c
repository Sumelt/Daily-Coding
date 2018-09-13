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
	unsigned long long a,b,num;
	int d;
	int array[10000];
	int count,i = 0;
	scanf("%llu %llu %d",&a,&b,&d);
	num = a+b;
	while(num!=0)
	{
		array[i++] = num%d;
		num = num/d;		
	}
	if(i>0)	
	{
		for(i=i-1;i>=0;i--)
			printf("%d",array[i]);
	}else printf("0");
	
	return 0;
}

