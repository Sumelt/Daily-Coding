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
	unsigned int begin;
	unsigned long hour,min;
 	unsigned int s;
	unsigned long end;
	float res;
	
	scanf("%u %lu",&begin,&end);
	res = (end - begin)/100.0+0.5; 
	hour = res / 3600;
	min  = (res - hour*3600)/60;
	s = res - hour*3600 - min*60;
	printf("%02d:%02d:%02d",hour,min+i,s);
	return 0;
}

