/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
using namespace std;

class Solution {
private:
	void reverseCore( char *startPtr, char *endPtr ){
		--endPtr;
		while( startPtr < endPtr )
			swap( *startPtr++, *endPtr-- );				
	}
public:
    string LeftRotateString(string str, int n) {
        if( str.size() == 0 )
        	return string();
       	
       	reverseCore( &str[ 0 ], &str[ n ] );//��תǰn���ַ�
       	reverseCore( &str[ n ], &str.back() + 1 );//��תʣ�ಿ��
       	reverseCore( &str[ 0 ], &str[ str.size() ] );//�ٷ�ת��������
       	
       	return str;
    }
};
int main(int argc, char *argv[])
{
	string str( "hello" );
	cout << str.back();
	return 0;
}