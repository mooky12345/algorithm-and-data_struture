#include<bits/stdc++.h>
using namespace std;
 
int n,l,r,m,ans;
char s[100100];
 
 
 
bool check(int x) {
	int left=-1,now=-1;
	for (int i=0;i<n;i++) {
		if (s[i]=='*'&&left==-1&&i>now) left=i;
		else if (s[i]=='P') {
			if (left==-1) now=i+x;
			else if (i-x>left) return 0;
			else if (left<i) now=max(left*2+x-i,i+(x-i+left)/2);
			else now=i+x;
			if (left<=now) left=-1;
		}
	}
	return left==-1;
}
 
int main()
{
	cin>>n>>s;
	l=1,r=2*n;
	while (l<=r) {
		m=(l+r)/2;
		if (check(m)) r=m-1, ans=m;	
		else l=m+1;
	}
	cout<<ans;
}