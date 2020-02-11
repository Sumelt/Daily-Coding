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


class MenuItem {
private:
	string m_name;
	string m_description;
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
};

//迭代器接口 
class Iterator {
public:
	virtual bool hasNext() = 0;
	virtual MenuItem next() = 0;
	
};

//A餐厅迭代器 
class PancakeHouseMenuIterator : public	Iterator {
private:
	int index = 0;
	vector<MenuItem*> m_arrayList; 
public:
	PancakeHouseMenuIterator( vector<MenuItem*> &arrayList ) {
		m_arrayList = arrayList;
	}
	bool hasNext() {
		if( index < m_arrayList.size() && m_arrayList[ index ] != nullptr )	
			return true;
		return false;
	}
	MenuItem next() {
		return *( m_arrayList[ index++ ] );
	}
};

//餐厅A 
class PancakeHouseMenu {
private:
	vector<MenuItem*>m_arrayList;
public:
	PancakeHouseMenu() {
		addItem( "bule pancake", "with eage, sugar", false, 2.99 );
		addItem( "bbbbb pancake", "with eage, sugar", false, 2.99 );
	}
	
	void addItem( const string &name, const string &desciption, bool vegetarian, double price ) {
		MenuItem *item = new MenuItem( name, desciption, vegetarian, price );
		m_arrayList.push_back( item );
	}
	vector<MenuItem*> getMenuItems() {
		return m_arrayList;
	}
	int getLength() {
		return m_arrayList.size();
	}
	//创建A餐厅迭代器 
	Iterator* createIterator() {
		return new PancakeHouseMenuIterator( m_arrayList );
	}
	void print() {
		for( auto p_value : m_arrayList )
			cout << p_value->getName() << ' ';
	}
};

//-------------------------------
//餐厅B的迭代器
class DinerMenuIterator : public Iterator {
private:
	int index = 0;
	MenuItem *m_array;
public:
	//传入一个菜单 
	DinerMenuIterator( MenuItem *array ) : m_array( array ) {}
	//获得下一个项目项
	MenuItem next() {
		MenuItem p_res = m_array[ index ];
		++index;
		return p_res;
	}
	//是否还有下一项 
	bool hasNext() {
		if( index < 7 && m_array[ index ].getPrice() > 0  )
			return true;
		return false;
	}
};

//餐厅B 
class DinerMenu  {
private:
	static int m_MaxCount;
	int m_index = 0;
	MenuItem *m_array;
public:
	DinerMenu() {
		m_array = new MenuItem[ m_MaxCount ]();
		addItem( "green Diner", "with eage, sugar", true, 3.00 );
		addItem( "yyyy Diner", "coool", true, 3.00 );
	}
	~DinerMenu() {
		delete []m_array;
	}

	void addItem( const string &name, const string &desciption, bool vegetarian, double price ) {
		MenuItem *item = new MenuItem( name, desciption, vegetarian, price );
		if( m_index < DinerMenu	::m_MaxCount ) {
			m_array[ m_index ] = *item;
			++m_index;
		}

	}
	int getLength() {
		return m_MaxCount;
	}
	//创建B餐厅迭代器 
	Iterator* createIterator() {
		return new DinerMenuIterator( m_array );//把第一个元素的地址传入 
	}

	void print() {
		cout << m_array[ 0 ].getName() << ' ';
		cout << m_array[ 1 ].getName() << ' ';	
	}
};
int DinerMenu::m_MaxCount = 7;

//女招待 
class Waitress {
private:
	DinerMenu *m_dinermenu;
	PancakeHouseMenu *m_pancakehousemenu;
	//通用迭代器 
	void printMenu( Iterator *iterator ) {
		while( iterator->hasNext() )	 {
			MenuItem iter = iterator->next();
			cout << iter.getName() << ' ' << iter.getDescription() << ' '
				<< iter.getPrice() << endl;
		}
	}
public:
	Waitress( DinerMenu *dinnerMenu, PancakeHouseMenu *pancakeMenu ) {
		m_dinermenu = dinnerMenu;
		m_pancakehousemenu = pancakeMenu;
	}
	//输出方法 
	void printMenu() {
		Iterator *dinerMenuiterator = m_dinermenu->createIterator();
		Iterator *pancakeHouseIterator = m_pancakehousemenu->createIterator();
		
		cout << "-------DinerMenu--------" << endl;
		printMenu( dinerMenuiterator );
		cout << "-------PancakeHouseMenu--------" << endl;
		printMenu( pancakeHouseIterator );
	}
};

int main(int argc, char *argv[])
{
	PancakeHouseMenu *pmenu = new PancakeHouseMenu();
	DinerMenu *dmenu = new DinerMenu();
	
	Waitress *waiter = new Waitress( dmenu, pmenu );
	waiter->printMenu();
	
	delete pmenu;
	delete dmenu;
	
	return 0;
}