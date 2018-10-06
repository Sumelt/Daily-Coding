/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date: 06/10/18 15:42

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>


using namespace std;

int main(int argc, char *argv[])
{
	signed long a, b;
	string res, tpres;
	int j = 0;
	
	cin>>a>>b;
	res = to_string(a+b);
		
	if(res.length()>3)
	{
		reverse(res.begin(), res.end());
		tpres.clear();
		for(int i =0; i<res.length()/3; i++)
		{			
			for(int k = 0; k<3; k++)
				tpres += res[j++];
			if(res.length()%3!=0) tpres += ',';
			else if(i<res.length()-1) tpres += ',';
		}
				
		while(j<res.length()) tpres += res[j++];
		reverse(tpres.begin(), tpres.end());
		if(tpres[0]=='-'&&tpres[1]==',') tpres.erase(tpres.begin()+1);
		res.clear();
		res = tpres;
	}	
	cout<<res;
	return 0;
}




