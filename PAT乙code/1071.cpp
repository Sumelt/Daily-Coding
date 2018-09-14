/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date: 14/09/18 16:00

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	int money, n;
	int fner, lner;
	int dec, pay;	
	cin>>money>>n;
	int total = money;
	
	for(int i =0; i<n; i++)
	{
		cin>>fner>>dec>>pay>>lner;
		if(total>=pay)
		{
			
			if((fner>lner&&dec==0)||(fner<lner&&dec==1))
			{
				total+=pay;
				printf("Win %d!  Total = %d.\n",pay,total);
			}
			else
			{
				total-=pay;
				printf("Lose %d.  Total = %d.\n",pay,total);
			}
		}
		else if(pay>total)printf("Not enough tokens.  Total = %d.\n",total);
		if(total==0)
		{
			cout<<"Game Over.\n";
			return 0;
		}
	}
	return 0;
}




