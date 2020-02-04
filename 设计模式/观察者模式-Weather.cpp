/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;

class Subject;
class Observer;


//观察者：抽象基类 
class Observer {
private:

public:
	virtual void upate( float temperature, float humidity, float pressure ) = 0;
};

//主题：抽象基类 
class Subject {	
public:
	virtual void registerObserver( Observer *o ) = 0;
	virtual void removeObserver( Observer *o ) = 0;
	virtual void notifyObserver() = 0;
	
};
//具体主题 
class WeatherData : public Subject {
private:
	vector< Observer*>observers;
	float m_temperature;//温度 
	float m_humidity;//湿度 
	float m_pressure;//压强
	bool change = false;
	
public:
	WeatherData(){}
	void registerObserver( Observer *o ) {
		observers.push_back( o );
	}

	void removeObserver( Observer *o ) {
		for( auto iter = observers.begin(); iter != observers.end(); ++iter ) {
			//地址相等 
			if( *iter == o ) {
				*iter = *( observers.end() - 1 ); //用尾部的元素覆盖要删除位置的元素 
				observers.pop_back();//删除尾部 
			}			
		}					
	}

	void notifyObserver() {
		for( auto p_value : observers ) {
				p_value->upate( m_temperature, m_humidity, m_pressure );
		}		
	}
	void measurementChange() {
		notifyObserver();
	}
	//组件信息发生该变 
	void setMeasurementChange( float temperature, float humidity, float	pressure ) {
		this->m_temperature = temperature;
		this->m_humidity = humidity;
		this->m_pressure = pressure;
		measurementChange();
	}
	
};

//显示相关的构件 
class DisplayElement {
public:
	virtual void display() = 0;	
};

//具体观察者 
class CurrentConditionDisplay : public Observer, public	DisplayElement {
private:
	float m_temperature;//温度 
	float m_humidity;//湿度 
	float m_pressure;//压强
	Subject *m_weatherData; //绑定的组件 
	
public:
	CurrentConditionDisplay( Subject *weatherData ) {
		this->m_weatherData = weatherData;
		this->m_weatherData->registerObserver( this ); //观察者加入 
	}
	
	//观察者更新自身 
	void upate( float temperature, float humidity, float pressure ) {
		this->m_temperature = temperature;
		this->m_humidity = humidity;
		display();
	}
		
	void display() {
		cout << "CurrentCondition: temperature, humidity, " 
			<< m_temperature << ' ' << m_humidity << endl; 
	}

};


int main(int argc, char *argv[])
{	
	WeatherData *weather = new WeatherData(); //启动一个气象站
	//观察者1 
	CurrentConditionDisplay *conditionDisplay1 = new CurrentConditionDisplay( weather );
	//观察者2 
	CurrentConditionDisplay *conditionDisplay2 = new CurrentConditionDisplay( weather );
	weather->setMeasurementChange( 30, 22, 100 );//气象数据更新 
	
	weather->removeObserver( conditionDisplay1 ); //删除一号观察者 
	weather->setMeasurementChange( 55, 12, 99 );//气象数据更新 
	
 	delete weather;
 	delete conditionDisplay1;
 	delete conditionDisplay2;
 	
	return 0;
}