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
	int A1,A2,A3,A4,A5;
	float A4con = 0;
	int number;
	bool flag = true;
	int i = 0;
	int count = 0;

	A1 = 0; A2 = A1; A3 = A1; A5 = A1; A4 = 0;
	
	scanf("%d",&i);
	while(count<i)
	{		
		scanf("%d",&number);
		if(number%5==0)
		{
			if(number%2==0)
				A1+=number;
		}			
		else if(number%5==1)
		{
			if(flag)
			{
				A2 += number; 
				flag = false;
			}
			else
			{
				A2 -= number; 
				flag = true;
			}
		}
		else if(number%5==2)
			A3++;
		else if(number%5==3)
			{
				A4+=number;
				A4con++;
			}
		else if(number%5==4)
		{
			if(number>A5)
			A5 = number;
		}		
		count++;
	}
	if(A1!=0)
		printf("%d",A1);
	else printf("N");
	if(A2!=0)
		printf(" %d",A2);
	else printf(" N");
	if(A3!=0)
		printf(" %d",A3);
	else printf(" N");
	if(A4!=0)
		printf(" %.1f",A4/A4con);
	else printf(" N");
	if(A5!=0)
		printf(" %d",A5);
	else printf(" N");
	return 0;
}

