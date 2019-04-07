/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
using namespace std;

//class solution

class Calculation{
		friend class Solution;
	public:	
		Calculation(){ ++number; res += number; }
		static void reSet(){ number = 0; res = 0; }//初始化静态成员 
	private:			
		static int number;
		static int res;	
};
int Calculation::number = 0;
int Calculation::res = 0;

class Solution {
public:
    int Sum_Solution(int n) {
		Calculation::reSet();			
		Calculation *returnRes = new Calculation[ n ];
		delete []returnRes;		
		return Calculation::res;
    }
};

//Polymorphism
class father;
father *array[ 2 ];

class father {
public:
	virtual cal( int n ) {
		return 0;
	}
};

class kid : public father {
public:
	virtual cal( int n ) {
		return n + array[ !!n ]->cal( n - 1 );
	}
};

class Solution2 {
public:
    int Sum_Solution(int n) {
		
		class father parents;
		class kid child;
		
		array[ 0 ] = &parents;
		array[ 1 ] = &child;
		
		return array[ 1 ]->cal( n );
    }
};

//function ptr ( exist bug )
/*
using funcPtr = int(*)( int );

class Solution3 {
public:
    int termination( int n ) {
		return 0;
	}
	int Sum_Solution(int n) {
		funcPtr array[ 2 ] = { termination, Sum_Solution };
		return array[ !!n ]( n - 1 ) + n; 
    }
};
*/
int main(int argc, char *argv[])
{
	Solution2 oj;
	cout << oj.Sum_Solution( 5 );
	return 0;
}