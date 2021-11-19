#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define int long long
#define N 1000005
#define AC ios::sync_with_stdio(0),cin.tie(0);
#define INF 2e18
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define all(x) x.begin(),x.end()
#define pii pair<int,int>
#define x first
#define y second
using namespace std;
int n,k,dp[2][N],lft[N],arr[N];
int mp[N];

signed main(){
    AC
    cin>>n>>k;
    memset(dp,0,sizeof(dp));
    memset(lft,0,sizeof(lft));
    memset(mp,0,sizeof(mp));
    rep(i,1,n)cin>>arr[i];
    int l = 1;
    for(int r=1;r<=n;r++){
    	mp[arr[r]]++;
    
    	while(mp[arr[r]] == 2){
    		mp[arr[l]]--;
    		l++;
		}
		lft[r] = l;
	}
//	for(int i=1;i<=n;i++){
//		cout<<lft[i]<<" ";
//	}
//	cout<<"\n";
    for(int i=0;i<k;i++){
        for(int j=1;j<=n;j++){
            dp[1][j] = max(dp[1][j-1],dp[0][lft[j]-1]+j-lft[j]+1);
        }
        for(int j=1;j<=n;j++){
            dp[0][j] = dp[1][j];
        }
    }
    cout<<dp[1][n]<<endl;
}
