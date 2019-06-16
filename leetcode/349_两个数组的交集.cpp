/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <cassert>
#include <set>
using namespace std;

class Solution {
private:
	set<int>Set;
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		if( nums1.size() == 0 || nums2.size() == 0 )
			return vector<int>();
		vector<int>res;
		
		for( auto value : nums1 )
			Set.insert( value );
		for( auto value : nums2 )
			if( Set.find( value ) != Set.end() ) {
				res.push_back( value );
				Set.erase( value );
			}
				
		return res;		
    }
};

int main(int argc, char *argv[])
{
	
	return 0;
}