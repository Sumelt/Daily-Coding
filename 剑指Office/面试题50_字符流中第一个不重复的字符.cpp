/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <algorithm>
using namespace std;

class Solution
{
private:
	vector<char>vec; //保存字符流中的字符容器
	map<char, int>mp;//哈希表
public:
  //Insert one char from stringstream
    void Insert(char ch){
       	if( ch == '\0' )
   			return;
		vec.push_back( ch );
		if( mp[ ch ] == 0 )			
			mp[ ch ] = 1;
		else mp[ ch ] = INT_MIN;//多次出现
		
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce(){
    	for( auto value : vec )//遍历数组
    		if( mp[ value ] == 1 )//出现次数为1则是我们的目标
    			return value;
		return '#';//否则返回#
	}
};

int main(int argc, char *argv[])
{
	
	return 0;
}