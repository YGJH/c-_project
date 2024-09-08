#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 int n ;
 ll dp[(int)1e6+3];
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n ;
    for(int i = 1 ; i <= n ; i++){
        dp[i] = 1e9;
    }
    dp[0]=0;
    for(int i = 2 ; i <= n ; i++) {
        for(int k = i ; k ; k /= 10) {
            if(k>0) dp[i] = min(dp[i-(k%10)]+1 , dp[i]);
        }
    }
    cout << dp[n] << endl;
}