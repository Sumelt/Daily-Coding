/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <map>
using namespace std;

class Solution {
private:
	class value{
		public:
			int _count = 0;//出现的次数
			int _index = 0;//位置
			value() : _count( 0 ), _index( 0 ){}
	};	
	map<char, value>mp;//哈希表
public:
    int FirstNotRepeatingChar(string str) {
        if( str.size() == 0 )
        	return -1;
       	for( int i = 0; i < str.size(); ++i ) {
		       	mp[ str[ i ] ]._count++;//累加出现的次数
		       	mp[ str[ i ] ]._index = i;//保存该位置
	       }
	
  		for( int i = 0; i < str.size(); ++i )
  			if( mp[ str[ i ] ]._count == 1 )
			  	return mp[ str[ i ] ]._index;//返回该位置				
		return -1;
    }
};
int main(int argc, char *argv[])
{
	Solution oj;
	cout << oj.FirstNotRepeatingChar( "google" );
	return 0;
}