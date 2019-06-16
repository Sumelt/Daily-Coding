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

class Solution {
private:
	map<int, int>mp;
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if( nums1.size() == 0 || nums2.size() == 0 )
        	return vector<int>();
        	
       	vector<int>res;
       	
       	for( auto value : nums1 ) {
	    	if( mp.find( value ) == mp.end() )
	    		mp[ value ] = 1;
    		else mp[ value ] += 1;
    	}
       	for( auto value : nums2 ) {
	    	if( mp.find( value ) != mp.end() ) {
	    		res.push_back( value );
	    		mp[ value ] = mp[ value ] - 1;
	    		if( mp[ value ] == 0 )
	    			mp.erase( value );
	    	}
     	}
       	return res;
    }
};

int main(int argc, char *argv[])
{
	
	return 0;
}