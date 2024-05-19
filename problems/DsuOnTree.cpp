#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
constexpr int N = 1e5 + 3;
int n , i , tmp1 , tmp2;
vector<vector<int>> edge(N);
vector<int> color(N);
vector<int> pa(N);

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(i = 0 ; i < n ; i++) {
        cin >> color[i];
    }
    for(i = 0 ; i < n - 1 ; i++) {
        cin >> tmp1 >> tmp2;
        edge[tmp1].pb(tmp2);
        edge[tmp2].pb(tmp1);
    }

}