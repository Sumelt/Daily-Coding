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
	//int a,b,c,d;
	//d = scanf("%d %d",&a,&b);
	//printf("%d %d\n",a,b);
	//printf("%d",d);
	char array[10];
	int i = 0;
	scanf("%3s",array);
	while(array[i])
	{
		printf("%c",array[i++]);
		//printf("cath a ' 'or '\\t'or '\\n'");
		//break;
	}
	//printf("ending\n");
	return 0;
}

