/*----------------------------------------------------------------

* @Author: Su

* @Description: �����ӵ������ 

* @Creath Date: 

----------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char *argv[])
{
	int a = 10;
	srand((unsigned int)time(NULL)); //�ṩα���������  
	while(a--!=0)
	//printf("%.1f ",(double)(rand()%10));
	printf("%d %lf ",rand(),(rand()/(RAND_MAX+1.0)));
	return 0;
}

