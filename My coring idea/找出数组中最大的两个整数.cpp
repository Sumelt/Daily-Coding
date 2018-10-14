/*----------------------------------------------------------------

* @Author: Su

* @Description:一次遍历找到结果 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>

using namespace std;

void findBgNm(int *A, int *fPO, int *sPO, int n)
{
	
	if(*fPO<*sPO)
	{
		int *tp = fPO;
		fPO = sPO;
		sPO = tp;
	}
	
	for(int i = 2; i<n; i++)
	{
		if(*(A+i)>*sPO){
			if(*fPO<*(A+i)){
				sPO = fPO;
				fPO = A+i;
			}
			else sPO = A+i;			
		}				
	}
	printf("%d %d", *fPO, *sPO);
}

int main(int argc, char *argv[])
{
	int indx = 6;
	int array[indx] = {1, 2, 89, 4, 5, 6};
	int *fPO = array, *sPO = (array+1);
	findBgNm(array, fPO, sPO, indx);
	return 0;
}




