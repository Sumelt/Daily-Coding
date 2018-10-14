/*----------------------------------------------------------------

* @Author: Su

* @Description: ¶þ·ÖµÝ¹é

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>

using namespace std;

static int sum = 0;

int myadd(int *A, int L, int R)
{
	if(L==R) return A[L];
	else 
		return myadd(A, L, (L+R)/2)+myadd(A, (L+R)/2+1, R);
}
int main(int argc, char *argv[])
{
	int indx = 6;
	int array[indx] = {1, 2, 3, 4, 5, 6};
	printf("%d",myadd(array, 0, indx-1));
	return 0;
}




