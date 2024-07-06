#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define ll long long
#define pb push_back
constexpr int N = 1e5 + 3;
int n , i , tmp1 , tmp2;
vector<vector<int>> edge(N);
vector<int> color(N);
vector<int> pa(N);
vector<ll> ans(N);
vector<unordered_map<int, ll>> tree(N);
void build(int now , int fa) {
    pa[now] = fa;
    for(auto &p : edge[now]) {
        if(p == pa[now]) continue;
        build(p , now);
    }
}
void dfs(int now) {
    tree[now][color[now]]++;
    ll anss=0 , mx_cnt = 1;
    // cerr << "now: " << now << endl;
    for(auto &p : edge[now]) {
        if(p == pa[now]) continue;
        dfs(p);
        for(auto & k : tree[p]) {
            tree[now][k.first] += k.second;
            mx_cnt = max( mx_cnt , tree[now][k.first]);
        }
        tree[p].clear();
    }
    // cerr << mx_cnt << endl;
    for(const auto & p : tree[now]) {
        // cerr << p.first << ' ' << p.second << endl;
        if(p.second == mx_cnt) {
            anss+=p.first;
        }
    }
    ans[now] = anss;    
}


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(i = 1 ; i <= n ; i++) {
        cin >> color[i];
    }
    for(i = 0 ; i < n - 1 ; i++) {
        cin >> tmp1 >> tmp2;
        edge[tmp1].pb(tmp2);
        edge[tmp2].pb(tmp1);
    }
    build(1, 0);
    dfs(1);
    for( i = 1 ; i <= n ; i++) {
        cout << ans[i] << " \n"[i==n];
    }
    return 0;

}