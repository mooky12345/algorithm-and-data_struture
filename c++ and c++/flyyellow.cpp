#include<iostream>
using namespace std;
int main(){
	int a;
	cin>>a;
	int temp,temp1,sum,pivot = 0;
	int x[10],y[10];
	for(int i = 0;i<a;i++){
		cin>>x[i]>>y[i];
		if(i > 0){
			for(int j = i;j>=1;j--){
				if(x[j]<x[j-1]){ 
					temp = x[j];
					x[j] = x[j - 1];
					x[j - 1] = temp;
					temp1 = y[j];
					y[j] = y[j - 1];
					y[j - 1] = temp1;
				}
				else{
					break;
				} 
			}		
		}
	}
	for(int i = 0;i<a-1;i++){
		if(y[i]<y[i+1])
			sum+=1;
		else{
			sum = 0;
			}
		if(sum>pivot){
			pivot = sum;
		}		
		
			
	}
	cout<<pivot+1;
}
