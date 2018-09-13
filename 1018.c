/*----------------------------------------------------------------

* @Author: Su

* @Description: 晴神的思路果然很屌，想法很号，为什么我就想不到呢，哭 

* @Creath Date: 

----------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int retnumber(char str);

int main(int argc, char *argv[])
{
	int i = 0,j;
	char ja,yi;
	int Anumb[3]={0};
	int Bnumb[3]={0};//win same fail 
	int times_A[3]={0};
	int times_B[3]={0};
	int JA,YI;
	char mp[3] = {
		'B','C','J'
	};//bu shi jian
	scanf("%d",&i);
	getchar();
	while(i-->0)
	{
		scanf("%c %c",&ja,&yi);
		getchar();
		JA = retnumber(ja);
		YI = retnumber(yi);
		if((JA+1)%3==YI)
		{
			Anumb[0]++;
			Bnumb[2]++;
			times_A[JA]++;
		}
		else if(JA==YI)
		{
			Anumb[1]++;
			Bnumb[1]++;
		}
		else if((YI+1)%3==JA)
		{
			Anumb[2]++;
			Bnumb[0]++;
			times_B[YI]++;
		}
	}
	printf("%d %d %d\n",Anumb[0],Anumb[1],Anumb[2]);
	printf("%d %d %d\n",Bnumb[0],Bnumb[1],Bnumb[2]);
	JA = 0;YI = 0;
	for(i=0;i<3;i++)
	{
		if(times_A[i]>times_A[JA]) JA = i;
		if(times_B[i]>times_B[YI]) YI = i;
	}
	printf("%c %c",mp[JA],mp[YI]);
	return 0;
}

int retnumber(char str)
{
	if(str=='B') return 0;
	else if(str=='C') return 1;
	else if(str=='J') return 2;
}


