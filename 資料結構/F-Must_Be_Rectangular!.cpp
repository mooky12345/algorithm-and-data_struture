#include<bits/stdc++.h>

#define ULL unsigned long long 
#define ll long long 
using namespace std;
 

const ULL base = 233;
const int N = 100005;
 
int n;
int f[201000];
ll val1[200100],val2[201000];
int find(int x){return f[x]==x?x:(f[x]=find(f[x]));}
 
int main(){
    cin>>n;
    for(int i =1;i<=2*N;i++)f[i]=i;
    for(int i=1;i<=n;i++){
        int x,y;
        cin>>x>>y;
        f[find(x)]= find(y+N);
    }
    for(int i=1;i<=N;i++)val1[find(i)]++;
    for(int i=N+1;i<=2*N;i++)val2[find(i)]++;
    ll ans=0;
    for(int i=1;i<=2*N;i++){
        ans+=val1[i]*val2[i];
        //if(val1[i]*val2[i])cout<<ans<<" "<<i<<" "<<i-N<<endl;
    }
    cout<<ans-n<<"\n";
}