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
	int begin,end;
	int temp;
	int i,j;
	bool flag = false;
	int count = 0;
	int N = 0;
	
	scanf("%d %d",&begin,&end);

	for(j=2;count<begin;j++)
		{
				temp = j;
				for(i = 2; i<= sqrt(temp);i++)
				{
					if(temp%i==0)
						break;
				}
				if(i>sqrt(temp))
					count++;										
		}
		printf("%d",temp);
		flag = true;
		N++;
	for(j=temp+1;count<end;j++)
		{
				temp = j;
				for(i = 2; i<= sqrt(temp);i++)
				{
					if(temp%i==0)
						break;
				}
				if(i>sqrt(temp))
				{
					count++;
					if(flag) putchar(' ');
					printf("%d",temp);
					N++;
					flag = true;
				}
				if(N%10==0&&flag)
					{
						putchar('\n');
						flag = false;
					}
		}
	return 0;
}

