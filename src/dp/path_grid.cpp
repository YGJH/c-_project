#include <bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr int MOD = 1e9+7;
int dp[1001][1001];
char bo[1001][1001];
    int n ;
int main() {
    cin >> n;
    memset(dp , 0 , sizeof(dp));
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1; j <= n ; j++) {
            cin >> bo[i][j];
        }
    }
    for(int i = 0 ; i <= n ; i++) {
        dp[i][0]=1;
        dp[0][i]=1;
    }
    
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1; j <= n ; j++) {
            if(bo[i][j] == '*') {
                dp[i][j] == 0;
            }
            else if(i == 1) {
                dp[i][j] += dp[i][j-1];
                dp[i][j] %= MOD;
            } else if(j == 1) {
                dp[i][j] += dp[i-1][j];
                dp[i][j] %= MOD;
            } else {
                dp[i][j] += dp[i-1][j];
                dp[i][j] %= MOD;
                dp[i][j] += dp[i][j-1];
                dp[i][j] %= MOD;
            }
        }
    }
    cout << dp[n][n] << endl;
    
}