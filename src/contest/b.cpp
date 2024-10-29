#include<bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n , k;
	cin >> n >> k;
	int sum = 0;
	int tmp;
	for(int i = 0 ; i < n ; i++) {
		cin >> tmp;
		if(tmp < 0) {
			sum += tmp;
		}
		else if(k > 0) {
			sum += tmp * -1;
			k--;
		}
		else {
			sum += tmp;
		}
	}
	cout << sum << endl;
}