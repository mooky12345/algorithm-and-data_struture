#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define ll long long int
#define ios::sync_with_stdio(0); cin.tie(0);
#define pii pair<int,int>
using namespace std;
int a;
vector<pii> v;
ll a1[200005];
ll bit1[200005];
ll bit2[200005];
vector<ll> ans;
int get(int x){
    return lower_bound(a1,a1+a, x)-a1+1;
}
void u1(ll pos){
	while(pos<=a){
		bit1[i]++;
		pos += pos&(-pos);
	}
}
ll q1(ll pos){
	ll ret = 0;
	while(pos){
		ret+=bit1[pos];
		pos-=pos&(-pos);
	}
}
void u2(ll pos){
	while(pos<=a){
		bit2[i]++;
		pos += pos&(-pos);
	}
}
ll q2(ll pos){
	ll ret = 0;
	while(pos){
		ret+=bit2[pos];
		pos-=pos&(-pos);
	}
}
int main(){

	cin>>a;
	memset(bit1,0,sizeof bit1);
	memset(bit2,0,sizeof bit2);
	for(int i=0;i<a;i++){
		cin>>a1[i];
	} 
	for(int i =0;i<a;i++){
		if(a1[i]%==1){
			u1(a1[i]);
			ans[i].pb(q1(a1[i]));
			ans[i].pb(q2(a1[i])); 
		}
		else{
			u2(a1[i]);
			ans[i].pb(q1(a1[i]));
			ans[i].pb(q2(a1[i]));
		}
	}
	memset(bit1,0,sizeof bit1);
	memset(bit2,0,sizeof bit2);
	for(int i=a-1;i>=0;i--){
		if(a1[i]%==1){
			u1(a1[i]);
			ans[i].pb(q1(get(a1[i])));
			ans[i].pb(q2(get(a1[i])));
		}
		else{
			u2(a1[i]);
			ans[i].pb(q1(get(a1[i])));
			ans[i].pb(q2(get(a1[i])));
		}
	}
	ll ans11 = 0; 
	for(int i=0;i<a;i++){
		if(a1[i]%2==1){
			ans11+=ans[0]*ans[3]+ans[2]*ans[1];
		}
		else{
			ans11+=ans[0]*ans[2]ans[1]*ans[3];
		}
	}
	cout<<ans;
}

