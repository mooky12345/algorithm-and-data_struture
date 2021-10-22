#include<bits/stdc++.h>
using namespace std;
 
const int N = 2e5 + 10;
int n, m, fa[N], ans[N], c[N];
struct Node{int l, r, x;} a[N];
 
 
bool cmp(Node a, Node b) {return a.r < b.r;}
 
int Get(int x) {
	if(x == fa[x]) return x;
	return fa[x] = Get(fa[x]);
}
 
void Add(int x) {for(; x <= n; x += x & -x) c[x] ++;}
int Ask(int x) {int sum = 0; for(; x; x -= x & -x) sum += c[x]; return sum;}
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i = 1; i <= n; i ++) fa[i] = i;
	for(int i = 1; i <= m; i ++)
		cin>>a[i].l>>a[i].r>>a[i].x;
	sort(a + 1, a + m + 1, cmp);
	for(int i = 1; i <= m; i ++) {
		int lim = a[i].x - (Ask(a[i].r) - Ask(a[i].l - 1));
		for(int j = 1; j <= lim; j ++) {
			int u = Get(a[i].r);
			Add(u), ans[u] = 1;
			fa[u] = Get(u - 1);
		}
	}
	for(int i = 1; i <= n; i ++)cout<<ans[i]<<" ";
}