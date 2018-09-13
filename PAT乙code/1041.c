/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct stu{
	char idnum[14];
	int testnum;
	int examnum; 
}stuinfo;

int main(int argc, char *argv[])
{
	int i = 0;int j = 0;
	int temp;int count;
	int array[1000];
		
	scanf("%d",&i);
	stuinfo stus[i];
	temp = i;	
	while(i-->0)
	{
		getchar();
		scanf("%s %d %d",&stus[j].idnum,&stus[j].testnum,&stus[j].examnum);
		j++;		
	}	
	scanf("%d",&count);
	for(j=0;j<count;j++)
		scanf("%d",&array[j]);
	j = 0;
	i = 0;
	while(1)
	{
		if(stus[j].testnum==array[i])
		{
			printf("%s %d\n",stus[j].idnum,stus[j].examnum);
			if(i==count-1)
				break;
			else i++;
			j = 0;
		}
		else if(j==temp-1)
					j = 0;
		else j++;	
	}	
	return 0;
}

