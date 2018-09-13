/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int count;
	int i = 0;
	int frequency;
	scanf("%d",&count);
	scanf("%d",&frequency);
	int array[count];
	if(frequency>count)
	{
		frequency  = frequency %count;
	}
	while(i<count)
	{
		scanf("%d",&array[i]);
		i++;
	}
	for(i = count - frequency; i<=count-1;i++ )
		{
			printf("%d",array[i]);
			putchar(' ');
		}
	for(i = 0;i<count - frequency;i++)
		{
			printf("%d",array[i]);
			if(i<count-frequency-1)
				putchar(' ');
		}
	return 0;
}

