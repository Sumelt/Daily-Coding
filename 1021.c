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
	char array[1000];
	int count[10] = {0};
	int i;
	scanf("%s",array);
	getchar();
	for(i=0;i<strlen(array);i++)
	{
			if(array[i]=='0')
			count[0]++;
		else if(array[i]=='1')
			count[1]++;
		else if(array[i]=='2')
			count[2]++;
		else if(array[i]=='3')
			count[3]++;
		else if(array[i]=='4')
			count[4]++;
		else if(array[i]=='5')
			count[5]++;
		else if(array[i]=='6')
			count[6]++;
		else if(array[i]=='7')
			count[7]++;
		else if(array[i]=='8')
			count[8]++;
		else if(array[i]=='9')
			count[9]++;
	}
	for(i=0;i<10;i++)
	{
		if(count[i]>0)
			printf("%d:%d\n",i,count[i]);
	}
	return 0;
}

