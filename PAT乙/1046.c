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
	int i = 0;
	int jcount = 0,ycount = 0;
	int jspek,jplan;
	int yspek,yplan;
	scanf("%d",&i);
	while(i-->0&&scanf("%d%d%d%d",&jspek,&jplan,&yspek,&yplan))
	{
		if(jplan==jspek+yspek&&yplan!=jspek+yspek)
			jcount++;
		else if(yplan==jspek+yspek&&jplan!=jspek+yspek)
			ycount++;
	}
	printf("%d %d",ycount,jcount);
	return 0;
}

