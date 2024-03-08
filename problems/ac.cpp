#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ishowspeed ios::sync_with_stdio(0),cin.tie(0);
signed main(){
    ishowspeed
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> arr(n+5);
    for(int i  = 1 ; i <=n;i++) cin >> arr[i];
    vector<int> dp(n+5);
    for(auto &c:dp) c = -1;
    dp[0] = 0;
    for(int i = 1; i <= n;i++){
        int mn = INT64_MAX;
        int mxn = INT64_MIN;
        for(int j = i;j > i - m && j >= 1;j--) {
            mxn = max(mxn,arr[j]);
            mn = min(mn,arr[j]);
        }
        for(int j = i - m;j >= 0;j--){
            if(mxn-mn <= k && dp[j] >= 0){
                dp[i] = j;
                break;
            }
            if(j >= 1){
                mxn = max(mxn,arr[j]);
                mn = min(mn,arr[j]);
            }
        }
    }
    vector<int> ans;
//???

    for(auto I:dp){
        cerr << I << ' ';
    }
    if(dp[n] == -1) cout << "-1\n";
    else {
        int y = n;
            while(true){
            int x = dp[y];
            ans.push_back(y - x);
            y = x;
            if(y == 0) break;
        }
        reverse(ans.begin(),ans.end());
        int s = ans.size();
        if(s < 2) {
            cout << -1 << '\n';
            return 0;
        }
        cout << s << '\n';
        for(auto c : ans) cout << c<< ' ';
    }
    putchar('\n');
    return 0;
}