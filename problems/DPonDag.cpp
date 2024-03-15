#include <bits/stdc++.h>
#define ishowspeed ios_base::sync_with_stdio(0),cin.tie(nullptr);
using ll = long long;
#define endl '\n'
#define int long long
#define MOD 1000000009
#define mmin(a,b) (a<b)?a:b
using namespace std;
const int N=1e5+5;
long long xx[] = {-1 , 0 , 1 };
int cas = 1;
int n;
vector<vector<int>> dp(N, vector<int> (5,0));
vector<vector<int>> arr(N, vector<int> (5,0));
void solve() {
	for(int i = 1 ; i <= n ; i++) {
		for(int j = 1 ; j <= 3; j++) {
			cin >> arr[i][j];
			dp[i][j] = arr[i][j];
		}
	}
int tmp;
int tmp2;
	for(int i = 2 ; i < n ; i++) {
		for(int j = 1; j<=3 ;j++) {
			if(i != 2) {
				tmp2 = INT32_MAX;
				for(int k = 0 ; k < 3; k++) {
					tmp = j + xx[k];
					if(tmp >= 1 && tmp <= 3)
						tmp2 = mmin(dp[i-1][tmp] + dp[i][j], tmp2);
				}
				dp[i][j] = tmp2;
			}
			else {
				dp[i][j] = dp[1][2] + dp[i][j];
			}
		}
	}
	tmp2 = INT32_MAX;
	for(int i = 0 ; i < 3; i++ ){
		tmp2 = mmin(tmp2 , dp[n][2] + dp[n-1][i+1]);
	}
	dp[n][2] = tmp2;
	cout << cas++ << ". " << dp[n][2] << endl;
}
signed main() {

    ishowspeed
	while(cin >> n) {
		if(n == 0) {
			return 0;
		}
		solve();
	}
    return 0;
}