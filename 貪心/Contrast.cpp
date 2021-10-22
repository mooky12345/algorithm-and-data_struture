#include<bits/stdc++.h>
using namespace std;
int a1[300005];
int b1[300005];
int main(){
    int a;cin>>a;
    for(int i=1;i<=a;i++)cin>>a1[i];
    for(int i=a;i>=1;i--)cin>>b1[i];
    for(int i=1;i<=a;i++){
        if(a1[i]==b1[i]){
            bool flag = false;
            for(int j=1;j<=a;j++){
                if(a1[i] != b1[j] && a1[j] != b1[i]){
                    swap(b1[i],b1[j]);
                    flag = true;
                    break;
                }
            }
            if(!flag){
                cout<<"No";
                return 0;
            }
        }
    }
    cout<<"Yes"<<"\n";
    for(int i=1;i<=a;i++){
        cout<<b1[i]<<" ";
    }
}
