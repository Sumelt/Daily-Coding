/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class State {
public:
	virtual void insertQuarter() = 0;
	virtual void ejecrQuarter() = 0;
	virtual void tumQuarter() = 0;
	virtual void dispense() = 0;
};

class HasQuarterState : public State {
	
};

class SoldState : public State {
	
};

......

int main(int argc, char *argv[])
{
	
	return 0;
}