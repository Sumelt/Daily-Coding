/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <cassert>
#include <queue>
using namespace std;

template<typename T>
class solution {
private :
	queue<T>queOne;
	queue<T>queTwo;

public :
	void Push( const T& value ) {
		//保证一个队列为空， 另一个不为空 
		if( !queOne.empty() )
			queOne.push( value );
		else queTwo.push( value );
	}
	
	T Pop() {
		T res;
		int res;
		if( queOne.empty() && queTwo.empty() )
			throw( exception() );
		if( !queOne.empty() ) {
			size = queOne.size();
			if( size > 1 ) {
				while( size > 1 ) {
					queTwo.push( queOne.front() );
					queOne.pop();
					--size;
				}
			}
			res = queOne.front();
			queOne.pop();
		}
		else {
			size = queTwo.size();
			if( size > 1 ) {
				while( size > 1 ) {
					queOne.push( queTwo.front() );
					queTwo.pop();
					--size;
				}
			}
			res = queTwo.front();
			queTwo.pop();			
		}
		return res;
	}
};

int main(int argc, char *argv[])
{
	solution<int> oj;
//	oj.Push( 2 );
//	oj.Push( 3 );
//	cout << oj.Pop();//3
//	oj.Push( 4 );
//	oj.Push( 5 );
//	cout << oj.Pop();//5
//	cout << oj.Pop();//4
//	cout << oj.Pop();//2
	oj
	return 0;
}