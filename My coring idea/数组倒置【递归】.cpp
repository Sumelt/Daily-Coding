/*----------------------------------------------------------------

* @Author: Su

* @Description: ������֮ 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>

using namespace std;

myswap(int *A, int L, int R)
{
	A[L] = A[L]+A[R];
	A[R] = A[L] - A[R];
	A[L] = A[L] - A[R];
}

void myReverse(int *A, int L, int R)
{
	
	if(L>R||(A+L)==(A+R)) return ; //same address prove is odd 
	else{
		myswap(A, L, R);
		myReverse(A, L+1, R-1);		
	}
	 
}

int main(int argc, char *argv[])
{
	int indx = 6;
	int array[indx] = {1, 2, 3, 4, 5, 6};
	myReverse(array, 0, indx-1);
	for(int i =0; i<indx; i++)
		cout<<array[i]<<' ';
	return 0;
}




