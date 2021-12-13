#include<bits/stdc++.h>
#define pii pair<int,int>
#define ll long long int
#define inf 99999999
#define pb push_back
#define AC ios::sync_with_stdio(0);cin.tie(0);
using namespace std;

int s, t, w, z;
int edge[501][501];
int ans[501];
int n,m;
int main(){
	AC
	cin>>n>>m;
    for (int i = 0; i < m; i++) {
		int u,v;
		cin>>u>>v;
		e[u][v] = i;
		edge[i] = make_pair(u,v);
	}
	queue<int> q;
	vector<pii> record(n);
	vector<int> dis(n,-1); dis[0] = 0;
	q.pb(0)
    while(!q.empty()){
        int i = q.front(); q.pop();
        for(int j = 0; j < n; j++) if(dis[j] == -1 && e[i][j] != -1){
            dis[j] = dis[i] + 1;
            record[j] = make_pair(i,e[i][j]);
            q.push(j);
        }
    }
    if(dis[n-1] == -1){
        for(int i = 0; i < m; i++) cout<<-1<<"\n";
        return 0;
    }
	vector<int> path;
	int cur = n-1;
	while(!cur){
		path.pb(record[cur].second);
		cur = record[cur].first;
	}
	vector<int> ans(m,dis[n-1]);
	for(int y:path){
		e[edge[y].first][edge[y].second] = -1;
        queue<int> que; que.push(0);
        vector<int> dis(n, -1); dis[0] = 0;
        while(!que.empty()){
            int i = que.front(); que.pop();
            for(int j = 0; j < n; j++) if(dis[j] == -1 && G[i][j] != -1){
                dis[j] = dis[i] + 1;
                qu.push(j);
            }
        }
        ans[y] = dis[n-1];
        G[edge[y].first][edge[y].second] = y;
	}
	for(int i=0;i<m;i++)cout<<ans[i]<<"\n";
}