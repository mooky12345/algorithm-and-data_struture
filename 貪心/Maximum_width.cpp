#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);
using namespace std;
int main(){
    fast
    int n,m;cin>>n>>m;
    string s,t;cin>>s>>t;
    vector<int> l(n),r(n);    
    for(int i=0,j=0;i<n&&j<m; i++)
        if(s[i]==t[j]) l[j++]=i;
    for(int i=n-1,j=m-1;i>=0&&j>=0;i--)
        if(s[i]==t[j]) r[j--]=i;
    int ans=0;
    for(int i=1;i<m;i++) ans=max(ans,r[i]-l[i-1]);
    cout<<ans<<"\n";
    return 0;
}