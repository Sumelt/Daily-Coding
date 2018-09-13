/*----------------------------------------------------------------

* @Author: Su

* @Description: 无法解决，耗费多个小时

* @Creath Date: 

----------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
	int i,j;
	int number,a_n,b_n;
	unsigned flag = 1;
	char array_a[110]={0},array_b[110]={0};
	char res[110] = {0};
	int k = 0;
	int max_long,gap;
	scanf("%s %s",array_a,array_b);
	i = strlen(array_a)-1;
	j = strlen(array_b)-1;
	if(i>j)
	{
		max_long = i;
		gap = i-j;
		for(k=1;k<=gap;k++)
				array_b[j+k] = '0';
	}
	else max_long = j;
	k = 0;
	while(max_long-->=0)
	{
		a_n = i>=0? array_a[i]-'0':0;
		b_n = j>=0? array_b[j]-'0':0; 
		if(flag%2!=0)  //奇数情况 
		{
			number = (a_n+b_n)%13;
			if(number==10)
				res[k++] = 'J';
			else if(number==11)
				res[k++] = 'Q';
			else if(number==12)
				res[k++]=='K';
			else res[k++] = number+48;
		}
		else    //偶数情况 
		{
	 		number = b_n - a_n;
	 		if(number<0)
	 			number += 10;
 			res[k++] = number +48;	
		}
		j--;i--;
		flag--;
	}

	for(i = strlen(res)-1;i>=0;i--)
		printf("%c",res[i]);
		
	return 0;
}

