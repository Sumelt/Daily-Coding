/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <forward_list>
using namespace std;

class Solution {
private:
	vector<int>nowres;	
	vector<vector<int> >res;
public:
    void push( int small, int big ){
    	for( int i = small; i <= big; ++i )
    		nowres.push_back( i );
   		res.push_back( nowres );
   		nowres.clear();
    }
	vector<vector<int> > FindContinuousSequence(int sum) {
        if( sum == 0 )
        	return vector<vector<int>>();   	
       		int smallPtr = 1;
       		int bigPtr = 2;
       		int addSum = 0;
       		addSum += smallPtr + bigPtr;
		   while( smallPtr < (( 1+sum )/2) ) { //���ٱ�֤������				
   				if( addSum == sum )
				   	push( smallPtr, bigPtr );//����������Ԫ��ѹ����������ʱԪ��ֵ�����㣬�����ڴ˻�����Ѱ����һ�����������Ԫ��
				while( addSum > sum && smallPtr < (( 1+sum )/2) ) {//����ʮ�����ͬʱ�����һ�����������
					addSum -= smallPtr;
					++smallPtr;					
 					if( addSum == sum )
				   		push( smallPtr, bigPtr );									
				}
				++bigPtr;
				addSum += bigPtr;
			}
		return res;     	
    }
};
int main(int argc, char *argv[])
{
	Solution oj;
	auto res = oj.FindContinuousSequence( 3 );
	for( auto vec : res )
		for( auto value : vec  )
			cout << value <<' ';
	return 0;
}