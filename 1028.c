/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int mycmp(const void* p1,const void* p2);

typedef struct info{
	char name[6];
	int year;
	int mon;
	int day;
	long long age;
}infos;

int main(int argc, char *argv[])
{
	int i = 0,count,j;
	scanf("%d",&count);
	infos penson[count];
	for(i = 0,j = 0;j<count;j++)
	{
		scanf("%s",penson[i].name);
		scanf("%d/%d/%d",&penson[i].year,&penson[i].mon,
		&penson[i].day);
		penson[i].age = penson[i].year*10000+penson[i].mon*100+penson[i].day;
		if(penson[i].age<=20140906&&penson[i].age>=18140906)
			i++;
		
	}
	if(i>0)
	{
		qsort(&penson,i,sizeof(struct info),mycmp);
		printf("%d ",i);
		printf("%s %s",penson[0].name,penson[i-1].name);
	}
	else printf("0"); 
	return 0;
}

int mycmp(const void* p1,const void* p2)
{
	const infos* a1 = (const infos*) p1;
	const infos* a2 = (const infos*) p2;
	if(a1->age<a2->age)
		return -1;
	else if(a1->age==a2->age)
		return 0;
	else return 1;
}
