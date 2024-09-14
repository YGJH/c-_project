#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define endl '\n'
#define lowbit(x) x & -x
constexpr int MXN = (1 << 20) + 5, N = (1 << 20);
ll dp1[MXN], dp2[MXN], arr[MXN];
template<typename T>
inline void re(T &a) {
	a = 0;
	char c = getchar();
	while (c < '0' || c > '9')
		c = getchar();
	while (c >= '0' && c <= '9')
		a = (a << 1) + (a << 3) + (c & 15), c=getchar();
	return;
}
template<typename T>
inline void wr(T a) {
	char cm[10];
	int now = 0;
	while (a)
		cm[now++] = a % 10 + 48, a /= 10;
	while (now)
		putchar(cm[--now]);
	return;
}
int n;
int32_t main() {
	// ios_base::sync_with_stdio(0);
	// cin.tie(0);
	// cout.tie(0);
	// cin >> n;
	re(n);
	for (int i = 0; i < n; i++) {
		// cin >> arr[i];
		re(arr[i]);
		dp1[arr[i]]++, dp2[arr[i]]++;
	}
	for (int i = 0; i < 20; i++) {
		for (int mask = 0; mask < N; mask++) {
			if ((mask & (1 << i)))
				dp1[mask] += dp1[mask ^ (1 << i)];
			else
				dp2[mask] += dp2[mask ^ (1 << i)];
		}
	}
	for (int i = 0; i < n; i++) {
		wr(dp1[arr[i]]);
		putchar(' ');
		wr(dp2[arr[i]]);
		putchar(' ');
		wr(n - dp1[arr[i] ^ (N - 1)]);
        putchar('\n');
	}
	return 0;
}