#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,M=31*100010;
#define ll long long
ll f[110][110];
 
int main(){
    ll a,b,k;cin>>a>>b>>k;
    int n=a+b;
    f[0][0]=1;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=i;j++)
            if(j) f[i][j]=f[i-1][j]+f[i-1][j-1];
            else f[i][j]=f[i-1][j];
    ll now=k;
    while(n--){
        if(f[n][a-1]<now) cout<<'b',now-=f[n][a-1],b--;
        else cout<<'a',a--;
        //cout<<now<<endl;
    }
 
    return 0;
}