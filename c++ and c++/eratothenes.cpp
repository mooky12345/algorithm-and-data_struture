#include<iostream>
#include "memory.h"
using namespace std;
int main(){
	int n=99;
	int vis[100] ={};
	
	for(int i=2;i<=n;i++){
		for(int j=i*2;j<=n;j+=i){
			vis[j] = 1;
		}
	}
	for(int i=0;i<100;i++){
		if(!vis[i])
		cout<<i<<" ";
		
	}
}
