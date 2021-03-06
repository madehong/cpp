#include <iostream>
#include <sstream>
#include <ios>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <cctype>
using namespace std;

/***************************
//spfa
***************************/
#define INF 0x3FFFFFFF
typedef  pair<int,int> PII;
const int MAXN = 1010;
vector<PII> G[MAXN];
void add_edge(int u,int v,int d){
    G[u].push_back(make_pair(v,d));
}
void init(int n){
    for(int i=0;i<n;i++)G[i].clear();
}
int vis[MAXN];
int dis[MAXN];
int cnt[MAXN];
void spfa(int s,int n){
    for(int i = 0;i<n;i++)dis[i] = (i == s ? 0 : INF);
    memset(vis,0,sizeof(vis));
    memset(cnt,0,sizeof(cnt));
    queue<int>q;
    q.push(s);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        vis[x] = 0;
        for(int i = 0;i<G[x].size();i++){
            int y = G[x][i].first;
            int d = G[x][i].second;
            if(dis[y] > dis[x] + d){
                dis[y] = dis[x] + d;
                if(!vis[y]){
                    q.push(y);
                    vis[y] = 1;
                }}}}
}
int main()
{
	int t,n;
	//init(n);
	while(cin>>t>>n&&t&&n)
	{
		int u,v,d;
		init(n);
		while(t--)
		{
			cin>>u>>v>>d;
			u--,v--;
			add_edge(u,v,d);
			add_edge(v,u,d);
		}
		spfa(0,n);
		cout<<dis[n-1]<<endl;
	}
	return 0;
}
