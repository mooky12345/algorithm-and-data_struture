#include <bits/stdc++.h>
using namespace std;
 
int n, q, a, b, s, t, k, d[100005], p[100005], sp[100005][18];
vector <int> v[100005];
 
void dfs(int x, int pre, int dep){
    d[x] = dep;
    p[x] = pre;
    sp[x][0] = pre;
    for (int i:v[x]){
        if (i == pre) continue;
        dfs(i, x, dep+1);
    }
}
int jump(int x, int steps){
    for (int i = 17; i >= 0; i--){
        if ((1<<i) <= steps){
            steps -= (1<<i);
            x = sp[x][i];
        }
    }
    return x;
}
int lca(int x, int y){
    if (d[x] > d[y]) swap(x, y);
    int gap = d[y]-d[x];
    for (int i = 17; i >= 0; i--){
        if ((1<<i) <= gap){
            gap -= (1<<i);
            y = sp[y][i];
        }
    }
    if (x == y) return x;
    for (int i = 17; i >= 0; i--){
        if (sp[x][i] != sp[y][i]){
            x = sp[x][i];
            y = sp[y][i];
        }
    }
    return sp[x][0];
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i < n; i++){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1, -1, 1);
    for (int i = 1; i < 18; i++){
        for (int j = 1; j <= n; j++){
            sp[j][i] = sp[sp[j][i-1]][i-1];
        }
    }
    for (int i = 0; i < q; i++){
        cin >> s >> t >> k;
        int l = lca(s, t);
        if (d[s]-d[l] >= k){
            cout << jump(s, k) << "\n";
            continue;
        }
        k -= d[s]-d[l];
        if (k > d[t]-d[l]){
            cout << -1 << "\n";
            continue;
        }
        cout << jump(t, (d[t]-d[l])-k) << "\n";
    }
}