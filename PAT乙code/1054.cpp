/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date: 15/09/18 12:00

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
	double res = 0;
	int count = 0;
	int n;
	cin>>n;
	
	string instr;
	string savstr[n];
	bool flag[n];
	fill(flag, flag+n, 1);
	
	for(int i =0; i<n; i++)
	{
		cin>>instr;
		savstr[i] = instr;
		for(int j =0; j<instr.length(); j++)
		{
			if(isdigit(instr[j])==0)
			{
				if(j==0&&instr[j]=='-');
				else if(instr[j]=='.')
				{
					if(instr.length()-1-j>2)
					{
						flag[i] = false;
						break;
					}
						
				}
				else
				{
					flag[i] = false;
					break;
				}
			}
		}
		if(flag[i])
		{
			double temp = strtod(instr.c_str(),NULL);
			if(temp>1000||temp<-1000)
					flag[i] = false;
			else{
				res+=temp;
				count++;
			}
		}
		instr.clear();
	}
	
	for(int i =0; i<n; i++)
	{
		if(!flag[i])		
			cout<<"ERROR: "<<savstr[i]<<" is not a legal number"<<endl;
	}
	if(count<=0) cout<<"The average of 0 numbers is Undefined"<<endl;
	else if(count>1) {
		cout<<"The average of "<<count<<" numbers is ";
		printf("%.2f\n",res/(count*1.0));
	}
	else{
		cout<<"The average of 1 number is ";
		printf("%.2f\n",res);
	} 
	return 0;
}




