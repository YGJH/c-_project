#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

	int v[(int)1e6+3];
int32_t main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int n;
	cin >> n;
	int ar[n];
	int arr[(int)1e6+3];
	memset(arr , 0 , sizeof(arr));
	for(int i = 0 ; i < n ; i++) {
		cin >> ar[i];
		arr[ar[i]]++;
	}
	int mx = 1;
	for(int i = 1 ; i <= 1e6 ; i++) {
		for(int j = i ; j <= 1e6 ; j+=i) {
			if(arr[j]>=2) {
				mx = max(mx , j);
			}
		}
	}
	cout << mx << endl;

	return 0;
}