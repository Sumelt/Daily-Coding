/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <deque>
#include <exception>
using namespace std;



class Solution {
private:
	struct data{ //数值结构
		int value;
		int index;
		data( int _value, int _index ) : 
			value( _value ), index( _index ){}
	};
	deque<data>que;//保存每一个元素的队列
	deque<data>saveMaxData;//保存最大的元素队列
	int curIndex = 0;
	
public:
	//返回最大元素
    data max() {
		if( !que.empty() )
			return saveMaxData.front();
		else throw new exception();  
	}
    //压入操作
	void push_back( const int number ) {
        //保证插入的元素比队列尾元素大
		while( !saveMaxData.empty() && number >= saveMaxData.back().value )
			saveMaxData.pop_back();
        //插入新元素
		data temp = data( number, curIndex++ );
		que.push_back( temp );
		saveMaxData.push_back( temp );
	}	
    //弹出操作
	void pop_front() {
		if( !que.empty() ) {
			if( que.front().index == saveMaxData.front().index )//要弹出的是最大值
				saveMaxData.pop_front();
			que.pop_front();
		}
		else throw new exception(); 
	}

};

int main(int argc, char *argv[])
{
	
	return 0;
}