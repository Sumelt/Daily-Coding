/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date: 06/09/18 21:02

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	unsigned n;
	double res = 0;
	double array[100000]={0};
	scanf("%d",&n);		
		for(unsigned j = 0; j<n; j++)
		{
			scanf("%lf",&array[j]);	
			res += array[j]*((j*(n-j))+(n-j));
		}
	printf("%.2f",res);
	return 0;
}

