/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if( input.size() == 0 || k == 0 || k > input.size() )
        	return vector<int>();
       	set<int>savKnumber;//����K��Ԫ�ص�����
       	for( int i = 0; i < input.size(); ++i ) {
	    	if( savKnumber.size() != k )//�ȱ���K��Ԫ��
	    		savKnumber.insert( input[ i ] );
    		else if( input[ i ] < *savKnumber.rbegin() ) {//�Ƚ����Ԫ��
		    	savKnumber.erase( *savKnumber.rbegin() );//ɾ������Ԫ��
    			savKnumber.insert( input[ i ] );	//�����Ԫ��
		    }  			
    	}
        return vector<int>( savKnumber.begin(), savKnumber.end() );
    }
};
int main(int argc, char *argv[])
{
	
	return 0;
}