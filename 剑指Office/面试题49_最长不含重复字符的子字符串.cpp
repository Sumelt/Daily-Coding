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
	vector<char>MaxLengthString;//保存最长字符串容器
	map<char,int>mp;//哈希表
public:
	pair< vector<char>, int > findStringMaxLength( string str ) {
		if( str.size() == 0 )
			return pair< vector<char>, int >();        
		for( char i = 'a'; i <= 'z'; ++i )//哈希表初始化
			mp[ i ] = -1;
		int curLength = 0;	
		for( int index = 0; index < str.size(); ++index ) {
			//不重复字符或者是重复的字符出现在有效字符串的前面
            if( mp[ str[ index ] ] < 0 || index - mp[ str[ index ] ] > curLength ) {	
				++curLength;
				MaxLengthString.push_back( str[ index ] );//保存当前的字符
			}         
			else {//出现重复字符且出现在有效字符串的后面
				if( maxLength < curLength )//保存最大的字符串长度
					maxLength = curLength;
                //容器中的字符串长度小于当前字符串的长度才清空
				if( MaxLengthString.size() <= ( index - mp[ str[ index ] ] ) ) {
					MaxLengthString.clear();
					MaxLengthString.push_back( str[ index ] );//保存第一个字符
				}				
				curLength = 1;//当前长度变为1
			}
			mp[ str[ index ] ] = index;//保存词字符出现的下标
		}
		if( maxLength < curLength )
			maxLength = curLength;
		return pair< vector<char>, int >( MaxLengthString, maxLength );//返回关联容器
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