/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date:

----------------------------------------------------------------*/
#include <iostream>
#include <cstring>
#include <ctime>
using namespace std;

//���ð�� 
void BubbleSort( char *array, int N )
{
	for( int i = 0; i < N - 1; ++i ) //ѭ�� N -1 �� 
	{
		bool flag = false; //��һ��ɨ��  ��־λ��û�з����ı� ��ʾ ����������� 
		for( int j = 0; j < N - 1 - i; ++j ) // N - 1��ֹ ��� + 1 ��� 
		{
			if( array[ j ] > array[ j+1 ] )
			{
				swap( array[ j ], array[ j+1 ] );
				flag = true;
			}			
		}
		if( !flag ) break;
	}	
}

//��β��ð�� 
void CocktailSort( char *array, int N )
{
	int count = N;
	int Lindex = 0;
	bool flag = false;
	for( int i = 0; count > 0; ++i, count -= 2 )
	{   
		int j = Lindex;
		for( ; j < N - 1 - i; ++j ) //�ϴ��Ѿ��ź� �ŵ����һλ
		{
			if( array[ j ] > array[ j+1 ] )
			{
				swap( array[ j ], array[ j+1 ] );
				flag = true;
			}			
		}
		if( !flag ) break;
		for( int i = j; i > Lindex; --i ) //��С�Ѿ��ź� �ŵ���һλ
		{
			if( array[ i ] < array[ i-1 ] )
				swap( array[ i ], array[ i-1 ] );			
		}
		 ++Lindex; 
	}
}

int main(int argc, char *argv[])
{
	char array[] = {'2','5','9','1','3','8','6','0','7','4'};
	CocktailSort( array, sizeof( array )/ sizeof( *array ) );
	
	auto start = begin( array );
	auto last = end( array );
	while( start != last )
		cout << *start++ << ' ';
	
/*
	printf("cycle lastmax number: %d\n",how_count_lastmax);
	printf("cycle lastmin number: %d\n",how_count_firstmin);
	printf("cycle number: %d\n", sizeof( array )/ sizeof( *array ) );
	printf("Cost time: %fms\n",how_count_lastmax - how_count_firstmin );*/
	return 0;
}
