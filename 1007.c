/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(int argc, char *argv[])
{
	int array[10000];
	int number,temp;
	int i,count = 1,j;
	int serial = 0,Prime = 0;
	scanf("%d",&number);
	
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
	}
	for(i=0;i<count;i++)
	{
		if(array[i]+2 == array[i+1])
			Prime++;
	}
	printf("%d",Prime);
	return 0;
}

