#include<bits/stdc++.h>
#define ll long long int
using namespace std;
bool cmp(ll a,ll b){
    return a>b;
}
ll a1[10000][4];
int main(){
    int a;
    int b;
    cin>>a>>b;
    for(int i=1;i<=a;i++){
        for(int j=1;j<=3;j++){
            cin>>a1[i][j];
        }
    }
    ll ans = 0;
    for(int i=0;i<8;i++){
        ll f[10000] = {};
        for(int j=1;j<=a;j++){
            int tmp = i;
            for(int u=1;u<=3;u++){
                if(tmp%2==1) f[j] += a1[j][u]; 
                else f[j]-=a1[j][u];
                tmp/=2;
            }
        }
        sort(f+1,f+a+1,cmp);
        ll sum = 0;
        for(int j=1;j<=b;j++)sum+=f[j];
        ans = max(ans,sum);
    }
    cout<<ans;
}