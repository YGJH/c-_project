#pragma G++ optimize(3)
#pragma G++ optimize("-Ofast")
#pragma G++ optimize("inline")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10, M = N * 2;
const int mod = 1e9 + 7;

ll x;

inline void solve()
{
    cin >> x;
    ll a = x >> 1;
    ll b = x * 2 - a;
    if ((a ^ b) == x)
        cout << a << ' ' << b << '\n';
    else
        cout << -1 << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int T;
    for (cin >> T; T--;)
        solve();
    return 0;
}
