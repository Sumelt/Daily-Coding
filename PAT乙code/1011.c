/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int num;
	long a,b;
	long long c;
	int i = 1;
	scanf("%d",&num);
	while(i<=num)
	{
		scanf("%d%d%lld",&a,&b,&c);
		if(a+b>c)
			printf("Case #%d: true\n",i);
		else
			printf("Case #%d: false\n",i);
		i++;
	}
	return 0;
}

