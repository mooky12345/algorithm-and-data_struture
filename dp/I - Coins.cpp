#include<bits/stdc++.h>
#define pii pair<int,int>
#define ll long long int
#define f first
#define s second
#define inf 9999999
#define pb push_back
#define fast ios::sync_with_stdio(0);cin.tie(0);
using namespace std;
 
 
 
double a1[100000];
double dp[2][10000];
int main(){
	fast
	int a;
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>a1[i];
	}
	dp[1][0] = 1-a1[1];
	dp[1][1] = a1[1];
	for(int i=2;i<=a;i++){
	for(int j=0;j<=i;j++){
				dp[0][j] = dp[1][j]; 
			}
		for(int j=0;j<=i;j++){
			
			if(j==0){
				dp[1][j]=dp[0][j]*(1-a1[i]);
			}
			else{
				dp[1][j] = dp[0][j-1]*a1[i]+dp[0][j]*(1-a1[i]);
			}
		}
	
		
	}
	double res = 0;
	for(int i=(a/2)+1;i<=a;++i){
		res+=dp[1][i];
	}
	cout<<fixed<<setprecision(10)<<res;
}
