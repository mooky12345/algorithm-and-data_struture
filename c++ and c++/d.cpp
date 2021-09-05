#include <iostream>
#include<string>
using namespace std;
int main(){
	int N,S = 0;
	string str;
	cin>>str;
	for(int i = 0;i<str.length();i++){
		S += (int)str[i];
		cout<<str[i]<<endl;
	}
	cout<<S;
	return 0;
} 
