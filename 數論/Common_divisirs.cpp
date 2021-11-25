#include <bits/stdc++.h>
using namespace std;
 
int cnt[1000001];
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	while (n--) {
		int x; cin >> x;
		cnt[x]++;
	}
	for (int i = 1000000; i; i--) {
		int div = 0;
		for (int j = i; j <= 1000000; j += i) div += cnt[j];
		if (div > 1){
            cout << i;
            return 0;  
        } 
	}
	return 0;
}