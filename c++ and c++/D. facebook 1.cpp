#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define ll long long int
#define fast ios::sync_with_stdio(0); cin.tie(0);
#define pii pair<int,int>
#define inf 9999999
using namespace std;
int a,b;


int vis[200005];
vector<int> a1[200005];
int main(){
	fast
	cin>>a>>b;
	string str;cin>>str;
	for(int i=1;i<=a;i++){
		vis[i] = str[i-1]-'0';
	}
	while(b--){
		int u,v;cin>>u>>v;
		a1[u].pb(v);
		a1[v].pb(u);
	}
	ll ans= 0;
	for(int i=1;i<=a;i++){
		if(vis[i]){
			int cnt = 0;
			for(int j=0;j<a1[i].size();j++){
				if(!vis[a1[i][j]]) cnt++; 
			}
			ans+=a1[i].size()*(a1[i].size()-1)-(a1[i].size()-cnt)*cnt;
		}
		else{
			ans += a1[i].size()*(a1[i].size()-1);
		}
		//cout<<ans<<"\n";
	}
	cout<<ans<<"\n";
}

