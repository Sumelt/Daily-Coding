/*----------------------------------------------------------------

* @Author: Su

* @Description:

* @Creath Date: 02/09/18 23:24

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <string.h>

using namespace std;

struct Participant{
	int teamnumber;
	double score;
}Participants[10000];

int cmp(struct Participant a, struct Participant b)
{
	if(a.score>b.score) return 1;
	else return 0;
}

int main(int argc, char *argv[])
{
	int number,max = 0;
	int a,b,c;
	
	cin>>number; 
	memset(Participants,0,sizeof(struct Participant));
	for(int i = 0; i<number; i++)
	{
		memset(Participants+i,0,sizeof(struct Participant));
		scanf("%d-%d%d",&a,&b,&c);
		Participants[a].teamnumber = a;
		Participants[a].score += c;
	}
	sort(Participants,Participants+1000,cmp);

	cout<<Participants[0].teamnumber<<' '<<Participants[0].score;
	return 0;
}




