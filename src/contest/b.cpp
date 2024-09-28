#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve() {
	int n, q;
	cin >> n >> q;
	map<int, int> mp;
	int tm;
	vector<int> v(n + 2, 0);
	mp[n - 1] += 2;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
    for(int i = 1 ; i <= n ; i++) {
        mp[(i)*(n-i)] += v[i] - v[i-1] - 1;
    }
	for (int i = 1; i + 1 < n; i++) {
		mp[(i + 1) * (n - i) - 1]++;
	}
	for (int i = 0; i < q; i++) {
		cin >> tm;
		cout << mp[tm] << ' ';
	}
	cout << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	while (n--) {
		solve();
	}

	return 0;
}