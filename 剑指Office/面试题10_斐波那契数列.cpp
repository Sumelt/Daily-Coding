/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
using namespace std;

//ѭ��ʵ�� 
int Fibonacci2(int n) {
	int res = 0;
	int temp1 = 0, temp2 = 1;
	if( n == 0 || n == 1 ) 
		return n == 1? temp2 : temp1; 
	
	for( int i = 2; i <= n; ++i ) {		
		res = temp1 + temp2;
		temp1 = temp2;
		temp2 = res;	
	}
	return res;	
}
//β�ݹ�
int Fibonacci3(int n, int res1, int res2) {
	if( n == 0 || n == 1 ) 
		return n == 1? res1 : 0; //���� ���� res1 ����Ϊ �洢�Ž�� 
	return Fibonacci3( n - 1, res2, res2 + res1 ); //�� ��n �����  1�� �Ľ�����Ǵ� �� 1��ӵ� �� n �� 
} 


//�ݹ�ʵ��
int Fibonacci(int n) {
	if( n == 0 || n == 1 ) 
		return n == 1? 1 : 0;
	return Fibonacci( n - 1 ) + Fibonacci( n - 2 ); 
}

int main(int argc, char *argv[])
{
	cout << Fibonacci3( 39, 1, 1 ) << endl;
	cout << Fibonacci2(39); //4 * 8 = 32 bit = 2 ^32 = 2147483647
	return 0;
}