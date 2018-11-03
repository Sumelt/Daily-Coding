/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <string>
#include <map>

using namespace std;

map<int, string>inttostring;
map<string, int>stringtoint;
map<string, int>gang;

const int Max = 2010;
int G[Max][Max] = {0};
int weight[Max] = {0};
bool vis[Max] = {false};
int n, k, numperson = 0;

/*
void DFS(int nowvisit, int& head, int& nummember, int& totalValue)
{
	nummember++;
	vis[nowvisit] = true;
	if(weight[head]<weight[nowvisit])
		head = nowvisit;
	
	for(int i = 0; i<numperson; i++){
		if(G[nowvisit][i]>0){
			totalValue += G[nowvisit][i];
			G[nowvisit][i] = G[i][nowvisit] = 0;
			if(vis[i]==false)
				DFS(i, head, nummember, totalValue);					
		}
			
	}	
	
}

void TravalDFS()
{
	for(int i = 0; i<numperson; i++)
	{
		if(vis[i]==false){
			int head = i, nummember = 0, totalValue = 0;
			DFS(i, head, nummember, totalValue);
			if(nummember>2&&totalValue>k)
				gang[inttostring[head]] = nummember;
		}		
	}	
}*/

void dfs(int u, int &head, int &numMember, int &totalweight) {
    vis[u] = true;
    numMember++;
    if(weight[u] > weight[head])
        head = u;
    for(int v = 0; v < numperson; v++) {
        if(G[u][v] > 0) {
            totalweight += G[u][v];
            G[u][v] = G[v][u] = 0;
            if(vis[v] == false)
                dfs(v, head, numMember, totalweight);
        }
    }
}
void TravalDFS() {
    for(int i = 0; i < numperson; i++) {
        if(vis[i] == false) {
            int head = i, numMember = 0, totalweight = 0;
            dfs(i, head, numMember, totalweight);
            if(numMember > 2 && totalweight > k)
                gang[inttostring[head]] = numMember;
        }
    }
}

int change(string str)
{
	if(stringtoint.find(str)!=stringtoint.end())
		return stringtoint[str];
	else{
		stringtoint[str] = numperson;
		inttostring[numperson] = str;
		return numperson++;		
	}

}


int main(int argc, char *argv[])
{
	int w;
	string str1, str2;	
	cin>>n>>k;
	
	/*
for(int i = 0; i<n ; i++)	
	{
		cin>>str1>>str1>>time;
		int inx1 = change(str1);
		int inx2 = change(str2);
		weight[inx1] += time;
		weight[inx2] += time;
		G[inx1][inx2] += time;
		G[inx2][inx1] += time;
	}*/
	for(int i = 0; i < n; i++) {
        cin >> str1 >> str2 >> w;
        int id1 = change(str1);
        int id2 = change(str2);
        weight[id1] += w;
        weight[id2] += w;
        G[id1][id2] += w;
        G[id2][id1] += w;
    }
	TravalDFS();
	
	/*
cout<<gang.size()<<endl;
	map<string, int>::iterator it;
	for(it = gang.begin(); it!=gang.end(); it++)
		cout<<it->first<<' '<<it->second<<endl;*/
		cout << gang.size() << endl;
    for(auto it = gang.begin(); it != gang.end(); it++)
        cout << it->first << " " << it->second << endl;
	return 0;
}

/*
int main() {
    int w;
    cin >> n >> k;
    string s1, s2;
    for(int i = 0; i < n; i++) {
        cin >> s1 >> s2 >> w;
        int id1 = change(s1);
        int id2 = change(s2);
        weight[id1] += w;
        weight[id2] += w;
        G[id1][id2] += w;
        G[id2][id1] += w;
    }
    TravalDFS();
    cout << gang.size() << endl;
    for(auto it = gang.begin(); it != gang.end(); it++)
        cout << it->first << " " << it->second << endl;
    return 0;
}*/