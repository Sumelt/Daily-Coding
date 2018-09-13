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
int main(int argc, char *argv[])
{
	int N;
	int evencount = 0;
	int oddcount = 0;
	int count;
	int i,j;
	puts("Please input a number list to range");	
	scanf("%d",&N);
	bool array[20000] = {0};
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
	oddcount = N-evencount-1;
	printf("odd number: %d\n",oddcount);
	count = oddcount;
	
	begin = clock();
	while(count>0)
	{
		for(i=N;i>2;i--)
		{
			if(array[i]==false)
			{
				j = i-1;
				while(j>2)
				{
						if(i%j==0)
						{
							array[i] = true;
							//array[j] = true;
						}					
					j--;	
						
				}
				count--;
			}
		}
	}
	end = clock();
	
	printf("The prime number between 2 and %d is: ",N);
	for(i=2;i<N+1;i++)
		if(array[i]==false)
			printf("%d ",i);
	putchar('\n');
	if(array[N]==false)
		printf("%d is a primer number\n",N);
		else printf("%d is not a primer number\n",N);
	printf("cost time: %fs ",(double)(end - begin)/ CLOCKS_PER_SEC);
	putchar('\n');
	return 0;
}

