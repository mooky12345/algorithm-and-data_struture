#include<bits/stdc++.h>
using namespace std;
int n,a1,b1,ans;
int st[55];
char cnt1[55];
int dp[55][55][55][55];
string s;
void dfs(int pos,int a,int b,int cnta){
    if(pos==n){
        if(!a && !b && cnta >= 1&& cnta < n){
            if(abs(n - cnta - cnta) < ans){
                ans = abs(n - cnta - cnta);
                for(int i=0;i<n;i++){
                    if(st[i] == 1){
                        cnt1[i] = 'B';
                    }
                    else{
                        cnt1[i] = 'R';
                    }
                }
            }
        }
        return;
    }
    if(dp[pos][a][b][cnta])return;
    dp[pos][a][b][cnta] = 1;
    st[pos] = 0;
	dfs(pos + 1, (a*10 + s[pos] - '0') % a1, b, cnta + 1);
	st[pos] = 1;
	dfs(pos + 1, a, (b*10 + s[pos] - '0') % b1, cnta);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        memset(dp,0,sizeof(dp));
        ans = 1e9;
        cin>>n>>a1>>b1;
        cin>>s;
        dfs(0,0,0,0);

        if(ans==1e9){
            cout<<-1<<"\n";
            continue;
        }
        else{
            for(int i=0;i<n;i++){
                cout<<cnt1[i];
            }
        }
        cout<<'\n';
    }
}
