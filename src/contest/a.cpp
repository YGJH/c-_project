#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
signed main() {
	int n;
	cin >> n ;
	int ans1 = 0 , ans2 =0 ;
	int arr;
	for(int i = 0 ; i <= n ; i++) {
		cin >> arr;
		ans1 += arr * (1 << (n - i));
	}
	for(int i = 0 ; i <= n ;i++) {
		cin >> arr;
		ans2 += arr * (1 << (n - i));
	}
	cout << ans1 <<  ' ' << ans2 << endl;
}