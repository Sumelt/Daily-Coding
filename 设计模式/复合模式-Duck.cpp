/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Observer;
class QuackObserverable;

//---观察者模式

//观察者接口 
class Observer {
public:
	virtual void update( QuackObserverable *duck ) = 0;
};

class Quackologist : public Observer {
public:
	void update( QuackObserverable *duck ) {
		cout << "update---------" << endl;
	}
};

//可观察者接口 
class QuackObserverable {
public:
	virtual void registerObserver( Observer* observer ) = 0;
	virtual void notifyObservers() = 0;
};

class Observerable : public QuackObserverable {
private:
	vector<Observer*>m_arrayList;
	QuackObserverable *m_animal; //动物 
public:
	Observerable( QuackObserverable* animal ) : m_animal( animal ) {}
	void registerObserver( Observer *observer ) {
		m_arrayList.push_back( observer );
	}
	void notifyObservers() {
		auto iter = m_arrayList.begin(); 
		while( iter != m_arrayList.end() ) {
			Observer *object = *iter;
			++iter;
			object->update( m_animal );
		}
	}
};

class Quackable : public QuackObserverable {
public:
	virtual void quack() = 0;
	//void registerObserver( Observer* observer ) {}
	//void notifyObservers() {}
};

class DuckA : public Quackable {
private:
	Observerable *m_p_observerable;
public:
	DuckA() {
		m_p_observerable = new Observerable( this );
	}
	void quack() {
		cout << "quack----duckA" << endl;
		notifyObservers();
	}
	void registerObserver( Observer *observer ) {
		m_p_observerable->registerObserver( observer );
	}
	void notifyObservers() {
		m_p_observerable->notifyObservers();
	}
};

class Goose : public QuackObserverable {
private:
	Observerable *m_p_observerable;
public:
	Goose() {
		m_p_observerable = new Observerable( this );
	}
	void hook()	{
		cout << "hook-----goose" << endl;
		notifyObservers();
	}
	void registerObserver( Observer *observer ) {
		m_p_observerable->registerObserver( observer );
	}
	void notifyObservers() {
		m_p_observerable->notifyObservers();
	}
};

//适配器模式 
class GooseAdapter : public Quackable {
private:
	Goose *m_p_goose;
	//Observerable *m_p_observerable;
public:
	GooseAdapter( Goose* goose ) : m_p_goose( goose ) {}
	void quack() {
		m_p_goose->hook();
	}
	void registerObserver( Observer *observer ) {
		m_p_goose->registerObserver( observer );
	}
	void notifyObservers() {}
};

//装饰者模式 
class QuackCounter : public Quackable {
private:
	static int m_count;
	Quackable *m_p_duck;
	
public:
	QuackCounter( Quackable *duck ) : m_p_duck( duck ){}
	void quack() {
		m_p_duck->quack();
		++m_count;
	}
	static int getCount() {
		return m_count;
	}
	void registerObserver( Observer *observer ) {
		m_p_duck->registerObserver( observer );
	}
	void notifyObservers() {}
};

int QuackCounter::m_count = 0;

//抽象工厂
class abstractFactory {
public:
	virtual Quackable* createDuckA() = 0;
	virtual Quackable* createGoose() = 0;
};
//工厂方法 
class counterFactory : public abstractFactory {
public:
	Quackable* createDuckA() {
		return new QuackCounter( new DuckA() );
	}
	Quackable* createGoose() {
		//装饰者 适配器 
		return new QuackCounter( new GooseAdapter( new Goose() ) );
	}
};

//组合模式
class Flock : public Quackable {
private:
	vector<Quackable*>m_arrayList;
	
public:
	void add( Quackable* quack ) {
		m_arrayList.push_back( quack );
	}
	//迭代器模式 
	void quack() {
		auto iter = m_arrayList.begin();
		while( iter != m_arrayList.end() ) {
			Quackable *object = *iter;
			++iter;
			object->quack();
		}
	}
	void registerObserver( Observer* observer ) {
		for( auto p_iter : m_arrayList )
			p_iter->registerObserver( observer );		
	}
	void notifyObservers() {}
};

//模拟器 
class DuckSimulator {
public:
	void simulate( Quackable* duck ) {
		duck->quack();
	}
	
	void simulate( abstractFactory* factory ) {
		Quackable *ducka = factory->createDuckA();
		Quackable *goose1 = factory->createGoose();
		Quackable *goose2 = factory->createGoose();
		Quackable *goose3 = factory->createGoose();
		
		
		Flock *rootDuck = new Flock();
		Flock *gooses = new Flock();
		
		rootDuck->add( ducka );
		
		gooses->add( goose1 );
		gooses->add( goose2 );
		gooses->add( goose3 );
		rootDuck->add( gooses );
		
		Observer *ologist = new Quackologist();
		rootDuck->registerObserver( ologist );
		
		simulate( rootDuck );
		//simulate( goose );
	}
};




int main(int argc, char *argv[])
{
	abstractFactory *factory = new counterFactory();
	DuckSimulator *simulateTest = new DuckSimulator();
	
	simulateTest->simulate( factory );
	
	delete simulateTest;
	delete factory;
	
	return 0;
}