#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define ll long long int
#define fast ios::sync_with_stdio(0); cin.tie(0);
#define pii pair<int,int>
#define inf 9999999
using namespace std;

ll a1[100001];
ll maxx = -999999;
ll ans =0 ;
int main(){
	fast
	int a,b;
	cin>>a>>b;
	for(int i=0;i<a;i++){
		cin>>a1[i];
		maxx = max(maxx,a1[i]);
	} 
	ll r = maxx,l = 0;
	while(r>l){
		ll cnt = 0;
		ll mid = l+(r-l)/2; 
		for(int i=0;i<a;i++){
			cnt += max(a1[i]-mid,(ll)0);
		}
		if(cnt>=b){
			l = mid+1;
		}
		else{
			r = mid;
		}
	}
	cout<<r;
	for(int i =0;i<a;i++){
		if(a1[i]<r)continue;
		b -= a1[i]-k+1;
		if(b<=0){
			k += -b;
		}
		ans += (a1[i]-k+1)*(k+a1[i])/2;
		
	}
	cout<<ans;
}

