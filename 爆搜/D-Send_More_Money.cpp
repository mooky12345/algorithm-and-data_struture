#include<bits/stdc++.h>
#define pii pair<int,int>
#define X first
#define Y second
#define pb push_back
#define ll long long int 
#define fast cin.tie(0); ios::sync_with_stdio(0);
using namespace std;
 
string a,b,c;
map<char,char> mp;
map<char,int> st;
int main(){
	string str;
	str = "0123456789";
	cin>>a>>b>>c;
	for(int i=0;i<a.size();i++)st[a[i]] = 1;
	for(int i=0;i<b.size();i++)st[b[i]] = 1;
	for(int i=0;i<c.size();i++)st[c[i]] = 1;
	if(st.size()>10){
		cout<<"UNSOLVABLE";
		return 0;
	}
	do{
		bool e = false;
		int j= 0;
		string f,g,h;
		for(auto i1:st){
			mp[i1.X] = str[j++];
		}
		if(mp[c[0]] == '0') e = true;
		if(mp[a[0]] == '0') e = true;
		if(mp[b[0]] == '0') e = true;
		if(e) continue;
		
		for(int i=0;i<a.size();i++){
			f.pb(mp[a[i]]);
			
		} 
		for(int i=0;i<b.size();i++){
			g.pb(mp[b[i]]);
			
		} 
		for(int i=0;i<c.size();i++){
			h.pb(mp[c[i]]);
			
		} 
		
		if(stol(f)+stol(g)==stol(h)){
			cout<<f<<"\n";
			cout<<g<<"\n";
			cout<<h<<"\n";
			return 0;
		}
	}while(next_permutation(str.begin(),str.end()));
	cout<<"UNSOLVABLE";
}