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

int sgDay[13] = {
	0, 31,28,31,30,31,30,31,31,30,31,30,30
};

class Date{
	private:
		int year;
		int month;
		int day;
	public:
		int tpyear;
		void set_values (int, int, int);	
		friend int count_day(Date, bool);
		friend bool leap(Date);
		friend int subs(int, int, Date, bool);
	
};

void Date::set_values(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
	tpyear = y;
}

bool leap(Date yr)  // 
{
	if((yr.year%4==0&&yr.year%100!=0)||yr.year%400==0)
		return true;
	else return false;
}

int count_day(Date mydate, bool flag)
{
	int sumday = 0;
	if(flag)// rear
	{				
		for(int i = mydate.month+1; i<13; i++)
			sumday+=sgDay[i];
		if(mydate.month==1)
			if(leap(mydate)) sumday+=1;
		else if(mydate.month==2)
		 	if(leap(mydate)) sumday+=sgDay[mydate.month]+1 - mydate.day;
			 else sumday+=sgDay[mydate.month] - mydate.day;	
	 	sumday+=sgDay[mydate.month] - mydate.day+1;	
	}
	
	else //head
	{
		for(int i = mydate.month-1; i>=1; i--)
			sumday+=sgDay[i];
		if(mydate.month>2&&leap(mydate)) sumday+=1;
		sumday+=mydate.day;				
	}
	return sumday;
}

inline int subs(Date mydate, bool flag)
{
	int sum;
	sum = count_day(mydate, flag);
	return sum;
}

int main(int argc, char *argv[])
{
	int year[2], month[2], day[2];
	Date y1, y2, ctemp;
	int sum = 0, temp;
	
	cin>>year[0]>>month[0]>>day[0];
	cin>>year[1]>>month[1]>>day[1];
		 
	if(year[0]!=year[1])
	{
		if(month[0]>12||month[1]>12||month[0]<1||month[1]<1|| \
		day[0]>31||day[1]>31||day[0]<1||day[1]<1){
			cout<<"time error!";
			return 0;
		}
		
		
		if(year[1]+month[1]+day[1]<year[0]+month[0]+day[0])
			{
				y1.set_values(year[1], month[1], day[1]);
				y2.set_values(year[0], month[0], day[0]);
				temp = year[1];
			}
		else
			{
				y2.set_values(year[1], month[1], day[1]);
				y1.set_values(year[0], month[0], day[0]);
				temp = year[0];
			}
			
		for(int i = 1; i<abs(y2.tpyear-y1.tpyear); i++)
			{
				ctemp.set_values(temp+i, 0 ,0);
				if(leap(ctemp)) sum+=366;
				else sum+=365;
			}
			
		printf("%d", subs(y1, true)+subs(y2, false)+sum);
	}
		
	else  cout<<"time error!";
	
	return 0;
}
