#pragma G++ optimize(3)
#pragma G++ optimize("-Ofast")
#pragma G++ optimize("inline")

// #include <bits/stdc++.h>
#include <iostream>
#define ll long long
#define fastio ios::sync_with_stdio(0), cin.tie(0)

using namespace std;
const int N = 21;
int dp[1 << N]; // 代表目前用了哪些男生(狀態壓縮)
int mp[N][N];
const int mod = 1e9 + 7;
void solve()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> mp[i][j];
        }
    }
    dp[0] = 1;
    for(int i = 0; i < (1 << n); i++) {
        int female_num = __builtin_popcount(i); // 現在要找第 female_num + 1 個女生的配對
        for(int j = 0; j < n; j++) {
            if((i & (1 << j))) continue; // 用過
            if(mp[female_num][j] == 0) continue; // isn't matching
            dp[i | (1 << j)] += dp[i];
            dp[i | (1 << j)] %= mod;
        }
    }
    cout << dp[(1 << n) - 1] << '\n';
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    solve();
    return 0;
}
