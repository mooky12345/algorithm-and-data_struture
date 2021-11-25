#include<bits/stdc++.h>
using namespace std;
const int N = 100000, M = 100000;
 
vector<int> rev[N+1]; 
int deg[N+1];
int label[N+1]; 
priority_queue<int> que;
 
int main()
{
    int n, m;
    cin>>n>>m;
    memset(deg, 0, sizeof deg);
    for(int f, t, i=0; i<m; ++i)
    {
        cin>>f>>t;
        rev[t].push_back(f);
        ++deg[f];
    }
    for(int i=1; i<=n; ++i)
        if(!deg[i])
            que.push(i);
    for(int lab=n, t; lab > 0; --lab) 
    {
        t = que.top();
        que.pop();
        label[t] = lab;
        for(int i=0; i<rev[t].size(); ++i)
            if(--deg[rev[t][i]] == 0)
                que.push(rev[t][i]);
    }
    for(int i=1; i<=n; ++i)
        cout<<label[i]<<" ";
    return 0;
}