#include<bits/stdc++.h>
#define pii pair<int,int>
#define ll long long int
#define inf 99999999
#define pb push_back
#define AC ios::sync_with_stdio(0);cin.tie(0);
using namespace std;
int n,m,T;
vector<int>g[200004];
int a[200004],b[200004];
int vis[200004];
ll sum,s[2];
bool dfs(int x){
	bool t=0;
	sum+=b[x],s[vis[x]]+=b[x];
	for(auto y:g[x]){
		if(vis[y]<0){
			vis[y]=vis[x]^1;if(dfs(y))t=1;
		}
		else{
			if(vis[x]==vis[y])t=1;
		}
	}
	return t;
}
int main(){
	AC
    cin>>T;
    while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>a[i],vis[i]=-1,g[i].clear();
		for(int i=1;i<=n;i++)cin>>b[i],b[i]-=a[i];
		for(int i=0;i<m;i++){
			int u,v;cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for(int i=1;i<=n;i++)
		if(vis[i]<0){
			sum=s[0]=s[1]=0;
			vis[i]=0;
			if(!dfs(i)&&s[0]!=s[1]){
				cout<<"NO\n";return;
			}
			if(sum&1){
				cout<<"NO\n";return;
			}
		}
		cout<<"YES\n";
	}
}