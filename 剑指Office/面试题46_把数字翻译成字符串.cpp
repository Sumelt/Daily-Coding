/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
using namespace std;

class Solution{
private:
	int _count = 0;
    //1 2258
    //1 2 258
    //1 2 2 58
    //1 2 2 5 8	+1
    //1 2 2 58
    //1 2 25 8	+1
    //1 22 58	+1
	void calCoreOne( string strPartOne, string strPartTwo ) {
		//第一部分长度为1
		if( strPartOne.size() == 1 && strPartTwo.size() == 1 ) {			
			++_count;
			return;
		}
        //第一部分长度为2
		if( strPartOne.size() == 2 ) {
			if( stoi( strPartOne ) >= 10 && stoi( strPartOne ) <= 25 )
				++_count;
			return;
		} 			
		calCoreOne( string( strPartTwo.begin(), strPartTwo.begin() + 1 ), 
				string( strPartTwo.begin() + 1, strPartTwo.end() ) );
		calCoreOne( string( strPartTwo.begin(), strPartTwo.begin() + 2 ), 
				string( strPartTwo.begin() + 2, strPartTwo.end() ) );
	}
    //12 258 +1
    //12 25 8 +1
	void calCoreTwo( string strPartOne, string strPartTwo ) {
        //第一部分长度为2
		if( strPartOne.size() == 2 ) {
			if( stoi( strPartOne ) >= 10 && stoi( strPartOne ) <= 25 )
				++_count;
			if( strPartTwo.size() <= 1 )//第二部分不满足递归了
				return;
		}
		calCoreTwo( string( strPartTwo.begin(), strPartTwo.begin() + 2 ), 
				string( strPartTwo.begin() + 2, strPartTwo.end() ) ); 
	}
	int calCount( int number ) {
		string str = to_string( number );//把数字转成字符串
        //只计算第一部分为1个长度的字符串，第二部分为剩下字符串
		calCoreOne( string( str.begin(), str.begin() + 1 ), 
			string( str.begin() + 1, str.end() ) );
        //只计算第一部分为2个长度的字符串，第二部分为剩下字符串
		calCoreTwo( string( str.begin(), str.begin() + 2 ), 
			string( str.begin() + 2, str.end() ) );
		return _count;
	}
public:
	int calTranslation( int number ) {
		if( number < 0 )
			return 0;
		return calCount( number );
	}
};

class Solution2{
private:
    int _count;
    int calCount( int number ){
		
		string str = to_string( number );//转成字符串
		int *array = new int[ str.size() ]();//分配等长的动态数组
		for( int index = str.size() - 1; index >= 0; --index ) {//从最后一个元素开始
			if( index < str.size() - 1 )//非最后一个元素
				array[ index ] = array[ index + 1 ];//考虑新字符结果要在它之后字符结果的基础上
			else array[ index ] = 1;//最后一个元素
			
			if( index < str.size() - 1 ) {//保证访问的元素已经大于1
				
				if( stoi( string( str, index, 2 ) ) >= 10 && //判断是否满足翻译条件
						stoi( string( str, index, 2 ) )<= 25 )
					if( index < str.size() - 2 )//访问的元素个数已经大于2
						array[ index ] += array[ index + 2 ];//两位符合条件同时也要加上index + 2的结果
					else ++array[ index ];//已经访问的元素个数刚好是2个元素
			}
		}
		_count = array[ 0 ];
		delete []array;
		return _count;
	}
public:
	int calTranslation( int number ) {
		if( number < 0 )
			return 0;
		return calCount( number );
	}	
};


int main(int argc, char *argv[])
{
	Solution2 oj;
	cout << oj.calTranslation( 12258 );
	return 0;
}