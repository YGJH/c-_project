#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define mmax(a,b) (a>b)?a:b
#define pb push_back
#define ishowspeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
void solve() {
	int n , m ;
	cin >> n >> m;
	string s;
	cin >> s;
	vector<int> dp(n + 1 , INF);
	dp[0] = -1;
	for(int i = 1 ; i <= n ; i++) {
		if(s[i] == '1')
			continue;
		else {
			for(int j = mmax(i - m, 0) ; j<i;j++) {
				if(s[j] == '0' && dp[j]!=INF) {
					dp[i] = j;
					break;
				}
			}
		}
	}
	if(dp[n] == INF) {
		putchar('-') ; putchar('1');
	}
	else {
		int now = n;
		stack<int> ans;
		while(now!=0) {
			ans.push(now - dp[now]);
			now = dp[now];
		}
		while(!ans.empty()) {
			cout << ans.top() << ' ';
			ans.pop();
		}
	}

}

signed main() {
	ishowspeed
	solve();
	return 0;
}

