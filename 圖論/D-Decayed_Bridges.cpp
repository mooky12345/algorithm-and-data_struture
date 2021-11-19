#include<bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define ll long long int
#define fast ios::sync_with_stdio(0); cin.tie(0);
#define pii pair<int,int>
#define inf 9999999999
#define MOD 1e9+7
using namespace std;


ll now;
ll f[100005];
ll num[100005];
vector<pair<int,int>> e;
int find(int x){
	return (f[x] == x) ? x : f[x] = find(f[x]);
}
void u(int x,int y){
	x = find(x);
	y = find(y);
	if(x==y)return;
	if(num[x]>num[y]) swap(x,y);
	now -= 1LL*num[x]*num[y];
	num[y] += num[x];
	f[x] = y;
	
}
vector<ll> ans(100005);
int main(){
	fast
	int a,b;cin>>a>>b;
	for(int i=1;i<=a;i++){
		f[i] = i;
	}
	for(int i=1;i<=a;i++)num[i] = 1;
	for(int i=1;i<=b;i++){
		int u,v;
		cin>>u>>v;
		e.pb({u,v});
	}
	now = 1LL*a*(a-1)/2;
	for(int i=b-1;i>=0;i--){
		ans[i] = now;
		u(e[i].f,e[i].s);
	}
	for(int i=0;i<b;i++)cout<<ans[i]<<"\n";
}
