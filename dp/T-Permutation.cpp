#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (ll i = a; i < b; i++)
#define rrep(i, a, b) for (ll i = b - 1; a <= i; i--)
ll MOD = 1000000007;
 
ll N, dp[3010][3010], cum[3010];
string s;
 
int main () {
  cin >> N;
  cin >> s;
  
  rep(i, 0, N) dp[0][i] = 1;
  rep(i, 1, N) {
    rep(j, 0, N) cum[j+1] = (dp[i-1][j] + cum[j]) % MOD;
    rep(j, 0, N-i) {
      if (s[i-1] == '<') {
        dp[i][j] = (cum[N-i+1] - cum[j+1] + MOD) % MOD;
        
      } else {
        dp[i][j] = (cum[j+1] - cum[0] + MOD) % MOD;
        
      }
    }
  }
  
  cout << dp[N-1][0];
}