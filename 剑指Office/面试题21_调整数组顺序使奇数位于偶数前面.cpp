/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//void reOrderArray(vector<int> &array) {
//    if( array.size() == 0 )
//        return;
//    int *ary = new int[ array.size() ];
//    int addCount = 0; int addBeginIndex = 0;
//    for( int i = 0; i < array.size(); ++i )
//        if( array[ i ] & 0x1 == 1 ) ++addCount; //计算奇数的个数
//    for( int i = 0; i < array.size(); ++i )
//        if( array[ i ] & 0x1 == 1 ) 
//            ary[ addBeginIndex++ ] = array[ i ]; //给新的数组赋值
//    	else ary[ addCount++ ] = array[ i ]; //保证新数组中偶数在奇数之后
//  	for( int i = 0; i < array.size(); ++i )
//        array[ i ] = ary[ i ]; //重新导入旧数组
//  	delete []ary;
//}



//class Solution{
//	public:
//    void reOrderArray(vector<int> &array){
//        stable_partition( array.begin(), array.end(),
//			 []( const int a ){ return ( (a & 0x1) == 1 ); } ); 
//    }
//};



class Solution{
public:
	static bool isOk(int n){ return ( (n & 1) == 1 ); } 
    void reOrderArray(vector<int> &array){
        stable_partition( array.begin(), array.end(), isOk ); 
    }
};


int main(int argc, char *argv[])
{
	vector<int>ary = {
		2,3,4,7,1,9
	};
	//Solution so;
//	so.reOrderArray( ary );
//	for( auto value : ary )
//		cout << value <<" ";
	return 0;
}