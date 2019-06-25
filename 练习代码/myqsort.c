/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

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

int main(int argc, char *argv[])
{
	int count = 6;
	int i;
	int array[count];
	puts("input six number"); 
	for(i=0;i<6;i++)
		scanf("%d",&array[i]);
	qsort(&array,6,sizeof(int),cmp);
	for(i=0;i<6;i++)
		printf("%d ",array[i]);
	return 0;
}

