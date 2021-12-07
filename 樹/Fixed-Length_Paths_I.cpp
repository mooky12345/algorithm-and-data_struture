#include<bits/stdc++.h>
#define pii pair<int,int>
#define ll long long int
#define inf 99999999
#define pb push_back
#define AC ios::sync_with_stdio(0);cin.tie(0);
using namespace std;


int n, k, root, rootpre, u[200005], sz[200005], cnt[200005], dis[200005];
long long ans;
vector <int> v[200005], used;
  
void find_root(int x, int pre, int siz){
    int mx = 0;
    sz[x] = 0;
    for (int i:v[x]){
        if (u[i]) continue;
        if (i == pre) continue;
        find_root(i, x, siz);
        sz[x] += sz[i];
        mx = max(mx, sz[i]);
    }
    sz[x] += 1;
    mx = max(mx, siz-sz[x]);
    if (mx <= siz/2){
        root = x;
        rootpre = pre;
    }
}
  
void dfs(int x, int pre, int d){
    used.push_back(x);
    if (k >= dis[x]) ans += d*cnt[k-dis[x]];
    cnt[dis[x]]++;
    for (int i:v[x]){
        if (u[i]) continue;
        if (i == pre) continue;
        dis[i] = dis[x]+1;
        dfs(i, x, d);
    }
}
  
void solve(int x, int siz){
    find_root(x, -1, siz);
    if (rootpre != -1) sz[rootpre] = siz-sz[root];
    dis[root] = 0;
    u[root] = 1;
    dfs(root, -1, 1);
    while (used.size()){
        cnt[dis[used.back()]] = 0;
        dis[used.back()] = 0;
        used.pop_back();
    }
    for (int i:v[root]){
        if (u[i]) continue;
        dis[i] = 1;
        dfs(i, root, -1);
        while (used.size()){
            cnt[dis[used.back()]] = 0;
            dis[used.back()] = 0;
            used.pop_back();
        }
    }
    for (int i:v[root]){
        if (u[i]) continue;
        solve(i, sz[i]);
    }
}
  
int main() {
    AC
    cin >> n >> k;
    for (int i = 1, a, b; i < n; i++){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    solve(1, n);
    cout << ans << "\n";
}