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
		   while( smallPtr < (( 1+sum )/2) ) { //至少保证两个数				
   				if( addSum == sum )
				   	push( smallPtr, bigPtr );//相等则把区间元素压入容器，此时元素值不清零，而是在此基础上寻找下一组的连续区间元素
				while( addSum > sum && smallPtr < (( 1+sum )/2) ) {//这里十分巧妙，同时获得下一组的连续序列
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