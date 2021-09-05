#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define ll long long int
#define fast ios::sync_with_stdio(0); cin.tie(0);
#define pii pair<int,int>
#define inf 9999999
using namespace std;

ll b1[2000000];
int main(){
	fast
	int t;cin>>t;
	while(t--){
	
	map<int,int> mp;
	vector<ll> a1; 
		int a;
	cin>>a;
	for(int i=0;i<a;i++){
		int aa;cin>>aa;
		a1.pb(aa);
	}
	for(int i=0;i<a;i++)b1[i] = a1[i];
	sort(a1.begin(),a1.end());
	a1.erase(unique(a1.begin(),a1.end()),a1.end());
	for(int i=0;i<a;i++){
		cout<<lower_bound(a1.begin(),a1.end(),b1[i])-a1.begin()+1<<" "; 
	}
	cout<<"\n";
	}
	
}

