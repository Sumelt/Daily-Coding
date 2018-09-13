/*----------------------------------------------------------------

* @Author: Su

* @Description: 随机数自动存入 

* @Creath Date: 

----------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30
int main(int argc, char *argv[])
{
	int count = 0,filecount = 0;
	int i = 0;
	int buf[MAX];
	FILE *p;
	
	if((p = fopen("number_rand.dat","a+b"))==NULL)
		{
			puts("opend E:\\nmber_rand.dat failed\n");
			exit(1);
		}
		
	rewind(p);
	
	while(count<MAX&&fread(&buf[count],sizeof(int),1,p)==1)   
		{
			if(count==0)
				puts("There are Last time number:");
			printf("%d ",buf[count]);
			count++;
		}
		putchar('\n');
	filecount = count;
	if(count<MAX)
		while(i!=5)
		{
			buf[count] = rand()%100/2;
			printf("wirting:%d ",buf[count]);			
			count++;
			i++;
			
		}
	fwrite(&buf[filecount],sizeof(int),count-filecount,p);
	if(count==MAX)
		puts("File filled\n");
	
	return 0;
}

