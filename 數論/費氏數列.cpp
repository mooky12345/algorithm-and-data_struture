#include<bits/stdc++.h>
#define pii pair<int,int>
#define X first
#define Y second
#define pb push_back
#define ll long long int 
#define fast cin.tie(0); ios::sync_with_stdio(0);
using namespace std;
 
int x1, x2, a, b, n, mod = 1e9+7;
struct mat{
    long long a[2][2];
    mat(){
        memset(a, 0, sizeof(a));
    }
    mat operator * (const mat &b)const{
        mat ret;
        for (int i = 0; i < 2; i++){
            for (int j = 0; j < 2; j++){
                for (int k = 0; k < 2; k++){
                    ret.a[i][j] = (ret.a[i][j] + a[i][k] * b.a[k][j]) % mod;
                }
            }
        }
        return ret;
    }
};
 
int main() {
    while (cin >> x1 >> x2 >> a >> b >> n){
        mat ret;
        ret.a[0][0] = x1;
        ret.a[1][0] = x2;
        mat p;
        p.a[0][0] = 0;
        p.a[0][1] = 1;
        p.a[1][0] = a;
        p.a[1][1] = b;
        n--;
        while (n){
            if (n & 1){
                ret = p * ret;
            }
            p = p * p;
            n >>= 1;
        }
        cout << ret.a[0][0] << "\n";
    }
}