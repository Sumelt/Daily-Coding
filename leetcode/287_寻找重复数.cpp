/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <cassert>
#include <map>
using namespace std;

/*
class Solution {
private:
	int calCount( vector<int>&nums, int begin, int end ) {
		if( nums.size() == 0 )
			return 0;
		int count = 0;
		for( auto value : nums )
			if( value >= begin && value <= end )
				++count;
		return count;
	}
public:
    int findDuplicate(vector<int>& nums) {
        if( nums.size() == 0 )
        	return -1;
       	
       	vector<int>array = nums;
       	int begin = 1, end = array.size() - 1;

       	while( begin <= end ) {
       		int mid = begin + ( ( end - begin ) >> 1 );	    	
			int count = calCount( array, begin, mid );
	    	if( begin == end && count > 1 )
	    		return begin;
    		else if( begin == end && count == 1 ) break;
    		if( count > ( end - begin + 1 ) )
    			end = mid;
   			else begin = mid;
    	}
       	return -1;
    }
};*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int, int>mp;
        for( int i = 0; i < nums.size(); ++i )
        	if( mp.insert( pair<int, int>( nums[ i ], 1 )).second == false )
        		return nums[ i ];
  		return 0;
    }
};

int main(int argc, char *argv[])
{
	
	return 0;
}