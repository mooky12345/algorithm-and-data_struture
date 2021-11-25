#include<bits/stdc++.h>
#define pii pair<int,int>
#define ll long long int
#define f first
#define s second
#define inf 99999999
#define pb push_back
#define intt __int128_t
#define AC ios::sync_with_stdio(0);cin.tie(0);
using namespace std;
 
 
 
vector<int> e[200005];
int cnt[200005];
ll ans[200005];
ll sum = 0;
int a;
void dfs(int v,int pre,int dep){
	cnt[v] = 1;
	sum += dep;
	for(int i:e[v]){
		if(i!=pre){
			dfs(i,v,dep+1);
			cnt[v] += cnt[i];
		}
	}
}
void dfs2(ll summ,int v,int pre){
	if(v!=pre){
		summ -= 1LL*2*cnt[v]-a;
		ans[v] =  summ;
	}
	
	for(int i:e[v]){
		if(i!=pre){
			dfs2(summ,i,v);
		}
	}
}
int main(){
	AC
	
	cin>>a;
	
	for(int i=0;i<a-1;i++){
		int u,v;cin>>u>>v;
		e[u].pb(v);
		e[v].pb(u);
	}
	dfs(1,1,0);
	ans[1] = sum; 
	dfs2(sum,1,1);
	for(int i=1;i<=a;i++)cout<<ans[i]<<" ";
}