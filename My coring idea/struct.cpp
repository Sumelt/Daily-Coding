/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <string>

using namespace std;

struct comad{
	int id;
	char name;
	
	comad(){}	
	comad(int myid, char myname){
		id = myid;
		name = myname;
	}
	
};

struct comad2{
	int id;
	char name;
	
	comad2(int yourid, char yourname): id(yourid), name(yourname){}
};

struct bign{
	int d[1000];
	int len;
	bign(){
		memset(d, 0, sizeof(d));
		len = 0;
	}
}; 

int main(int argc, char *argv[])
{
	comad myifo = comad(45, 'S');
	cout<<myifo.id;
	return 0;
}




