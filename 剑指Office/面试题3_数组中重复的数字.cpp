/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>

using namespace std;

// time: O(n) space: O(n)
bool duplicate2( int numbers[], int length, int *duplication )
{
	bool flag[ length ] = { 0 }; //����Ĺ�ϣ��ռ� 
	if( length <= 1 || numbers == nullptr ) //��Ҫ�ı߽��ж� 
		return false;
		
	for( int i = 0; i < length; ++i ) //ֻ�Ը�����Χ�ڵ����ֽ��в��� 
		if( numbers[ i ] < 0 || numbers[ i ] > length-1 )
			return false; //���ڷ�Χ֮�������ֱ�Ӳ����жϣ����뱣֤��Ч������
    
	for( int i = 0; i < length; ++i )
	{
		if( flag[ numbers[ i ]] ) {
			*duplication = numbers[ i ]; //���ݸ�����ָ�� ��������Խ��ж���Ĳ���
			return true; //�����ظ������� 
		} 			
		else flag[ numbers[ i ]] = true;
	}
	return false; //û���ظ�������
}

// time: O(n) space: O(1)
bool duplicate( int numbers[], int length, int *duplication )
{
	if( length <= 1 || numbers == nullptr )
		return false;
		
	for( int i = 0; i < length; ++i )
		if( numbers[ i ] < 0 || numbers[ i ] > length-1 )
			return false;
	for( int i = 0; i < length; ++i )
	{
		if( numbers[ i ] != i )  //��Ӧ���±������Ԫ��ֵ������ 
			if( numbers[ numbers[ i ]] != numbers[ i ] ) //�жϸ��±��Ԫ��ֵ��
			//����Ԫ��ֵ��Ϊ�±��ж��µ������ǲ��� �±��Ԫ�ش�Сһһ��Ӧ 
				swap( numbers[ i ], numbers[ numbers[ i ]] ); //�������������� ��������һ��Ԫ�ؽ�������ȷ���±� 
			else{
				*duplication = numbers[ i ]; //�������ҵ��ظ���Ԫ�� 
				return true;
			}		
	}
	return false;
}

int main(int argc, char *argv[])
{
	int array[] = { 0, 1, 3, 3 };
	int duplication = -1;
	cout << "Result : " 
		<< duplicate( array, sizeof( array )/sizeof( *array ), &duplication );

	return 0;
}




