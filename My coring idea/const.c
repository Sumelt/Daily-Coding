/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	/*const int a = 425;
	a = 450;   //error
	int b = 450;
	const int *point;
	point = &b;
	*point = 470; //error
	int* point2;
	point2 = &a;   //warning
	*point2 = 480;
	*/
	double array[2]={
		1,2
	};
	const double *const pt = array;
	pt = &array[1];  //非法修改地址
	*pt = 450;  	//非法修改数值
	printf("%d",a);
	int array2[-1];
	return 0;
}



