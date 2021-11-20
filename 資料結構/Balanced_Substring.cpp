#include<bits/stdc++.h>
#define ll long long
using namespace std;
map<int,int> m;
int n;
string s;
int main()
{
	int sum=0;
	int ans=0;
	cin>>n;
	cin>>s;
	m[0]=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='0') sum--;
		else sum++;
		if(m[sum]!=0||sum==0) ans=max(i-m[sum]+1,ans);
		else m[sum]=i+1;
	}
	cout<<ans<<endl;
}