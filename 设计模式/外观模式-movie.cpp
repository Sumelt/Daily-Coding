/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
class DVD {
	
};

class homeTheaterFacade {
private:
 //看电影的设备组件
	DVD *m_dvd;
public:
	homeTheaterFacade( DVD *dvd ) : m_dvd( dvd ) {}
	void watchMovie(){/*看电影一些的操作 */}
	void endMovie() {/*结束电影的一些操作*/}
};


int main(int argc, char *argv[])
{
	homeTheaterFacade *facade = new homeTheaterFacade( new DVD() );
	facade->watchMovie();
	facade->endMovie();
	
	return 0;
}