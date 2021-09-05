#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define ll long long int
#define fast ios::sync_with_stdio(0); cin.tie(0);
#define pii pair<int,int>
#define inf 9999999
using namespace std;
vector<int> v;

int f(ll pos){
	int ret = 0;
	while(pos){
		ret += pos%10;
		pos /= 10;
	}
}

int main(){
	fast
	cin>>a>>b>>a1>>b1;
	v.pb(0);
	for(int i=a;i<=b;i++){
		v.pb(f(a));
	}
	sort(v.begin(),v.end());
	for(int i=1;i<b-a+1;i++){
		v[i] = v[i]+v[i-1];
	}
	for(int i=0;i<a<;i++){
		v[]
	}
}

