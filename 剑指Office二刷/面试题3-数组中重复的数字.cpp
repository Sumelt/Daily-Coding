/*----------------------------------------------------------------

* @Author: Su

* @Description: 
在一个长度为n的数组里的所有数字都在0到n-1的范围内
请找出数组中任意一个重复的数字。 
例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字2

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        if( numbers == nullptr || length <= 0 )
        	return false;
       	for( int i = 0; i < length; ++i )
       		if( numbers[ i ] < 0 || numbers[ i ] >= length ) 
			   	return false;
  		for( int index = 0; index < length; ++index )
  			while( numbers[ index ] != index ) {
				if( numbers[ numbers[ index ] ] == numbers[ index ] ) {
					*duplication++ = numbers[ index ];
					return true; //存在重复返回真				
				}
				else swap( numbers[ index ], numbers[ numbers[ index ] ] );
		  	}
   		return false;//不存在重复返回假 
    }
};

int main(int argc, char *argv[])
{
		int array[] = { 0, 1, 2 };
	int duplication = -1;
	cout << "Result : " 
		<< duplicate( array, sizeof( array )/sizeof( *array ), &duplication );
	return 0;
}