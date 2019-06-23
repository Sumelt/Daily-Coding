#ifndef __CODETIME__H_
#define __CODETIME__H_

#include <iostream>
#include <ctime>

clock_t tbegin, tend;

void costTime() {
	double cost = (double)( tend - tbegin) / CLOCKS_PER_SEC;
	cout << "cost Time: " << cost << " s" << endl;
	return;
}



#endif