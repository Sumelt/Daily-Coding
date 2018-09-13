/*----------------------------------------------------------------

* @Author: Su

* @Description: 先系数后指数 ，可优化，想得复杂，题目没看懂是最骚的 

* @Creath Date: 

----------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int array[10001];
	int i;
	int count;
	int flag = 0;
	scanf("%d %d",&array[0],&array[1]);
	count = array[1] -1;
	for(i = 2;count>0;count--,i+=2)
		scanf("%d %d",&array[i],&array[i+1]);
	count = array[1];
	if(count == 0)
		printf("0 0");
	for(i=0;count>0;i+=2)
	{
		if(array[i]*array[i+1]==0)
		{				
				if(flag==0)
					printf("0 0");
				flag++;
		}			
		else
		{
			if(flag==0)
					printf("%d",array[i]*array[i+1]);
				else
					printf(" %d",array[i]*array[i+1]);
			printf(" %d",array[i+1]-1);
			flag++;
		}
		count--;
	}
		
	return 0;
}

