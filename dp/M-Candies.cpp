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
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;


int a1[maxn];
int dp[105][maxn],sum[maxn];
int main(){
	fast
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a1[i];
	dp[1][0] = 1; sum[0] = 1;
	for (int i = 1; i <= a1[1]; i++) {
        dp[1][i] = 1; sum[i] = sum[i -1] + dp[1][i];
    }
    for (int i = 1; i <= m; i++) {
        sum[i] = sum[i - 1] + dp[1][i];
    }
    for(int i=2;i<=n;i++){
    	for(int j=0;j<=m;j++){
    		if(j>a1[i]){
    			dp[i][j] = (sum[j]-sum[j-a1[i]-1]+mod)%mod; 
			}
			else{
				dp[i][j] = sum[j];
			}
		}
		sum[0] = dp[i][0];
		for(int u=1;u<=m;u++){
			sum[u] = (sum[u-1]+dp[i][u])%mod;
		}
	}
	cout<<dp[n][m];
}

