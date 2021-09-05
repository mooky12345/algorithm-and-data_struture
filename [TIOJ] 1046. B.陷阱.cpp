#include<bits/stdc++.h>
using namespace std;
string game[100];
int n,m;
int main(){
	string c;
	while(true){
		for(int n=0;;n++){
			if(c == c.size()){
				n = 0;
				break;
			}cin>>c;
			if(c=="#")break;
			game[n] = c;
			
		}
		
		if(c =="#")break;
		ans = dfs1(0);
		if(ans>=inf)
		else cout<<ans;
	}
}
