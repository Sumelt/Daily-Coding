/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	double array2[3] = {1,2,3};
	int array[2]={
		1,2
	};
	printf("%d\n",sizeof array[0]); //one element length 
	printf("%d",sizeof array);//all array length 
	puts("\n");
	return 0;
}

