#include<iostream>
using namespace std;
void getnext(string p,int a[]){
	int len = p.size();
	int i = 0;
	int j = -1;
	int next[0] = -1;
	while(i<len){
		if(j == -1 || p[i]==p[j]){
			i++;
			j++;
			next[i] = j;
		}
		else{
			j = next[j];
		}
	}
}
void kmp(string s,string p,int next[]){
	int i=0;
	int j=0;
	int len = s.size();
	int len1 = p.size();
	while(i<len && j<len1){
		if(j==-1 || s[i] == p[j]){
			i++;
			j++;
		}
		else{
			j = next[j];
		}
		if(j==len1){
			return i - j;
		}
	}
	return -1;
	
}
int main(){
	int next[100];
	
} 
