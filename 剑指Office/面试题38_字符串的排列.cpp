/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	vector<string>res;
public:
	void arrangement( char head, string str, string complete )
	{
		if( head != '\0' )
			complete += head;		
		if( str.size() == 1 ) {//区间只剩一个字符则表明 一个排列已经完成了
			complete += str;
			res.push_back( complete );//保存排好的序列
			return;
		}
		for( int i = 0; i < str.size(); ++i ) {
        	if( str[ 0 ] != str[ i ] )//头和后序的字符不相等彼此交换
				swap( str[ 0 ], str[ i ] );
			else if( i != 0 ) continue;	//在第一次循环下，头和后序的字符相等也要做一次全排列&&去重
			arrangement( str[ 0 ], string( str, 1, str.size() - 1 ), complete );
            //选择头 头后续的区间 前面排好的一部分序列
		}		
	}
    vector<string> Permutation(string str) {
        if( str.size() == 0 )
        	return vector<string>();
        if(  str.size() == 1) { //只有一位字符直接返回
			res.push_back( str );
        	return res;
        }            
		arrangement( '\0', str, string() );//全排列
        return res;        
    }
};

//STL next_permutation
vector<string> Permutation(string str) {
    if( str.size() == 0 )
    	return vector<string>();
	vector<string>res;
	sort( str.begin(), str.end() );
	do{
		res.push_back( str );
	}
	while( next_permutation( str.begin(), str.end() ) );
}

int main(int argc, char *argv[])
{
	Solution oj;
	oj.Permutation( "ab" );
	for( auto value : oj.res )
		cout << value << endl;
	return 0;
}