#include<bits/stdc++.h>
#define pii pair<int,int>
#define ll long long int
#define x first
#define y second
#define inf 9999999
#define pb push_back
#define fast ios::sync_with_stdio(0);cin.tie(0);
using namespace std;
int a1[1000000];
int b1[1000000];
stack<int> st;
int main(){
	fast
	int a,b;
	cin>>a>>b;
	for(int i=1;i<=a;i++)cin>>a1[i];
	for(int i=1;i<=a;i++)cin>>b1[i];
	a1[0] = 0;
	a1[a+1] = b;
	b1[0] = 2e9;
	int maxx = -999999;
	int ans = 0; 
	for(int i=1;i<=a;i++){
		while(a1[st.top()] + b1[st.top()] <= a1[i]){
			ans ++;
			maxx = max(maxx,b1[st.top()]);
			st.pop();
		}
		if(a1[i]-b1[i] >= a1[i-1] || a1[i]+b1[i]<=a1[i+1]){
			ans++;
			maxx = max(maxx,b1[i]);
		}
		else{
			st.push(i);
		}
	}
	while(a1[st.top()] + b1[st.top()] <= b){
		ans ++;
		maxx = max(maxx,b1[i]);
		st.pop();
	}
	cout<<ans<<"\n"<<maxx;
}