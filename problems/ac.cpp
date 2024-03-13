#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long

const int NMAX = 1e5 + 5;
const int INF = 1e18;

void solve(int n, int cnt) {
    int graph[n][3];
    int dp[n][3];
    for (int i = 0; i < n; i++)
        cin >> graph[i][0] >> graph[i][1] >> graph[i][2];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++)
            dp[i][j] = INF;

    dp[0][1] = graph[0][1];
    dp[0][2] = graph[0][1] + graph[0][2];
    for (int i = 1; i < n; i++) {
        dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + graph[i][0];
        dp[i][1] = min({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2], dp[i][0]}) + graph[i][1];
        dp[i][2] = min({dp[i - 1][1], dp[i - 1][2], dp[i][1]}) + graph[i][2];
    }
    // cout << dp[n - 1][1] << '\n';
    printf("%d. %d\n", cnt, dp[n - 1][1]);
}
signed main() {
    FASTIO;
    int n;
    int i = 1;
    while (cin >> n) {
        if (n == 0)
            break;
        solve(n, i);
        i++;
    }
}