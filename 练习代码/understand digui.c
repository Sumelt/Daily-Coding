/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date:

----------------------------------------------------------------*/

/*¿ÌΩ‚C”Ô—‘µ›πÈ∫Ø ˝*/

#include<stdio.h>

void up_and_down(int);

int  main(void)
{
	up_and_down(1);
	return 0;
}


void up_and_down(int n)
{
	printf("level %d: n loacation %p\n", n, &n);/*1*/
	if (n < 4)
		up_and_down(n + 1);
	printf("level %d: n loacation %p\n", n, &n);/*2*/
}




