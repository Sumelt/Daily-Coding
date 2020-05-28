/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
	bool vis[100010] = {false};
	int n, number;
	scanf("%d", &n);
	
	for(int i = 0; i<n; i++)
	{
		scanf("%d", &number);
		if(number>0&&number<=100010)
			vis[number] = true;
	}
	for(int i = 1; i<=100010; i++){
		if(!vis[i]){
			printf("%d", i);
			break;
		} 	
	}
	return 0;
}

