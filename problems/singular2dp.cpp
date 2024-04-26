#include <bits/stdc++.h>
using namespace std;
#define ing long long
#define ishowspeed ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define mk make_pair
#define pii pair<int,int>
#define all(x) (x).begin(),(x).end();

const int N = 5002;
//vector<vector<vector<int>> dp(N , vector<vector<int>(N , vector<int>(1 , 0)));// blocks sum (left x to choose)
int dp[N][N][N];	       // blocks - 1 
//bool check() {
// check all block have at least one choosen
//}
void solve() {
// k is blocks
// x is how many to choosen
	int n , k , x;
	cin >> n >> k >> x;
	vector<int> arr(n+1);
	for (int i = 1 ; i <= n ; i++ )
		cin >> arr[i];

	for(int i = x ; i > 0 ; i--) {
		for(int j = 0 ; j <= n ; j++) {
			for(int k = 0 ; k < i ; k++) {
				dp[i][j][k] += arr[j];
			}
		}
	}
	for(int i = x ; i > 0 ; i--) {
		for(int j = 0 ; j <= n ; j++) {
			for(int k = 0 ; k < i ; k++) {
				cerr << dp[i][j][k] << " \n"[k==i-1];
			}
		}
	}	

}
signed main() {
	ishowspeed
	solve();
	return 0;
}
