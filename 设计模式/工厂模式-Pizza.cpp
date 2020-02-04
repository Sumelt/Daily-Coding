/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/


#include <iostream>
#include <vector>
#include <string>
#include <cassert>
using namespace std;

class Pizza;
class Pizza_a;
class Pizza_b;
class Pizza_c;
/* 
//-----------------
class Pizza{
private:

public:
	void prepare();
	void bake();
	void cut();
	void box();
	 
};
//---------------披萨种类
class Pizza_a : public Pizza{
	
};

class Pizza_b : public Pizza{
	
};

class Pizza_c : public Pizza{
	
};

//创建工厂 
class SamplePizzaStore {
private:
	Pizza *m_pizza;
	
public:
	//简单工厂 
	~SamplePizzaStore() { delete m_pizza; }
	Pizza &creatPizza( const string &pizzaType ) {
		if( pizzaType == string( "A" ) ) //依据类型创建pizza 
			m_pizza = new Pizza_a();
		//else if 其他的披萨种类创建
		 
		return *m_pizza;
	}
};

class PizzaStore {
private:
	SamplePizzaStore *m_p_factory; //绑定的工厂 
	Pizza *m_pizza;
	
public:
	PizzaStore( SamplePizzaStore &factory ) : m_p_factory( &factory ){}
	~PizzaStore() { delete m_pizza; }
	Pizza &orderPizza( string &pizzaType ) {
		m_pizza = &m_p_factory->creatPizza( pizzaType ); //创建披萨交由工厂创建
		
		//披萨的一系列其他操作
		return *m_pizza;
	}
};

//-------------------
*/

//产品：披萨基类 
class Pizza{
private:
	string m_name;
public:
	Pizza( const string name ) : m_name( name ){}
	void prepare(){ cout << " prepare " << m_name << " operation "; }
	void bake() { cout << " bake operation ";}
	void cut() { cout << " cut operation "; }
	void box() { cout << " box operation "; }
	 
};
//不同风味的披萨 
class AStyleCheesePizza : public Pizza {
public:
	AStyleCheesePizza() : Pizza( "AStyleCheesePizza" ){}
};

class BStyleCheesePizza : public Pizza {
public:
	BStyleCheesePizza() : Pizza( "BStyleCheesePizza" ){}
};

//充当抽象基类的：披萨店 
class PizzaStore {
private:
	Pizza *m_pizza;
	
public:
	~PizzaStore() { delete m_pizza; }
	
	//create回到基类，具体的实现交由子类实现，延迟实例化 
	virtual Pizza &creatPizza( const string &pizzaType ) = 0; //纯虚函数：充当工厂接口 
	Pizza &orderPizza( const string &pizzaType ) {
		m_pizza = &creatPizza( pizzaType ); //
		
		//披萨的一系列其他操作
		return *m_pizza;
	}
};
//不同风味的披萨店 
class AStylePizzaStore : public	PizzaStore {
public:
	Pizza &creatPizza( const string &pizzaType ) {
		if( pizzaType == string( "CheesePizza" ) )
			return *new AStyleCheesePizza();
		//else if return //其他风味的披萨
	} 

};

class BStylePizzaStore : public	PizzaStore {
public:
	Pizza &creatPizza( const string &pizzaType ) {
		if( pizzaType == string( "CheesePizza" ) )
			return *new BStyleCheesePizza();
		//else if return //其他风味的披萨 
	}
};

int main(int argc, char *argv[])
{
	PizzaStore *aStore = new AStylePizzaStore( );
	Pizza* pizza = &aStore->orderPizza( "CheesePizza" );
	pizza->prepare();
	pizza->bake();
	
	delete aStore;
	
	return 0;
}