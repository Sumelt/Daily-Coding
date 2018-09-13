/*----------------------------------------------------------------

* @Author: Su

* @Description: 算法笔记有更简单的写法，我的太繁琐 

* @Creath Date: 

----------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
	int i = 0;
	long Galleon,myGalleon;
	int Sickle,Knut,mySickle,myKnut;
	int RemainGalleon,RemainSickle,RemainKnut;
	
	scanf("%ld.%d.%d",&Galleon,&Sickle,&Knut);
	scanf("%ld.%d.%d",&myGalleon,&mySickle,&myKnut);
			
		if(myGalleon*17*29+mySickle*29+myKnut>=Galleon*17*29+Sickle*29+Knut){
			RemainGalleon = myGalleon - Galleon;
			RemainSickle = mySickle - Sickle;
			RemainKnut = myKnut - Knut;
				if(RemainSickle<0){
					RemainSickle = RemainSickle+17;
					RemainGalleon--;
				}
				if(RemainKnut<0){
					RemainKnut = RemainKnut+29;
					RemainSickle--;
					if(RemainSickle<0){
						RemainSickle = RemainSickle+17;
						RemainGalleon--;
					}
				}
			}
			else
			{
				RemainGalleon =  (Galleon -myGalleon);
				RemainSickle = (Sickle - mySickle);
				RemainKnut = (Knut - myKnut);
				if(RemainSickle<0){
					RemainSickle = RemainSickle+17;
						RemainGalleon--;
				}
				if(RemainKnut<0){
						RemainKnut = RemainKnut+29;
						RemainSickle--;
						if(RemainSickle<0){
						RemainSickle = RemainSickle+17;
						RemainGalleon--;
					}
				}
				printf("-");
			}
	printf("%d.%d.%d",RemainGalleon,RemainSickle,RemainKnut);
	return 0;
}

