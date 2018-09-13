/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <string.h>

using namespace std;

int two_points(int array[],int num, int aim)
{
	int count = 0;
	int i = 0,j = num-1;
	while(i<=j)
	{
		if(array[i]+array[j]==aim)
		{
			count++;
			i++;
			j--;
		}			
		else if(array[i]+array[j]>aim) j--;//[i,j--]才可能满足跳出条件 
		else if(array[i]+array[j]<aim) i++;  //[i++,j]才可能满足跳出条件
		
	}
	return count;
}

int main(int argc, char *argv[])
{
	int num = 5;
	int array[num] = {1,2,3,4,5};
	cout<<two_points(array,num,5);
	return 0;
}




