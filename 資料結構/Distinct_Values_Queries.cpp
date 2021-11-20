#include<bits/stdc++.h>
#define pii pair<int,int>
#define ll long long int
#define f first
#define s second
#define inf 99999999
#define pb push_back
#define AC ios::sync_with_stdio(0);cin.tie(0);
using namespace std;
 
 
 
const int maxx = 4e5+5;
int ans[maxx];
ll bit[maxx];
int a1[maxx];
vector<pii> query[maxx];
map<int,int> mp;
int a,b;
void up(int pos,int val){
	while(pos<=a){
		bit[pos]+=val;
		pos += pos & (-pos);	
	}
}
int q(int val){
	int ret = 0;
	while(val){
		ret += bit[val];
		val -= (-val) & val;
	}
	return ret;
}
int main(){
	AC
	cin>>a>>b;
	for(int i=1;i<=a;i++)cin>>a1[i];
	for(int i=0;i<b;i++){
		int u,v;cin>>u>>v;
		query[u].pb({v,i});
	}
	for(int i=a;i>=1;i--){
		int z = a1[i];
		if(mp.count(z)) up(mp[z],-1);
		mp[z] = i;
		up(i,1);
		for(auto t:query[i]){
			ans[t.s] = q(t.f);
		}
	}
	for(int i=0;i<b;i++){
		cout<<ans[i]<<"\n";
	}
}
 