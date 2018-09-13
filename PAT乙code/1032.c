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
	unsigned int i = 0,j;
	int stus[100000] = {0};
	int score;
	int number;
	scanf("%u",&i);
	for(j = 0;j<i;j++)
	{
		scanf("%d %d",&number,&score);
		stus[number] += score;
	}
	for(j=0;j<i;j++)
	{
		if(stus[j]>score)
			{
				score = stus[j];
				number = j;
			}
	}
	printf("%d %d",number,score);
	return 0;
}

