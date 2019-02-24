/*----------------------------------------------------------------

* @Author: Su

* @Description: 200以内的素数 ,时间复杂度有点高，貌似去掉因数那步有问题

 20000个数据，花费500ms 

* @Creath Date: 7-24 

----------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define maxn 20000

int main(int argc, char *argv[])
{
	int N;
	int evencount = 0;
	int oddcount = evencount;
	int count, prmN = 0;
	int i,j;
	
	puts("Please input a number list to range");	
	scanf("%d",&N);
	bool array[maxn] = {0};
	int prime[maxn] = {0};
	time_t begin,end;
	
	
	if(N==2)
	{
		puts("2 is a primer number ,but it have no other primer number");
		exit(0);
	}
	for(i=4;i<=N;i=i+2)
	{
		array[i] = true;    //排除偶数 
		evencount++;
	}
	printf("eve number: %d\n",evencount);
	oddcount = N-evencount;
	printf("odd number: %d\n",oddcount);
	count = oddcount;
	
	begin = clock();

	for(i = 2; i<N; i++)
	{
		if(array[i]==false)
			prime[prmN++] = i;
		for(j = i+i; j<N; j +=i )
			array[j] = true;
			
	}

	end = clock();
	
	printf("The prime number between 2 and %d is: ",N);
	for(i=0;i<prmN;i++)
			printf("%d ",prime[i]);
	putchar('\n');
	if(array[N]==false)
		printf("%d is a primer number\n",N);
		else printf("%d is not a primer number\n",N);
	printf("cost time: %fs ",(double)(end - begin)/ CLOCKS_PER_SEC);
	putchar('\n');
	return 0;
}
