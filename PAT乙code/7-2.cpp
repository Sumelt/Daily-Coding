/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>

using namespace std;

class Date{
	protected :
		int year;
		int month;
		int day;
};

class Time{
	protected :
		int hour;
		int minute;
		int second;
	
};

class Schedule : public Date, public Time{
	private:	
		int ID;
		
	public:
		void set_values (int, int, int, int, int, int, int);
		void prin();
		bool operator < (const Schedule & s2);
};

void Schedule :: set_values(int id, int y, int m, int d, int h, int mu, int sec)
{
	ID = id;
	year = y;
	month = m;
	day = d;
	hour = h;
	minute = mu;
	second = sec;
}
inline void Schedule ::prin()
{
	printf("%d: %d/%d/%d %d:%d:%d", ID, year, month, day, hour, minute, second);
}

bool Schedule :: operator < (const Schedule & s2)
{
	string str1, str2;
	str1 = to_string(year)+to_string(month)+to_string(day)+to_string(hour)\
	+to_string(minute)+to_string(second);
	
	str2 = to_string(s2.year)+to_string(s2.month)+to_string(s2.day)\
	+to_string(s2.hour)+to_string(s2.minute)+to_string(s2.second);
	
	cout<<str1<<endl<<str2;
	
	if(str1<str2) return true;
		else return false;
	
/*
str1 = to_string(year)+to_string(month)+to_string(day);
	str2 = to_string(s2.year)+to_string(s2.month)+to_string(s2.day);
	if(str1<str2) return true;
	else if(str1==str2)
	{
		str1.clear();
		str2.clear();
		str1 = to_string(hour)+to_string(minute)+to_string(second);
		str2 = to_string(s2.hour)+to_string(s2.minute)+to_string(s2.second);
		if(str1<str2) return true;
		else return false;
	}
	else return false;*/
	
}

int main(int argc, char *argv[])
{
	Schedule min_sch, input_sch;	
	int id, y, m, d, h, mu, sec;
	int count = 0;

	while(1)
	{
		cin>>id;
		if(!id) break;
		scanf("%d/%d/%d %d:%d:%d", &y, &m, &d, &h, &mu, &sec);
		if(!count++){
			 min_sch.set_values(id, y, m, d, h, mu, sec);
			 input_sch = min_sch;
		}
		else input_sch.set_values(id, y, m, d, h, mu, sec);
		if(input_sch<min_sch)  min_sch = input_sch;
	}
	
	if(count){
		cout<<"The urgent schedule is No.";
		min_sch.prin();
	}
		
	return 0;
}
