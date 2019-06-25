/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int array[3] = {
		2,3,4
	};
	int *point;
	point = array;
	//printf("%d",(*point)+1);
	//printf("%d",*point);
	int **point2;
	point2 = &point ;
	printf("%p\n",point);
	printf("%d",**point2);
	return 0;
}

