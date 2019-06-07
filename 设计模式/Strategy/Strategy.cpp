/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class TaxStrategy {
	virtual double Calculate( const Context& context ) = 0;
	virtual ~TaxStrategy() = default;
};

class ChinaTax : public TaxStrategy {
	virtual double Calculate( const Context& context ) {
		
	}
}; 


class SaleOrder{
private:
	TaxStrategy *strategy;
public:
	//由工厂模式返回一个对象 
	SaleOrder( StrategyFactory* strategyFactory ) {
		this->strategy = strategyFactory->newStrategy(); //产生一个相应的对象 
	}
	~SaleOrder {
		delete strategy;
	}
	double Calculate() {
		double val = strategy->Calculate( context );//调用对象相应的计算 
	}
};

int main(int argc, char *argv[])
{
	
	return 0;
}