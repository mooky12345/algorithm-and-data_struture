#include<bits/stdc++.h>
#define pii pair<int,int>
#define X first
#define Y second
#define pb push_back
#define lli long long int 
#define fast cin.tie(0); ios::sync_with_stdio(0);
using namespace std;
const int mod = 1e9 + 7, N = 2000000;

lli modpow(lli a, lli b, lli m) {
    lli ans = 1;
    for (; b; b >>= 1, a = a * a % m) {
        if (b & 1) ans = ans * a % m;
    }
    return ans;
}

int main () {
    AC
    int t;
    cin >> t;
    while (t--) {
        lli mod, a, b, x1, y1, x2, y2;
        cin >> mod >> a >> b >> x1 >> y1 >> x2 >> y2;
        lli M = (y2 - y1) * modpow(x2 - x1, mod - 2, mod) % mod;
        if (M < 0) M += mod;
        lli K = y1 - M * x1 % mod;
        if (K < 0) K += mod;
        lli xsum = M * M % mod;
        lli x3 = (xsum - x1 - x2 + mod + mod) % mod;
        cout << x3 << ' ' << (x3 * M + K) % mod << endl;
    }
}