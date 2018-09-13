/*----------------------------------------------------------------

* @Author: Su

* @Description: 几个小时都不AC，好像是数据类型有问题啊，脑壳疼 

* @Creath Date: 

----------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int mycmp(const void* p1,const void* p2);

int main(int argc, char *argv[])
{
	int i = 0,j;
	unsigned long N;
	unsigned long P;
	bool flag = false;
	scanf("%lu %lu",&N,&P);
	long array[N];
	//while(scanf("%d",&array[i++])!=EOF&&getchar()!='\n');
	for(i=0;i<N;i++)
	{
		scanf("%ld",&array[i]);
	}
	qsort(&array,N,sizeof(long),mycmp);
	for(j=N-1;j>0;j--)
	{
		for(i=0;i<N;i++)
		{
			if(array[i]*P>=array[j])
				{
					flag = true;
					break;
				}
		}
		if(flag)
			break;
	}
	if(!flag)
		printf("0");
	else printf("%d",N-i);
	return 0;
}

int mycmp(const void* p1,const void* p2)
{
	const long *a1 = (const long*) p1;
	const long *a2 = (const long*) p2;
	if(*a1<*a2)
		return -1;
	else if(*a1==*a2) 
		return 0;
		else return 1;
}