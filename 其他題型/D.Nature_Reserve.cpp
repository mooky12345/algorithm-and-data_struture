#include<bits/stdc++.h>
#define pii pair<int,int>
#define X first
#define Y second
#define pb push_back
#define ll long long int 
#define fast cin.tie(0); ios::sync_with_stdio(0);
using namespace std;
#define db double
const int M = 100005;
int n,f1,f2,x[M],y[M];
db Abs(db x)
{
	return x<0?-x:x;
}
bool check(db t)
{
	db l=-2e15,r=2e15;
	for(int i=1;i<=n;i++)
	{
		db dis=Abs(t-y[i]);
		if(dis>t) return 0;
		db s=sqrt((t-dis)*(t+dis));
		db ln=x[i]-s,rn=x[i]+s;
		if(rn<l || ln>r) return 0;
		l=max(l,ln);r=min(r,rn);
	}
	return 1;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i];
		if(y[i]>0) f1=1;
		else f2=1;
	}
	if(f1 && f2)
	{
		puts("-1");
		return 0;
	}
	for(int i=1;i<=n;i++)
		if(y[i]<0) y[i]=-y[i];
	db l=0,r=2e15,ans=0;
	for(int i=1;i<=888;i++)
	{
		db mid=(l+r)/2;
		if(check(mid)) ans=mid,r=mid;
		else l=mid;
	}
	cout<<ans;
}