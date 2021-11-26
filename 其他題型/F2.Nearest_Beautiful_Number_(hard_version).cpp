#include<bits/stdc++.h>
#define pii pair<int,int>
#define ll long long int
#define f first
#define s second
#define inf 99999999
#define pb push_back
#define AC ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;



int f(int x){
	vector<int> tmp(10,0);
	int ans = 0;
	while(x){
		int ret = x%10;
		x/=10;
		tmp[ret]++;
	}
	for(int i=0;i<10;i++){
		if(tmp[i])ans++;
	}
	return ans;
}
int main(){
	AC
	int t;
	cin>>t;
	while(t--){
		int a,b;cin>>a>>b;
		while(f(a)>b){
			int s = a;
			int base = 1;
			while(f(s)>b){
				s /= 10;
				base *= 10;
			}
			base/=10;
			a = (a/base+1)*base;
			
		}
		cout<<a<<"\n";
	}
}