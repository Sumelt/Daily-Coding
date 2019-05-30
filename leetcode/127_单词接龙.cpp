/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <cassert>
#include <cstring>
#include <queue>
using namespace std;

class Solution {
private:
	bool *visted = nullptr;
	bool in = false;
	bool cmpStr( int index, const string &str1, const string &str2 ) {
		int i = 0;
		bool res;
		if( str1.size() > 1 ) {
			for( ; i < str1.size(); ++i )
				if( str1[ i ] != str2[ i ] )
					break;
			if( i == str1.size() )
				return false;
			res = strcmp( str1.substr( i + 1, str1.size() - i ).c_str(), 
							str2.substr( i + 1, str2.size() - i ).c_str() );			
		}
		else{
			res = strcmp( str1.c_str(), str2.c_str() ) != 0 ? true : false; //相同返回假 
			visted[ i ] = ( res == false ? true : false );//为假返回真 
			in = ( res == false ? true : false );//为假说明存在 
			return res;
		}
		return res == false;
	}
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if( wordList.size() == 0 )
        	return -1;
        	
		vector<int>vec[ wordList.size() ];
		visted = new bool[ wordList.size() ]();
		
		//建立无向图 
		for( int i = 0; i < wordList.size(); ++i ) {
			for( int j = 0;  j < wordList.size(); ++j )
				if( cmpStr( i, wordList[ i ], wordList[ j ] ) )
					vec[ i ].push_back( j );
		}
		
		int i = 0;
		for( ; i < wordList.size(); ++i )
			if( cmpStr( i, beginWord, wordList[ i ] ) )
				break;
		if( i >= wordList.size() )
			return 0;

		//成功找到 第一个变换的字符串 
		visted[ i ] = true;
		queue<pair<int, int>>que;
		que.push( make_pair( i, 0 ) );
		pair<int, int>cp;
		
		//BFS
		while( !que.empty() ) {
			cp = que.front();
			que.pop();
			if( endWord == wordList[ cp.first ] )
				break;
			visted[ cp.first ] = true;
			for( int i = 0; i < vec[ cp.first ].size(); ++i )
				if( !visted[ vec[ cp.first ][ i ] ] )
					que.push( make_pair( vec[ cp.first ][ i ], cp.second + 1 ) );
		}
		
		if( que.empty() )
			return 0;
		if( in )
			return cp.second + 2;
		else return cp.second; 
    }
};

int main(int argc, char *argv[])
{
	Solution oj;
	vector<string>vec = {"hot","dot","dog","lot","log","cog"};
	cout << oj.ladderLength( "hit", "cog", vec );
	
	return 0;
}