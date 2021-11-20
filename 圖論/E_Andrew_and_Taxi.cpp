#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=100005;
int n,m,mma,in[maxn],top[maxn];
struct node{
    int fr,to,val;
}e[maxn];
vector<int> ve[maxn],road;
int ck(int x){
    memset(in,0,sizeof(in));
    for(int i=1;i<=n;i++){ve[i].clear();}
    int now=0;
    for(int i=1;i<=m;i++){
        if(e[i].val>x){
            in[e[i].to]++;
            ve[e[i].fr].push_back(e[i].to);
        }
    }
    queue<int> q;
 
    for(int i=1;i<=n;i++){
        if(!in[i]){
            q.push(i);
            top[i]=++now;
        }
    }
    while(!q.empty()){
        int u=q.front(); q.pop();
        for(int i=0;i<ve[u].size();i++){
 
            int v=ve[u][i];

            if(--in[v]==0){
                q.push(v);
                top[v]=++now;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(in[i]) return 0;
    }
    return 1;
}
 
int main(){
    int x,y,z,mma=0;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>x>>y>>z;
        e[i].fr=x,e[i].to=y,e[i].val=z;
        mma=max(mma,z);
    }
    int l=0,r=mma,ans=-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(ck(mid)) {ans=mid; r=mid-1;}
        else l=mid+1;
    }
    ck(ans);
    for(int i=1;i<=m;i++){
        if(e[i].val<=ans){
            if(top[e[i].fr]>top[e[i].to]){
                road.push_back(i);
            }
        }
    }
    cout<<ans<<road.size();
    for(int i=0;i<road.size();i++)
        cout<<road[i]<< (i==road.size()-1?'\n':' ');
	return 0;
}