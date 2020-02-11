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

//菜单组件:包括菜单和菜单项 
class MenuComponent {
public:
	virtual void add( MenuComponent *component ) {}
	virtual void remove( MenuComponent *component ) {}
	virtual MenuComponent* getChild( int i ) { return nullptr; }
	virtual string getName() { return string(); }
	virtual string getDescription() { return string(); }
	virtual double getPrice() { return .0; }
	virtual bool isVegetarian() { return false; }
	virtual void print() {}
};

//菜单
class Menu : public MenuComponent {
private:
	string m_name; //菜单的名称 
	string m_description; //菜单的解析 
	vector<MenuComponent*>m_arrayList;	
public:
	Menu( const string &name, const string &description ) {
		m_name = name;
		m_description = description;
	}
	void add( MenuComponent *component ) {
		m_arrayList.push_back( component );
	}
	void remove( MenuComponent *component ) {
		for( auto iter = m_arrayList.begin(); iter != m_arrayList.end(); ++iter ) {
			if( *iter == component ) {
				*iter = *( m_arrayList.end() - 1 );	
				m_arrayList.pop_back();
				break;
			}
		}
	}
	MenuComponent* getChild( int i ) {
		return m_arrayList[ i ];
	}
	string getName() {
		return m_name;
	}
	string getDescription() {
		return m_description;
	}
	void print() {
		cout << "menu: " << m_name << " " << m_description << endl;
		cout << "---------------------" << endl;
		auto iter = m_arrayList.begin();
		while( iter != m_arrayList.end() ) {
			( *iter )->print(); //递归 
			++iter;
		}
	}
};

//菜单项 
class MenuItem : public	MenuComponent {
private:
	string m_name;//菜的名称 
	string m_description;//菜的描述 
	bool m_vegetarian;
	double m_price;
	 
public:
	MenuItem( const string &name, const string &description, bool vegetarian, double price ) {
		this->m_name = name;
		this->m_description = description;
		this->m_vegetarian = vegetarian;
		this->m_price = price;
	}
	MenuItem() = default;
	
	string getName() {
		return m_name;
	}
	
	string getDescription() {
		return m_description;
	}
	
	double getPrice() {
		return m_price;
	}
	
	bool isVegetarian() {
		return m_vegetarian;
	}
	void print() {
		cout << "menuitem: " << getName() << ' ' 
			<< getDescription() << ' ' << getPrice() << endl;
	} 
};

class Waitress {
private:
	MenuComponent *m_rootmenu;
	
public:
	Waitress( MenuComponent* rootmenu ) : m_rootmenu( rootmenu ) {}
	void print() {
		m_rootmenu->print();//开始从头向下遍历 
	}
};


int main(int argc, char *argv[])
{
	MenuComponent *MenuA = new Menu( "menuA", "about A" );
	MenuComponent *MenuB = new Menu( "menuB", "about B" );
	MenuComponent *MenuCToA = new Menu( "menuC", "about C to A" );
	
	MenuComponent *rootMenu = new Menu( "mentRoot", "about root" ); //根菜单 
	//根菜单加菜谱
	rootMenu->add( MenuA ); 
	rootMenu->add( MenuB );
	MenuA->add( MenuCToA );
	
	//菜谱加菜名 
	MenuA->add( new MenuItem( "AAA", "11111", true, 2.00 ) );
	MenuB->add( new MenuItem( "BBBB", "22222", false, 3.00 ) );
	MenuCToA->add( new MenuItem( "CCCC", "33333", false, 4.022 ) );
	
	//女仆
	Waitress *waiter = new Waitress( rootMenu );
	waiter->print();
	
	return 0;
}