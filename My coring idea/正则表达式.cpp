/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <regex>

using namespace std;
int main(int argc, char *argv[])
{
	// 定义一个正则表达式 , 4~23 位数字和字母的组合
	regex repPattern("[0-9a-zA-Z]{4,23}",regex_constants::extended);
	// 声明匹配结果变量
	match_results<string::const_iterator> rerResult;
	// 定义待匹配的字符串
	string strValue = "123abc";
	// 进行匹配
	bool bValid = regex_match(strValue, rerResult, repPattern);
	if (bValid)
	{
	    printf("YES");
	}

	return 0;
}

