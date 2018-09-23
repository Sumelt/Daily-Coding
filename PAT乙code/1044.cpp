/*----------------------------------------------------------------

* @Author: Su

* @Description:1044

* @Creath Date: 15/09/18 14:14

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>

using namespace std;

map<int,string>dwmp1;
map<int,string>dwmp2;
map<string, int>wdmp1;

void inmp()
{  //jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec
	dwmp1[0] = "tret";
	dwmp1[1] = "jan";
	dwmp1[2] = "feb";
	dwmp1[3] = "mar";
	dwmp1[4] = "apr";
	dwmp1[5] = "may";
	dwmp1[6] = "jun";
	dwmp1[7] = "jly";
	dwmp1[8] = "aug";
	dwmp1[9] = "sep";
	dwmp1[10] = "oct";
	dwmp1[11] = "nov";
	dwmp1[12] = "dec";
	//tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou?
	dwmp2[1] = "tam";
	dwmp2[2] = "hel";
	dwmp2[3] = "maa";
	dwmp2[4] = "huh";
	dwmp2[5] = "tou";
	dwmp2[6] = "kes";
	dwmp2[7] = "hei";
	dwmp2[8] = "elo";
	dwmp2[9] = "syy";
	dwmp2[10] = "lok";
	dwmp2[11] = "mer";
	dwmp2[12] = "jou";
	
	wdmp1["tret"] = 0;
	wdmp1["jan"] = 1; 
	wdmp1["feb"] = 2;
	wdmp1["mar"] = 3;
	wdmp1["apr"] = 4;
	wdmp1["may"] = 5;
	wdmp1["jun"] = 6;
	wdmp1["jly"] = 7;
	wdmp1["aug"] = 8;
	wdmp1["sep"] = 9;
	wdmp1["oct"] = 10;
	wdmp1["nov"] = 11;
	wdmp1["dec"] = 12;
	
	wdmp1["tam"]=1*13;
	wdmp1["hel"]=2*13;
	wdmp1["maa"]=3*13;
	wdmp1["huh"]=4*13;
	wdmp1["tou"]=5*13;
	wdmp1["kes"]=6*13;
	wdmp1["hei"]=7*13;
	wdmp1["elo"]=8*13;
	wdmp1["syy"]=9*13;
	wdmp1["lok"]=10*13;
	wdmp1["mer"]=11*13;
	wdmp1["jou"]=12*13;
	
}

int main(int argc, char *argv[])
{

	int n;
	cin>>n;
	cin.get();
	inmp();
	for(int i=0; i<n; i++)
	{
		string temp;
		getline(cin,temp);
		if(isdigit(temp[0]))
		{
			long tp = atoi(temp.c_str());
			if(tp>13&&tp%13!=0){
				cout<<dwmp2[tp/13]<<' ';
				cout<<dwmp1[tp%13]<<endl;
			}
			else if(tp<13)cout<<dwmp1[tp]<<endl;
			else cout<<dwmp2[tp/13]<<endl;
			
		}
		else
		{
			int res = 0;
			string tp;
			if(temp.length()>3){
				long j = temp.find(' ');
				tp.insert(tp.begin(), temp.begin(), temp.begin()+j);
				res += wdmp1[tp];
				tp.clear();	
				tp.insert(tp.begin(),temp.begin()+j+1,temp.end());
				res += wdmp1[tp];			
			}
			else
				res += wdmp1[temp];			
			cout<<res<<endl;		
		}
		temp.clear();
	}
	return 0;
}




