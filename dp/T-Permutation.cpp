#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second
#define ll long long int
#define fast ios::sync_with_stdio(0); cin.tie(0);
#define pii pair<int,int>
#define inf 9999999999
#define MOD 1e9+7
using namespace std;
ll MOD = 1000000007;
 
ll N, dp[3010][3010], cum[3010];
string s;
 
int main () {
  cin >> N;
  cin >> s;
  for(int i=0;i<N;i++){
      dp[0][i] = 1;
  }
  for(int i=1;i<N;i++) {
      for(int j=0;j<N;j++) cum[j+1] = (dp[i-1][j] + cum[j]) % MOD;
      for(int j= 0;j<N-i;j++) {
          if (s[i-1] == '<') {
              dp[i][j] = (cum[N-i+1] - cum[j+1] + MOD) % MOD;
          } 
          else {
              dp[i][j] = (cum[j+1] - cum[0] + MOD) % MOD;
          }
    }
  }
  
  cout << dp[N-1][0];
}