#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define ll long long int
#define fast ios::sync_with_stdio(0); cin.tie(0);
#define pii pair<int,int>
#define inf 9999999
using namespace std;int a;
string str;
string f(){
	queue<string> q;
	for(int i=0;i<=25;i++){
		char s = 'a'+i;
		string o;
		o.pb(s);
		q.push(o);
	}
	while(!q.empty()){
		string st;
		st = q.front();
		//cout<<st<<" ";
		q.pop();
		if(str.find(st) == str.npos){
			return st;
			break;
		}
		for(int i=0;i<=25;i++){
			char s = 'a'+i;
			string o = st;
			o.pb(s);
			q.push(o);
			
		}
	}
}


int main(){
	int t;cin>>t;
	while(t--){
		cin>>a;
		cin>>str;
		cout<<f()<<"\n";
	}
}

