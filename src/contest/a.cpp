#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<pair<int,int>> dp(n ,{0, 0});
    for(int i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }
    int mx = 0;
    for(int i = 0 ; i < n ; i++) {
        for(int j = i ; j < n ; j+=2) {
            dp[i].second++;
            dp[i].first = max(dp[i].first , arr[j]);
        }
        for(int j = i - 2; j > 0 ; j-=2) {
            dp[i].second++;
            dp[i].first = max(dp[i].first , arr[j]);
        }
        mx = max(mx , dp[i].first + dp[i].second);
    }
    cout << mx << endl;
}


signed main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;
    while(n--) {
        solve();
    }


    return 0;
}