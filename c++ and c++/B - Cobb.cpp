#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define ll long long int
#define fast ios::sync_with_stdio(0); cin.tie(0);
#define pii pair<int,int>
#define inf 9999999
using namespace std;




int main(){
	int t;cin>>t;
	while(t--){
		int a1[200005];
		ll ans = -9999999;
		int a,b;
		cin>>a>>b;
		for(int i =1;i<=a;i++){
			cin>>a1[i];
		}
		for(int i=1;i<=a;i++){
			for(int j = i+1;j<=a;j++){
				ans=max(ans,i*j - 1LL*b*(a1[i]|a1[j]));
			}
		}
		cout<<ans <<"\n";
	}
}

