/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

//����� 
class Beverage {
private:
	string m_description;
	 
public:
	Beverage( string description = "Unkown description" ) : 
		m_description ( description ){}
	virtual double cost() = 0; //���麯�����ṩ�ӿڣ����������ȫʵ�ֶ��� 
	virtual string getDescription() {
		return m_description;
	}	
};

//���ϱ�����
class Condiment : public Beverage {

public:
	virtual string getDescription() = 0;
}; 

//��д������
class Coffee_a : public Beverage {
public:
	Coffee_a() : Beverage( "coffee_a" ){}
	
	double cost() {
		return 2.00;
	}
};

class Coffee_b : public Beverage {
public:
	Coffee_b() : Beverage( "coffee_b" ){}
	
	double cost() {
		return 3.00;
	}	
};

class Coffee_c : public Beverage {
public:
	Coffee_c() : Beverage( "coffee_c" ){}
	
	double cost() {
		return 4.00;
	}	
};

//��д������ 
class Moka : public Condiment {
private:
	Beverage *m_p_beverage;
	
public:
	Moka( Beverage &beverage ) {
		this->m_p_beverage = &beverage;	
	}

	string getDescription() {
		return m_p_beverage->getDescription() + " MOKA ";
	}
	
	double cost() {
		return m_p_beverage->cost() + 2.00;	
	}
};

class Milk : public	Condiment {
private:
	Beverage *m_p_beverage;
	
public:
	Milk( Beverage &beverage ) {
		this->m_p_beverage = &beverage;
	}
	string getDescription() {
		return m_p_beverage->getDescription() + " MILK ";
	}
	
	double cost() {
		return m_p_beverage->cost() + 3.00; 
	}
};


int main(int argc, char *argv[])
{
	Beverage *coffeeb = new Coffee_b();
	coffeeb = new Moka( *coffeeb );
	coffeeb = new Milk( *coffeeb );
	cout << coffeeb->getDescription() << "cost: " << coffeeb->cost();
	delete coffeeb;
	return 0;
}