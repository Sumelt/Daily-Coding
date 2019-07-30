/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

//class Solution {
//private:
//	vector<int>saveMaxWindows;
//	deque<int>saveMaxIndex;
//public:
//    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
//    {
//		if( num.size() == 0 || size == 0 || size > num.size() )
//			return vector<int>();
//		int i = 0;
//        //填满滑动窗口
//		for( ; i < size; ++i ) {
//			while( !saveMaxIndex.empty() && num[ i ] >= num[ saveMaxIndex.back() ] )
//				saveMaxIndex.pop_back();//若要插入元素比队列中的元素还大，弹出队列最后一个元素
//			saveMaxIndex.push_back( i );//压入此滑动窗口中最大元素的下标
//		}
// 		//滑动窗口       
//		for( i; i < num.size(); ++i ) {		
//			saveMaxWindows.push_back( num[ saveMaxIndex.front() ] );//保存此窗口的最大元素
//            //滑动窗口，判断新元素是否比队列中最后一个元素还大
//			while( !saveMaxIndex.empty() && num[ i ] >= num[ saveMaxIndex.back() ] )
//				saveMaxIndex.pop_back();
//            //判断首元素是否已经移出窗口
//			if( !saveMaxIndex.empty() && abs( saveMaxIndex.front() - i ) >= size )
//				saveMaxIndex.pop_front();				
//
//			saveMaxIndex.push_back( i );//压入元素的下标		
//		}
//		saveMaxWindows.push_back( num[ saveMaxIndex.front() ] );//保存此窗口的最大元素
//        
//		return saveMaxWindows;
//    }   
//};

class Solution {
private:
    deque<int>dque;
    vector<int>res;
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        if( num.size() == 0 || size == 0 || size > num.size() ) 
			return vector<int>();

        for( int index = 0; index < size; ++index ) {
            while( !dque.empty() && num[ dque.back() ] < num[ index ] )
                dque.pop_back();
            dque.push_back( index );
        }
        res.push_back( num[ dque.front() ] );
        
        for( int index = size; index < num.size(); ++index ) {
            if( index - dque.front() >= size  )
                dque.pop_front();
            while( !dque.empty() && num[ dque.back() ] < num[ index ] )
                dque.pop_back();
            dque.push_back( index );
            
            res.push_back( num[ dque.front() ] );
        }
        return res;
    }
};

int main(int argc, char *argv[])
{
	Solution oj;
	auto vec = oj.maxInWindows( { 2,3,4,2,6,2,5,1 }, 3 );
	
	for( auto value : vec )
		cout << value << ' ';
	
	return 0;
}