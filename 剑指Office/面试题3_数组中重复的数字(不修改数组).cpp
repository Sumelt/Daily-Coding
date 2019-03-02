/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>

using namespace std;

int RangeCount( const int *numbers, int length, int start, int end )
{
	if( numbers == nullptr ) return 0;
	int count = 0;
	for( int i = 0; i < length; ++i )
	  	if( numbers[ i ] >= start && numbers[ i ] <= end )
	  		++count;
	return count;
}

int getDuplication( const int *numbers, int length ) 
{
	if( numbers == nullptr || length <= 1 )
		return -1;
	int start = 1; //区间的开始 
	int end = length - 1;	//区间的结束 
	while( end >= start )
	{
		int mid = (( end - start )>>1) + start; //获得中间的位置 
		int count = RangeCount( numbers, length, start, mid ); //统计该区间内的数字个数 
		if( end == start ) //区间内只有一个值 
			if( count > 1 ) return start; //该区间的元素个数比 1 还大 一定是重复元素 
			else break;
		if( count > ( mid - start + 1 )) //该区间的元素个数大于区间个数 
			end = mid; //重复数字一定在本区间内  缩小区间 
		else start = mid + 1; //否则在另外一个区间 这里存在 
	}
	return -1;
}

int main(int argc, char *argv[])
{
	int array[] = { 2, 3, 5, 4, 2, 2, 6, 7 };
	cout << getDuplication( array, sizeof( array )/sizeof( *array ));
	return 0;
}




