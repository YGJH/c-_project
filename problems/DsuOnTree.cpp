#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
constexpr int N = 1e5 + 3;
int n , i , tmp1 , tmp2;
vector<vector<int>> edge(N);
vector<int> color(N);
vector<int> pa(N);
void build(int now , int fa) {
    pa[now] = fa;
    for(auto &p : edge[now]) {
        if(p == pa[now]) continue;
        build(p , now);
    }
}
vector<int> ans(N);
vector<unordered_map<int,int>> tree(N);
void dfs(int now , int fa) {
    tree[now][color[now]]++;
    // cerr << "LLLLL" << endl;
    for(auto &p : edge[now]) {
        if(p == pa[now]) continue;
        dfs(p , now);
        if(tree[p].size() > tree[now].size()) {
            swap(tree[p] , tree[now]);
            for(const auto &jk : tree[p]) {
                tree[now][jk.first] += jk.second;
            }
        }
        else {
            for(const auto &jk : tree[p]) {
                tree[now][jk.first] += jk.second;
            }
        }
    }
    // cerr << now << " fin " << ans[now] << endl;
    int tmp1 , mx = 0;
    for(const auto & p : tree[now]) {
        mx = max(mx , p.second);
    }
    // cerr << now << ' ' << mx << endl;
    ans[now] = 0;
    for( const auto &p : tree[now]) {
        if(p.second == mx) {
            cerr << p.first << ' ' << p.second << endl;
            ans[now] += p.first;
        }
    }
}


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
    build(1, 0);
    dfs(1 , 0);
    for( i = 1 ; i <= n ; i++) {
        cout << ans[i] << " \n"[i==n];
    }
    return 0;

}