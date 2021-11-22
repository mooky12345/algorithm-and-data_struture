#include<bits/stdc++.h>
#define pii pair<int,int>
#define ll long long int
#define f first
#define s second
#define inf 99999999
#define pb push_back
#define intt __int128_t
#define AC ios::sync_with_stdio(0);cin.tie(0);
using namespace std;
const int MX = 100005;
int n,m,k;
priority_queue<ll> bes[MX];
vector<pii> adj[MX];
priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k;
	for(int i=0;i<m;i++) {
		int a,b,c; cin >> a >> b >> c;
		adj[a].pb({b,c});
	}
	bes[1].push(0); pq.push({0,1});
	while (pq.size()) {
		auto a = pq.top(); pq.pop();
		if (a.f > bes[a.s].top()) continue;
		for (auto& i: adj[a.s]) {
			ll tmp = a.f+i.s;
			if (bes[i.f].size() < k) {
				bes[i.f].push(tmp);
				pq.push({tmp,i.f});
			} else if (tmp < bes[i.f].top()) {
				bes[i.f].pop();
				bes[i.f].push(tmp);
				pq.push({tmp,i.f});
			}
		}
	}
	vector<ll> ans;
	while (bes[n].size()) {
		ans.pb(bes[n].top());
		bes[n].pop();
	}
	reverse(ans.begin(),ans.end());
	for (auto a: ans) cout << a << " ";
}
