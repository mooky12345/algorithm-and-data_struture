#include<bits/stdc++.h>
#define pii pair<int,int>
#define x first
#define y second
using namespace std;
vector<pii> v;int k;
map<int,int> mp;
int a1[1000];
int b1[1000];
int b;
int ans = 0;
void dfs(int x1){
	if(x1==k){
		int ans1 = 0; 
		for(int i=0;i<b;i++){
			if(mp[a1[i]] && mp[b1[i]]){
				ans1++;
			}
		}
		if(ans1>ans){
			ans = ans1;
		}
		return;
	}
	mp[v[x1].x]++;
	dfs(x1+1);
	mp[v[x1].x]--;
	mp[v[x1].y]++;
	dfs(x1+1);
	mp[v[x1].y]--;
}
int main(){
	int a;
	cin>>a>>b;
	for(int i=0;i<b;i++){
		cin>>a1[i]>>b1[i];
	}
	
	cin>>k;
	int j = k;
	while(j--){
		int u,v1;
		cin>>u>>v1;
		v.push_back({u,v1});
	}
	dfs(0);
	cout<<ans;
	
}