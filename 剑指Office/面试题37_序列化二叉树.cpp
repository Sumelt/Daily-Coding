/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <cstring>
using namespace std;


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
	//序列化
    void creathSerialize( TreeNode *root, string &str ) {
		if( root == nullptr ) {//空节点变成#
			str += '#';
			return;
		}			
		else{
			str += to_string( root->val );//数值可能是多位数的转成string类型
			str += ',';
		} 
		creathSerialize( root->left, str );
		creathSerialize( root->right, str );
	}		
    char* Serialize(TreeNode *root) {    
		if( root == nullptr )
			return nullptr;
		string str;//保存序列化后的string结果
		creathSerialize( root, str );
		char *charStr = new char[ str.size() + 1 ];	//创建动态的char数组
		strcpy( charStr, str.c_str() );//string到char内容的拷贝
		charStr[ str.size() ] = '\0';//char数组结束符是必须的
		
		return charStr;
    }
    //反序列化
    //这里的参数必须是指针类型的引用，每次递归指针都必须同时移动
    TreeNode* creathDeserialize(char *&str) {
    	if( str == nullptr || *str == '\0' )
    		return nullptr;
    	TreeNode *node = nullptr;
   		if( *str != '#' ) {
   			int number = 0;
			while( *str != ',' && *str != '\0' )//多位数的存在
				number = number * 10 + ( *str++ - '0' );//字符类型装整型
            if( *str == '\0' ) return nullptr; //跳出条件是结束符则返回
			node = new TreeNode( number );//创建一个节点空间
			node->left = creathDeserialize( ++str );
			node->right = creathDeserialize( ++str );
	   }
	   return node;
    }   
    TreeNode* Deserialize(char *str) {
    	return creathDeserialize( str );
    }
};

int main(int argc, char *argv[])
{
	
	return 0;
}