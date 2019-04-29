/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
	vector<string> res;
	const string map[ 10 ] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", 
		"tuv", "wxyz",};
	void combination( string &str, int index, string combStr ) {
		
		if( combStr.size() == str.size() ) { //匹配满足要求了 
			res.push_back( combStr );
			return;
		}
			
		char c = str[ index ];
		string transStr = map[ c - '0' ];
		for( int i = 0; i < transStr.size(); ++i ) {
			combination( str, index + 1, combStr + transStr[ i ] ); 
			// 输入数字串  下一个数字  当前数字的对应字符串的每一个和下一个数字对应的字符串中的每一个字符匹配 
		}
		return;
	}
	
public:
    vector<string> letterCombinations(string digits) {
        if( digits.size() == 0 ) return vector<string>();
		combination( digits, 0, "" );
		return res;
    }
};

int main(int argc, char *argv[])
{
	Solution so;
	vector<string> str = so.letterCombinations("");
	for( auto value : str )
		cout << value << ' ';
	return 0;
}