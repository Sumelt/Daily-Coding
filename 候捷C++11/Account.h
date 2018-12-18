/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date: using static 

----------------------------------------------------------------*/

#ifndef SOMETHING_H
#define SOMETHING_H

class Account {
	
	public:
		static double m_rate;
		static void set_rate(const double& x) {
			m_rate = x;
		}
};
double Account::m_rate = 8.0;

//use method 
//Account::set_rate(6.0);
//Account demo;
//demo::set_rate(5.0);

#endif
/*
	Name: 
	Copyright: 
	Author: 
	Date: 18/12/18 16:01
	Description: 
*/





