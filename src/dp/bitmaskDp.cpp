#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int MOD  = 1e9+7;
int n;
constexpr int MXN = 21;
int dp[1<<MXN+1];
bool bo[MXN+1][MXN+1];

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            cin >> bo[i][j];
        }
    }
    dp[0] = 1;
    for(int i = 0 ; i < (1<<n) ; i++) {
        int fe = __builtin_popcount(i);
        for(int j = 0 ; j < n ; j++) {
            if(i&(1<<j)) continue;
            if(!bo[fe][j]) continue;
            dp[i|(1<<j)] += dp[i];
            dp[i|(1<<j)] %= MOD;
        }
    }
    cout << dp[(1<<n)-1] << endl;
}