/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution{
private:
	int maxLength = 0;
	vector<char>MaxLengthString;//������ַ�������
	map<char,int>mp;//��ϣ��
public:
	pair< vector<char>, int > findStringMaxLength( string str ) {
		if( str.size() == 0 )
			return pair< vector<char>, int >();        
		for( char i = 'a'; i <= 'z'; ++i )//��ϣ���ʼ��
			mp[ i ] = -1;
		int curLength = 0;	
		for( int index = 0; index < str.size(); ++index ) {
			//���ظ��ַ��������ظ����ַ���������Ч�ַ�����ǰ��
            if( mp[ str[ index ] ] < 0 || index - mp[ str[ index ] ] > curLength ) {	
				++curLength;
				MaxLengthString.push_back( str[ index ] );//���浱ǰ���ַ�
			}         
			else {//�����ظ��ַ��ҳ�������Ч�ַ����ĺ���
				if( maxLength < curLength )//���������ַ�������
					maxLength = curLength;
                //�����е��ַ�������С�ڵ�ǰ�ַ����ĳ��Ȳ����
				if( MaxLengthString.size() <= ( index - mp[ str[ index ] ] ) ) {
					MaxLengthString.clear();
					MaxLengthString.push_back( str[ index ] );//�����һ���ַ�
				}				
				curLength = 1;//��ǰ���ȱ�Ϊ1
			}
			mp[ str[ index ] ] = index;//������ַ����ֵ��±�
		}
		if( maxLength < curLength )
			maxLength = curLength;
		return pair< vector<char>, int >( MaxLengthString, maxLength );//���ع�������
	}	
};

int main(int argc, char *argv[])
{
	Solution oj;
	//cout << oj.findStringMaxLength("arabcacfr");
	auto form = oj.findStringMaxLength("arabcacfr");
	for( auto value : form.first )
		cout << value;
	cout << ' ' << form.second;
	return 0;
}