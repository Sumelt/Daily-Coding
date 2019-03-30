/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include "18.h"

namespace space{
	int value;
}

namespace space{
	char c = 3;
}

namespace sp = space;

int main(int argc, char *argv[])
{
	sp::value = 3;
	sp::c = 4;
	return 0;
}