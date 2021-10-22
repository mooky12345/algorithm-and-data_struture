#include<bits/stdc++.h>
#define pii pair<int,int>
#define x first
#define y second
using namespace std;
int b;
int f(int u){
	if(u>=0&&u<=b-2){
		return 1;
	}
	else{
		return 0;
	}
}
int main(){
	int a;
	cin>>a;
	while(a--){
		int u,r,d,l,u1,r1,d1,l1;
		cin>>b>>u>>r>>d>>l;
		bool e=false;
		for(int i=0;i<(1<<4);i++){
			u1 = u;r1 = r;d1 = d;l1 = l;
			if(i&1){
				u1--;
				r1--;
			}
			if(i&2){
				r1--;
				d1--;
			}
			if(i&4){
				d1--;
				l1--;
			}
			if(i&8){
				l1--;
				u1--;
			}
			if(f(l1)&&f(d1)&&f(r1)&&f(u1)){
				e = true;
				break;
			}
		}
		if(e)cout<<"YES\n";
		else cout<<"NO\n";
	}
	
}