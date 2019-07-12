/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

/*
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        bool *array = new bool[ nums.size() + 1 ]();
        for( int i = 0; i < nums.size(); ++i )
            array[nums[ i ] ] = true;
        for( int i = 0; i <= nums.size(); ++i  )
            if( !array[ i ] ) {
                res = i;
                break;
            }
        delete []array;
        return res;
    }
};*/

/*
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
		int length = nums.size();
        for( int i = 0; i < length; ++i )
        	res ^= nums[ i ] ^ i;
       	return ( res ^ length );
    }
};*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int lenght = nums.size();
		int sum = ( lenght * ( lenght + 1 ) ) / 2;
		int add = 0;
		for( auto value : nums )
			add += value;
		return sum - add;
    }
};

int main(int argc, char *argv[])
{
	
	return 0;
}