#include <bits/stdc++.h>
using namespace std;
 
int n, m, s, t, w, z;
int e[401][401], d1[401], d2[401], a[160000];
queue<int> Q;
 
int f(int v, int d[401]) {
	fill(d, d + n + 1, 500);
	d[1] = 0;
	Q.push(1);
 
	while (!Q.empty()) {
		int k = Q.front();
        Q.pop();
        for (int i = 1; i <= n; i++) {
			if (e[k][i] > 0 && e[k][i] != v) {
				if (d[i] > d[k] + 1) {
					d[i] = d[k] + 1;
					Q.push(i);
				}
			}
		}
	}
 
	if (d[n] == 500)
		return -1;
 
	return d[n];
}
 
int main()
{
	cin >> n >> m;
 
	for (int i = 0; i < m; i++) {
		cin >> s >> t;
		e[s][t] = i + 1;
	}
 
	z = f(0, d1);
	fill(a, a + m + 1, z);
 
	if(z > 0){
		w = n;
        while (w != 1) {
			for (int i = 1; i <= n; i++) {
				if (e[i][w] > 0 && d1[i] == d1[w] - 1) {
					int u = e[i][w];
                    a[u] = f(u, d2);
					w = i;
					break;
				}
			}
		}