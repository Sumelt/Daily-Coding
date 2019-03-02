/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>

using namespace std;

// time: O(n) space: O(n)
bool duplicate2( int numbers[], int length, int *duplication )
{
	bool flag[ length ] = { 0 }; //额外的哈希表空间 
	if( length <= 1 || numbers == nullptr ) //必要的边界判断 
		return false;
		
	for( int i = 0; i < length; ++i ) //只对给定范围内的数字进行操作 
		if( numbers[ i ] < 0 || numbers[ i ] > length-1 )
			return false; //存在范围之外的数字直接不做判断，必须保证有效的输入
    
	for( int i = 0; i < length; ++i )
	{
		if( flag[ numbers[ i ]] ) {
			*duplication = numbers[ i ]; //传递给整型指针 ，这里可以进行额外的操作
			return true; //存在重复的数字 
		} 			
		else flag[ numbers[ i ]] = true;
	}
	return false; //没有重复的数字
}

// time: O(n) space: O(1)
bool duplicate( int numbers[], int length, int *duplication )
{
	if( length <= 1 || numbers == nullptr )
		return false;
		
	for( int i = 0; i < length; ++i )
		if( numbers[ i ] < 0 || numbers[ i ] > length-1 )
			return false;
	for( int i = 0; i < length; ++i )
	{
		if( numbers[ i ] != i )  //对应的下标和它的元素值不符合 
			if( numbers[ numbers[ i ]] != numbers[ i ] ) //判断该下标的元素值，
			//并把元素值作为下标判断新的数组是不是 下标和元素大小一一对应 
				swap( numbers[ i ], numbers[ numbers[ i ]] ); //不是则两两交换 ，把其中一个元素交换到正确的下标 
			else{
				*duplication = numbers[ i ]; //若是则找到重复的元素 
				return true;
			}		
	}
	return false;
}

int main(int argc, char *argv[])
{
	int array[] = { 0, 1, 3, 3 };
	int duplication = -1;
	cout << "Result : " 
		<< duplicate( array, sizeof( array )/sizeof( *array ), &duplication );

	return 0;
}




