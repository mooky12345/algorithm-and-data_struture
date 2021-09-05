#include<bits/stdc++.h>
using namespace std;
string str;
struct node{
	int count;
	int fail;
	int next[27];
	void init(){
		memset(next,-1,sizeof(next));
		fail = 0;
		count = 0;
	}
}s[100000];
int ins(){
	int len = strlen(str+1);
	int ind = 0,i,j;
	int num = 0;
	s[num].init(); 
	for(i=1;i<=len;i++){
		j = str[i]-'a';
		if(s[ind].next[j]==-1){
			num++;
			s[num].init();
			s[ind].next[j] = num; 
		}
		num = s[ind].next[j];
	}
	s[ind].count++;
    return 0;
}
int main(){
	
}
