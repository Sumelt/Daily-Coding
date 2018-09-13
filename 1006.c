/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	char array[2] = {
		'B','S'
	};
	char savary[100];
	int number;
	int i,temp;
	char j = '1';
	scanf("%d",&number);
	
	temp = number%10-1;
	
	for(i=temp;i>=0;i--)  //个位 
	{
		savary[i] = j;
		j++;
	}
	number = number/10;
	
	if(number!=0)   //十位 
	{
		temp = temp+number%10;
		for(i = temp,j = number%10; j>0;i--)
			{
				savary[i] = 'S';
				j--;
			}
			
	}
	
	number = number/10;
	
	if(number!=0)    //百位 
	{
		temp = temp+number%10;
		for(i = temp,j = number%10; j>0; i--)
		{
				savary[i] = 'B';
				j--;
		}
	}
	while(temp>=0)
	{
		printf("%c",savary[temp]);
		temp--;
	}
	return 0;
}

