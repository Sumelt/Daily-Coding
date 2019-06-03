/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include "../random_number.h"
using namespace std;

namespace Binary_search {
template <typename T>
int Binarysearch( T *ary, int size, T target) {
	
	int leftIndex = 0, rightIndex = size - 1;
	while( leftIndex <= rightIndex ) {
		
		int midIndex = leftIndex + ( ( rightIndex - leftIndex ) >> 1 );//������� 
		if( target == ary[ midIndex ] )
			return midIndex;
		if( target > ary[ midIndex ] )
			leftIndex = midIndex + 1;
		else rightIndex = midIndex - 1;
	}
	return -1;
}

// ���ֲ��ҷ�, ����������arr��, ����target
// ����ҵ�target, ���ص�һ��target��Ӧ������index
// ���û���ҵ�target, ���ر�targetС�����ֵ��Ӧ������, ���������ֵ�ж��, �����������
// ������target�������������СԪ��ֵ��ҪС, �򲻴������target��floorֵ, ����-1
template<typename T>
int floor(T arr[], int n, T target){

    assert( n >= 0 );

    // Ѱ�ұ�targetС���������
    int l = -1, r = n-1;
    while( l < r ){
        // ʹ������ȡ��������ѭ��
        int mid = l + (r-l+1)/2;
        cout << "floor: mid: " << mid << ' ' << l << ' ' << r << endl;
        if( arr[mid] >= target )//���ڵ�Ŀ��ֵʱ 
            r = mid - 1; //��Сβ�� 
        else
            l = mid;
    }

    assert( l == r );

    // ���������+1����target����, ������+1��Ϊ����ֵ
    if( l + 1 < n && arr[l+1] == target )
        return l + 1;

    // ����, ��������Ϊ����ֵ
    return l;
}


// ���ֲ��ҷ�, ����������arr��, ����target
// ����ҵ�target, �������һ��target��Ӧ������index
// ���û���ҵ�target, ���ر�target�����Сֵ��Ӧ������, ��������Сֵ�ж��, ������С������
// ������target��������������Ԫ��ֵ��Ҫ��, �򲻴������target��ceilֵ, ������������Ԫ�ظ���n
template<typename T>
int ceil(T arr[], int n, T target){

	    assert( n >= 0 );
	
	    // Ѱ�ұ�target�����С����ֵ
	    int l = 0, r = n;
	    while( l < r ){
	        // ʹ����ͨ������ȡ�����ɱ�����ѭ��
	        int mid = l + (r-l)/2;
	        //cout << "" 
	        if( arr[mid] <= target )
	            l = mid + 1;
	        else // arr[mid] > target
	            r = mid;
	    }
	
	    assert( l == r );
	
	    // ���������-1����target����, ������+1��Ϊ����ֵ
	    if( r - 1 >= 0 && arr[r-1] == target )
	        return r-1;
	
	    // ����, ��������Ϊ����ֵ
	    return r;
	}
}

int main(int argc, char *argv[])
{
	int length = 20;
	int *ary = Generate_random_numbers( 20, 90, length );
	sort( ary, ary + length );
	
	for( int i = 0; i < length; ++i )
		cout << ary[ i ] << ends;
	cout << endl;
	cout << endl << Binary_search::floor( ary, length, 23 );
	
	return 0;
}