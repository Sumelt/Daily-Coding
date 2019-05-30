/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>tempVec;
        if( m == 0 ) {
            nums1 = nums2;
            return ;
        }
        if( n == 0 )  return ;
        
        int index1, index2;
        index1 = index2 = 0;
        while( index1 < m && index2 < n ) {
            if( nums1[ index1 ] < nums2[ index2 ] )
                tempVec.push_back( nums1[ index1++ ] );
            else tempVec.push_back( nums2[ index2++ ] );
        }
       
        while( index1 < m )
            tempVec.push_back( nums1[ index1++ ] );
        
        while( index2 < n )
            tempVec.push_back( nums2[ index2++ ] );
        
        nums1 = tempVec;
    }
};

int main(int argc, char *argv[])
{
	
	return 0;
}