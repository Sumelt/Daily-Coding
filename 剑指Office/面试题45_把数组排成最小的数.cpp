/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


class Solution {
private:
	string res;
    //类中的私有函数必须定义为静态或者放到类的外部，否则sort函数无法调用
	static bool cmp( int number1, int number2 ) {
		
		string str1 = to_string( number1 );
		string str2 = to_string( number2 );
		
		return ( str1 + str2 ) < ( str2 + str1 );//依据组合的大小进行排序
	}

public:
    string PrintMinNumber(vector<int> numbers) {
		if( numbers.size() == 0 )        
			return string();
		
		sort( numbers.begin(), numbers.end(), cmp );//使用定义的比较器
		for( int i = 0; i < numbers.size(); ++i )
			res += to_string( numbers[ i ] );
        
		return res;
    }
};

int main(int argc, char *argv[])
{
	Solution oj;
	cout << oj.PrintMinNumber( { 3, 32, 321 } );
	return 0;
}