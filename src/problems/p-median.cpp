#include <bits/stdc++.h>
using  namespace std;
%:define mk make_pair
%:define int long long
%:define pii pair<int,int>
%:define ishowspeed ios_base::sync_with_stdio(0);cin.tie(0);
%:define endl '\n'
int kk = 1;

vector<vector<int>> dp(202 , vector<int>(202,0));
vector<vector<int>> d(202 , vector<int>(202,0));
vector<vector<int>> r(202 , vector<int>(202,0));
void solve(int N , int P) {

		int arr[203];
		for(int i = 1 ; i <= N ; i++) 
			cin >> arr[i];
		for(int i = 1 ; i <= N ; i++ )
			for(int j = i ; j <= N  ; j++) {
				int m = (i + j) >> 1;
				d[i][j] = 0;
				for(int k = i ; k <= j ; k++) 
					d[i][j] += abs(arr[k] - arr[m]);
	
			}
		for(int i = 1 ; i <= N ; i++)
			dp[1][i] = d[1][i];
		for(int i = 1 ; i <= N ; i++) 
			r[1][i] = 1;

		for(int i = 2 ; i <= P ; i++) {
			for(int j = N ; j >= 1 ; j--) {
				dp[i][j] = INT32_MAX;
				for(int k = i ; k <= j ; k++) {
					if(dp[i-1][k-1] + d[k][j] < dp[i][j]) {
						dp[i][j] = dp[i-1][k-1]+d[k][j];
						r[i][j] = k;
					}
				}
			}

		}
		int sum = dp[P][N];
	
		stack<pii> ans;

		int en = N;
		int now = r[P][N];
		int cnt = P;
		cout << "Chain " << kk++ << endl;
		while(cnt > 0) {
			ans.push(mk(now , en));
			en = now - 1;
			now = r[--cnt][now-1];
		}
		int cn = 1;
		while(!ans.empty()){
			auto now = ans.top();
			ans.pop();
			if(now.first != now.second)
				cout << "Depot " << cn++ << " at restaurant " << ((now.first+now.second)>>1) << " serves restaurants " << now.first << " to " << now.second << endl;
			else {
				cout << "Depot " << cn++ << " at restaurant " << now.first << " serves restaurant " << now.first << endl;

			}
		}
		cout << "Total distance sum = " << sum << endl << endl;
}
signed main() {
	ishowspeed
	int a, b;

	while(cin >> a >> b) 
		if(a == 0 && b == 0)
			return 0;
		else
			solve(a ,b);
	return 2;
}
