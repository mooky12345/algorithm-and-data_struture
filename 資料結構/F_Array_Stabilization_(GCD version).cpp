#include<bits/stdc++.h>
#define pii pair<int,int>
#define ll long long int
#define f first
#define s second
#define inf 999999990
#define pb push_back
#define AC ios::sync_with_stdio(0);cin.tie(0);
using namespace std;
 
int a,b;
int dp[1000005][31];
int g = 0;
 
inline ll q(ll l,ll r){
	int k = log2(r-l+1);
	return __gcd(dp[l][k],dp[r-(1<<k)+1][k]);
}
int test(ll m){
	for(int i=0;i<a;i++){
		if(g != q(i,i+m)) return 1; 
	}
	return 0;
}
int main(){
	AC
	int t;
	cin>>t;
	
	while(t--){
		cin>>a;
		g = 0;
		for(int i=0;i<a;i++){
			cin>>dp[i][0];
			dp[i+a][0] = dp[i][0];
			g = __gcd(dp[i][0],g);
		}	
		for(int j=1;j<20;j++){
			for(int i=0;(i+ (1<<j)-1)<a*2;i++){
				dp[i][j] = __gcd(dp[i][j-1],dp[i + (1<<(j-1))][j-1]);
			}
		}
		
		int l = 0;
		int r = a-1;
		while(l<r){
			ll m = (l+r)/2;
			if(test(m)){
				l = m+1;
			}
			else {
				r = m;
			}
		}
		cout<<l<<"\n";
	}
	
}