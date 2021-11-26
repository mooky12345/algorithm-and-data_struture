#include<bits/stdc++.h>
#define pii pair<int,int>
#define ll long long int
#define f first
#define s second
#define inf 99999999
#define pb push_back
#define AC ios::sync_with_stdio(0);cin.tie(0);
using namespace std;



int a1[200010];
int b1[200010] = {};
int main(){
	AC
	int a,b;cin>>a>>b;
	for(int i=1;i<=b;i++)cin>>a1[i];
	int j = 1;
	for(int i=1;i<b;i++){
		cout<<a1[i]<<" ";
		b1[a1[i]] = 1;
		while(b1[j]) j++;
		if(j<a1[i]){
			cout<<j<<" ";
			b1[j] = 1;
			while(b1[j])j++;
		}
	}
	for(int i=a;i>=1;i--)if(!b1[i])cout<<i<<" ";
}
                                          