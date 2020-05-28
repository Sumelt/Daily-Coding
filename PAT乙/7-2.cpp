/*----------------------------------------------------------------

* @Author: Su

* @Description: 用string对象处理日期会溢出，第一点数据很大，改用 sprintf是个很
	聪明的办法 

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
	char str1[15], str2[15];
	sprintf(str1, "%04d%02d%02d%02d%02d%02d", year, month, day\
 	,hour, minute, second);
 	sprintf(str2, "%04d%02d%02d%02d%02d%02d", s2.year, s2.month, s2.day\
  	, s2.hour, s2.minute, s2.second);
	
	
	if(atof(str1)<atof(str2)) return true;
		else return false;	
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
