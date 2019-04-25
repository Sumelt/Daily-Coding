#ifndef _OPENFILE_H
#define _OPENFILE_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

namespace opfile {
//取出第一个单词
int fistWoldIndex( const string &contents, int index ) {
	for( int i = index; i < contents.size(); ++i )
		if( isalpha( contents[ i ] ) )//找出第一个字母的下标 
			return i;
	return contents.length();
}


//把单词全部转换成小写
string toLowerS( const string &str ) {
	string ret = "";
	for( int i = 0; i < str.length(); ++i )
		ret += tolower( str[ i ] );
	return ret;
}


//单词分割

bool openfile( const string &filePath, vector<string>&words ){
		string line;
		string contents = "";
		ifstream file( filePath );//file和文件绑定 
		
		if( file.is_open() ) {//打开文件 
			while( getline( file, line ) )//从file中读取一行到line
				contents += ( line + '\n' );//读取一行后加上一个换行到contents 
			file.close(); //读取完全部内容后，文件关闭 
		}
		else {
			cout << "open file" << filePath << "faile"  << endl;
			return false;
		}
		
		int startWorldIndex = fistWoldIndex( contents, 0 );//第一个词已经是字母，下一次应该从下一个开始 
		for( int i = startWorldIndex + 1; i < contents.size(); ) {
			if( i == contents.length() || !isalpha( contents[ i ] ) ) {
				//压入一个单词 
				words.push_back( toLowerS( contents.substr( startWorldIndex, i - startWorldIndex ) ) );
				//找到下一个单词的第一个字母 
				startWorldIndex = fistWoldIndex( contents, i );
				i = startWorldIndex + 1;//上一个已经是字母，应该从下一个开始检索 
			}
			else ++i;				
		}
	}
 	
}


#endif