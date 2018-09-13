/*----------------------------------------------------------------

* @Author: Su

* @Description: 想和筛选法比较来着 

* @Creath Date: 

----------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(int argc, char *argv[])
{
	int array[20000];
	int number,temp;
	int i,count = 1,j;
	int serial = 0,Prime = 0;
	scanf("%d",&number);
	time_t begin,end;
	
	begin = clock();
	if(number<2)
		{
			printf("%d",count = 0);return 0;
		}
	else if(number==2);	
	else
	{
		for(j=3;j<=number;j++)
		{
				temp = j;
				for(i = 2; i<= sqrt(temp);i++)
				{
					if(temp%i==0)
						break;
				}											
				if(i>sqrt(temp))
					{
						count++;
						array[serial] = temp;
						serial++;
					}
			
		}
		//printf("%d",count);
	}
	end = clock();
	
	for(i=0;i<count;i++)
	{
		if(array[i]+2 == array[i+1])
			Prime++;
	}
	printf("%d\n",Prime);
	printf("cost time: %fs ",(double)(end - begin)/ CLOCKS_PER_SEC);
	return 0;
}

