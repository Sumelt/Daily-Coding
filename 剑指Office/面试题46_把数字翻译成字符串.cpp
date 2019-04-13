/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
using namespace std;

class Solution{
private:
	int _count = 0;
    //1 2258
    //1 2 258
    //1 2 2 58
    //1 2 2 5 8	+1
    //1 2 2 58
    //1 2 25 8	+1
    //1 22 58	+1
	void calCoreOne( string strPartOne, string strPartTwo ) {
		//��һ���ֳ���Ϊ1
		if( strPartOne.size() == 1 && strPartTwo.size() == 1 ) {			
			++_count;
			return;
		}
        //��һ���ֳ���Ϊ2
		if( strPartOne.size() == 2 ) {
			if( stoi( strPartOne ) >= 10 && stoi( strPartOne ) <= 25 )
				++_count;
			return;
		} 			
		calCoreOne( string( strPartTwo.begin(), strPartTwo.begin() + 1 ), 
				string( strPartTwo.begin() + 1, strPartTwo.end() ) );
		calCoreOne( string( strPartTwo.begin(), strPartTwo.begin() + 2 ), 
				string( strPartTwo.begin() + 2, strPartTwo.end() ) );
	}
    //12 258 +1
    //12 25 8 +1
	void calCoreTwo( string strPartOne, string strPartTwo ) {
        //��һ���ֳ���Ϊ2
		if( strPartOne.size() == 2 ) {
			if( stoi( strPartOne ) >= 10 && stoi( strPartOne ) <= 25 )
				++_count;
			if( strPartTwo.size() <= 1 )//�ڶ����ֲ�����ݹ���
				return;
		}
		calCoreTwo( string( strPartTwo.begin(), strPartTwo.begin() + 2 ), 
				string( strPartTwo.begin() + 2, strPartTwo.end() ) ); 
	}
	int calCount( int number ) {
		string str = to_string( number );//������ת���ַ���
        //ֻ�����һ����Ϊ1�����ȵ��ַ������ڶ�����Ϊʣ���ַ���
		calCoreOne( string( str.begin(), str.begin() + 1 ), 
			string( str.begin() + 1, str.end() ) );
        //ֻ�����һ����Ϊ2�����ȵ��ַ������ڶ�����Ϊʣ���ַ���
		calCoreTwo( string( str.begin(), str.begin() + 2 ), 
			string( str.begin() + 2, str.end() ) );
		return _count;
	}
public:
	int calTranslation( int number ) {
		if( number < 0 )
			return 0;
		return calCount( number );
	}
};

class Solution2{
private:
    int _count;
    int calCount( int number ){
		
		string str = to_string( number );//ת���ַ���
		int *array = new int[ str.size() ]();//����ȳ��Ķ�̬����
		for( int index = str.size() - 1; index >= 0; --index ) {//�����һ��Ԫ�ؿ�ʼ
			if( index < str.size() - 1 )//�����һ��Ԫ��
				array[ index ] = array[ index + 1 ];//�������ַ����Ҫ����֮���ַ�����Ļ�����
			else array[ index ] = 1;//���һ��Ԫ��
			
			if( index < str.size() - 1 ) {//��֤���ʵ�Ԫ���Ѿ�����1
				
				if( stoi( string( str, index, 2 ) ) >= 10 && //�ж��Ƿ����㷭������
						stoi( string( str, index, 2 ) )<= 25 )
					if( index < str.size() - 2 )//���ʵ�Ԫ�ظ����Ѿ�����2
						array[ index ] += array[ index + 2 ];//��λ��������ͬʱҲҪ����index + 2�Ľ��
					else ++array[ index ];//�Ѿ����ʵ�Ԫ�ظ����պ���2��Ԫ��
			}
		}
		_count = array[ 0 ];
		delete []array;
		return _count;
	}
public:
	int calTranslation( int number ) {
		if( number < 0 )
			return 0;
		return calCount( number );
	}	
};


int main(int argc, char *argv[])
{
	Solution2 oj;
	cout << oj.calTranslation( 12258 );
	return 0;
}