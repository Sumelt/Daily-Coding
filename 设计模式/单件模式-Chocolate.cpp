/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <cassert>
#include <mutex>

using namespace std;

class Chocolate {
private:
	static Chocolate *instance;
	Chocolate() = default;
	//资源管理类 
	class DelTool {
		public:
		~DelTool();
		static DelTool del;
	};
public:
	static Chocolate* getInstance();
	static mutex mlock;
	static void destory();
};

Chocolate::DelTool Chocolate::DelTool::del;
Chocolate::DelTool::~DelTool() {
	if( instance != nullptr )
		delete instance;
}

//手动释放 
void Chocolate::destory() {
	if( instance != nullptr )
		delete instance;
}


//懒汉模式 
Chocolate* Chocolate::instance = nullptr;
Chocolate* Chocolate::getInstance() {
	if( instance == nullptr ) {		
		std::lock_guard<std::mutex> lock( mlock );  // 自解锁
		if( instance == nullptr ) {
			instance = new Chocolate();
			cout << "create only ont object" << endl;
		}
	}		
	return instance;
}

//饿汉模式 
//Chocolate* Chocolate::instance = new Chocolate();
//Chocolate* Chocolate::getInstance() {		
//	return instance;
//}

int main(int argc, char *argv[])
{
	auto ptr = Chocolate::getInstance();
	return 0;
}

