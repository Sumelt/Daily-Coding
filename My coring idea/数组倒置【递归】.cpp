/*----------------------------------------------------------------

* @Author: Su

* @Description: ºı∂¯÷Œ÷Æ 

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
	if(A[L]>A[R]){
		A[L] -= (A[L]-A[R]);
		A[R] += (A[L]-A[R]);
	} 
	else{
		
		A[L] += A[R]-A[L];
		A[R] -= A[R]-A[L];
		cout<<A[L]<<' '<<A[R]<<endl;
	} 
}

void myReverse(int *A, int L, int R)
{
	if(L>R) return ;
	else{
		myswap(A, L, R);
		myReverse(A, L+1, R-1);		
	}  
}

int main(int argc, char *argv[])
{
	int array[] = {1, 2, 3, 4, 5, 6};
	myReverse(array, 0, 5);
	for(int i =0; i<6; i++)
		cout<<array[i]<<' ';
	return 0;
}




