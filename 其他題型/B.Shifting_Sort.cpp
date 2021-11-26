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




int main(){
	AC
	int t;
	cin>>t;
	while(t--){
		vector<vector<int>> ans1;
		vector<int> pos1;
		map<int,vector<int>> mp;
		int a;
		int a1[100];
		cin>>a;
		for(int i=1;i<=a;i++){
			cin>>a1[i];
			mp[a1[i]].pb(i);
		} 
		int pos = 1;
		int ans = 0;
		for(auto i:mp){
			for(int j:i.s){
				int cnt1 = a;
				int pos2 = j;
				int cnt2 = 0 ;
				for(int u:pos1){
					pos2 -= u;
					if(pos2<=cnt2){
						pos2 += cnt1;
					}
					cnt1--;
					cnt2++;
				}
				
				if(pos2 == pos){
					pos++;
					pos1.pb(0);
					continue;
				}
				pos1.pb(pos2 - pos);
				vector<int> tmp;
				tmp.pb(pos);tmp.pb(a);tmp.pb(pos2-pos);
				ans1.pb(tmp); 
				pos++;
				ans++;
			}
		}
		cout<<ans<<"\n";
		for(auto i:ans1){
			for(int j:i){
				cout<<j<<" ";
			}
			cout<<"\n";
		}
	}
}