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
	int array[10];
	int i = 0 , j;
	int count0;
	for(i=0;i<10;i++)
	{
		scanf("%d",&array[i]);
	}
	for(i=0;i<10;i++)
	{
		if(array[i]>0&&i==0)
		{
			count0 = array[i];
		}
		else
		{
			if(array[i]>0)
			{
				if(count0>0)
				{						
					printf("%d",i);
					while(count0-->0)
					printf("0");
					j = 1;											
				}
				
				for(j;j<array[i];j++)
				{
					printf("%d",i);				
				}
				j=0;						
			}
			
		}
	}
	return 0;
}

