/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
using namespace std;

int findAppearingOneTime( int *array, int n )
{
	int bitArray[ 32 ] = { 0 };//�洢������ÿһλ���ֵĴ���
	
	for( int i = 0; i < n; ++i )
	{
		int andBit = 1;//���������ж�ÿһλ
        //�����λ��ʼ
		for( int bitIndex = 31; bitIndex >= 0; --bitIndex ) {
			if( ( andBit & array[ i ] ) != 0 ) //����һ��ע���ϵ�������λ������ȼ���Ҫ��
				bitArray[ bitIndex ] += 1;//�����λ���ֵĴ���
			andBit <<= 1; 
		}
	}	
	int res = 0;
    //�����λ��ʼ
	for( int i = 0; i < 32; ++i ) {
		res <<= 1;
		res += bitArray[ i ] % 3;//��ȥ�ܱ�3�����Ĵ�����ʣ�µľ���ֻ����һ�ε�λ��
	}
	return res;
}

int main(int argc, char *argv[])
{
	int array[  ] = {
		2, 2, 2, 3
	};
	cout << findAppearingOneTime( array, 4 );
	return 0;
}