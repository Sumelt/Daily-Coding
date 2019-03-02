/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>

using namespace std;

int RangeCount( const int *numbers, int length, int start, int end )
{
	if( numbers == nullptr ) return 0;
	int count = 0;
	for( int i = 0; i < length; ++i )
	  	if( numbers[ i ] >= start && numbers[ i ] <= end )
	  		++count;
	return count;
}

int getDuplication( const int *numbers, int length ) 
{
	if( numbers == nullptr || length <= 1 )
		return -1;
	int start = 1; //����Ŀ�ʼ 
	int end = length - 1;	//����Ľ��� 
	while( end >= start )
	{
		int mid = (( end - start )>>1) + start; //����м��λ�� 
		int count = RangeCount( numbers, length, start, mid ); //ͳ�Ƹ������ڵ����ָ��� 
		if( end == start ) //������ֻ��һ��ֵ 
			if( count > 1 ) return start; //�������Ԫ�ظ����� 1 ���� һ�����ظ�Ԫ�� 
			else break;
		if( count > ( mid - start + 1 )) //�������Ԫ�ظ�������������� 
			end = mid; //�ظ�����һ���ڱ�������  ��С���� 
		else start = mid + 1; //����������һ������ ������� 
	}
	return -1;
}

int main(int argc, char *argv[])
{
	int array[] = { 2, 3, 5, 4, 2, 2, 6, 7 };
	cout << getDuplication( array, sizeof( array )/sizeof( *array ));
	return 0;
}




