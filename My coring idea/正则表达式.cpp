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
	// ����һ��������ʽ , 4~23 λ���ֺ���ĸ�����
	regex repPattern("[0-9a-zA-Z]{4,23}",regex_constants::extended);
	// ����ƥ��������
	match_results<string::const_iterator> rerResult;
	// �����ƥ����ַ���
	string strValue = "123abc";
	// ����ƥ��
	bool bValid = regex_match(strValue, rerResult, repPattern);
	if (bValid)
	{
	    printf("YES");
	}

	return 0;
}

