/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date:03/11/18 13:59

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

map<string, int>StrToInt;
map<int, string>IntToStr;
map<string, int>gand;

const int Max = 2010;
int v[Max][Max] = {0};
int Point[Max] = {0};
bool vis[Max] = {false};
int n, k;
int NumPep = 0;


void DFS(int NowInx, int& head, int& member, int& totallValue)
{
	member++;
	vis[NowInx] = true;
	if(Point[head]<Point[NowInx])
		head = NowInx;
	
	for(int i = 0; i<NumPep; i++){
		if(v[NowInx][i]>0){
			totallValue += v[NowInx][i];
			v[NowInx][i] = v[i][NowInx] = 0;
			if(vis[i]==false)
				DFS(i, head, member, totallValue);					
		}
			
	}	
	
}

void TravalDFS()
{
	for(int i = 0; i<NumPep; i++)
	{
		if(vis[i]==false){
			int head = i, member = 0, totallValue = 0;
			DFS(i, head, member, totallValue);
			if(member > 2 && totallValue > k)
				gand[IntToStr[head]] = member;
		}
		
	}
	
}

int StrToNub(string str)
{
	if(StrToInt.find(str)!=StrToInt.end())
		return StrToInt[str];
	else{
		StrToInt[str] = NumPep;
		IntToStr[NumPep] = str;
		return NumPep++;		
	}

}

int main(int argc, char *argv[])
{
	string str1, str2;
	int time;
	cin>>n>>k;
	
	for(int i = 0; i<n ; i++)	
	{
		cin>> str1 >> str2 >> time;
		int inx1 = StrToNub(str1);
		int inx2 = StrToNub(str2);
		Point[inx1] += time;
		Point[inx2] += time;
		v[inx1][inx2] += time;
		v[inx2][inx1] += time;
	}
	TravalDFS();
	
	cout<<gand.size()<<endl;
	//cout<<NumPep<<endl;
	//map<string, int>::iterator it;
	for(auto it = gand.begin(); it!=gand.end(); it++)
		cout<<it->first<<' '<<it->second<<endl;
	
	return 0;
}
