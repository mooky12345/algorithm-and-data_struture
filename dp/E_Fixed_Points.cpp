#include<bits/stdc++.h>
#define pii pair<int,int>
#define ll long long int
#define f first
#define s second
#define inf 99999999
#define pb push_back
#define AC ios::sync_with_stdio(0);cin.tie(0);
using namespace std;




int main(){
	AC
	int t;
	cin>>t;
	while(t--){
		int ans = inf;
		int a;
		int dp[3000][3000] = {};
		int a1[10000];
		int b;
		cin>>a>>b;
		for(int i=1;i<=a;i++)cin>>a1[i];
		for(int i=1;i<=a;i++){
			for(int j=0;j<=i;j++){
				dp[i][j] = dp[i-1][j]+(a1[i]==(i-j));
				if(j){
					dp[i][j] = max(dp[i][j],dp[i-1][j-1]);
					
				}
				if(dp[i][j]>=b) ans = min(ans,j);
			}
		}
		if(ans == inf)cout<<-1<<"\n";
		else cout<<ans<<"\n";
	}
}