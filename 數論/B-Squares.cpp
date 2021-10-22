#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int MOD = 998244353;
 
ll n;
int main(){
	cin >> n;
	ll ans = 0;
	for(ll p = 1; p * p <= n; p++)
		(ans += ceil((n / p - p + 1) / 2.0)) %= MOD;
	cout << ans << endl;
}