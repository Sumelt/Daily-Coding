/*----------------------------------------------------------------

* @Author: Su

* @Description: 1005 ¼ÌÐø(3n+1)²ÂÏë

* @Creath Date: 7-23 

----------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int cmp(const void * p1, const void * p2); 

int main(int argc, char *argv[])
{
	int count;
	scanf("%d",&count);
	int savary[count];
	int number;
	bool numbary[1000] = {0};
	int key = 0;
	
	int i;
	for(i=0;i<count;i++)
	{
		scanf("%d",&savary[i]);
		number = savary[i];
		while(number!=1)
		{
			if(number%2 == 0 )
            	{
					number = number /2;
					numbary[number] = true;
            	}
        	else
            	{
					number = (3 * number + 1)/2;
					numbary[number] = true;
            	}
		}
	}
		
	for(i=0;i<count;i++)
		if(numbary[savary[i]]==false)
			key++;	
				
	qsort(&savary,count,sizeof(int),cmp);

	for(i=0;i<count;i++)
	{
		if(numbary[savary[i]]==false)
		{
			printf("%d",savary[i]);
			key--;
			if(key>0)
				printf(" ");
		}
					
	}
	return 0;
}

int cmp(const void * p1, const void * p2)
{
    const int * a1 = (const int *) p1; 
    const int * a2 = (const int *) p2;
    
    if(*a1<*a2)   //big-->small
    	return 1;
   	else if(*a1==*a2)
   		return 0;
  		else return -1;
    	
}
