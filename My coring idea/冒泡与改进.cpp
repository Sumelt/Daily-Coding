/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date:

----------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <time.h>

short how_count_lastmax = 0;
short how_count_firstmin = 0;
short how_count = 0;
clock_t begin, end;
double  cost = 0;
bool flag;

int main(int argc, char *argv[])
{
	char array[10] = {'2','5','9','1','3','8','6','0','7','4'};
	char array1[10] = {'0','1','2','3','4','5','6','7','8','9'};
	short count = 10;
	char temp;
	int m = 0,i=0;	
	//begin = clock();
	 //¼¦Î²¾ÆÃ°ÅÝ 
	while(count>m)
	{
		
		for(int j = m; j< count-1; j++)
			{
				if(array[j]>array[j+1])
				{
					temp = array[j];
					array[j] = array[j+1];
					array[j+1] =  temp;
					how_count_lastmax++;
				}
					
			}
			count--;
		for(int j = count-1; j>m; j--)
			{
				if(array[j]<array[j-1])
				{
					temp = array[j];
					array[j] = array[j-1];
					array[j-1] =  temp;
					how_count_firstmin++;
				}
					
			}
			m++;
	}
	
	//end = clock();
	
	//cost =  (double)(end - begin)/ CLOCKS_PER_SEC;
	how_count = how_count_lastmax + how_count_firstmin;	
  	while(i!=10)		
		{
			printf("%c",array[i]);
			i++;
		}
	putchar('\n');	
	printf("cycle lastmax number: %d\n",how_count_lastmax);
	printf("cycle lastmin number: %d\n",how_count_firstmin);
	printf("cycle number: %d\n",how_count);
	//printf("Cost time: %fms",cost);
	putchar('\n');
	return 0;
}

/*
	//³õ¼¶£¬Ã°ÅÝ 
	for(int i = 0; i < count-1; i++)
		for(int j = 0; j< count-i-1; j++)
			{
				if(array[j]>array[j+1])
				{
					temp = array[j];
					array[j] = array[j+1];
					array[j+1] =  temp;
				}
					
			}
*/

/* 
	///ÓÐ±ê¼ÇÃ°ÅÝ 
	for(int i = 1; i < count; i++)
	{
		flag = true;
		for(int j = 0; j< count-i; j++)
			{
				if(array[j]>array[j+1])
				{
					temp = array[j];
					array[j] = array[j+1];
					array[j+1] =  temp;
					flag = false;
					how_count++;
				}
					
			}
		if(flag)
			break;
	}
	*/	

