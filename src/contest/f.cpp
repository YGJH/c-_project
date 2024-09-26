#include <bits/stdc++.h>
using namespace std;
#define int long long
int arr[(int)1e6+3];
int a[4];
int32_t main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n ;
	cin >> n;
	for(int i = 0 ; i < n ; i++) {
		cin >> arr[i];
	}
	int count = 0;
	for(int i = 0 ; i < n ; i++) {
		for(int j = 3 ; arr[i] < j ; j--) {
			count += a[j];
			// cout << a[arr[j]] << endl;
		}
		a[arr[i]]++;
	}
	cout << count << endl;
	return 0;
}