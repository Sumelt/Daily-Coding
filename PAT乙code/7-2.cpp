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
	if(year<s2.year) return true;
	else if(year==s2.year){
		if(month<s2.month) return true;
		else if(month==s2.month){
			if(day<s2.day) return true;
			else if(day==s2.day){
				if(hour<s2.hour) return true;
				else if(hour==s2.hour){
					if(minute<s2.minute) return true;
					else if(minute==s2.minute){
						if(second<s2.second) return true;
						 else if(second==s2.second) return true;
						 	else false;
					}
					else false;
				}
				else false;
			}
			else false;
		}
		else false;
	}
	else false;
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
		if(!count++) min_sch.set_values(id, y, m, d, h, mu, sec);
			else input_sch.set_values(id, y, m, d, h, mu, sec);
		if(!(min_sch<input_sch))  min_sch = input_sch;
	}
	
	if(count){
		cout<<"The urgent schedule is No.";
		min_sch.prin();
	}
		
	return 0;
}

