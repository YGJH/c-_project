#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
constexpr int N = 1e5+3;
vector<int> pa(N);
vector<vector<int>> edge(N);
vector<int> color(N);
unordered_map<int,int> tim;
unordered_map<int,bool> ds;
int n, i , ans , tmp1 , tmp2;
void dfs(int now , int fa) {
    pa[now] = fa;
    ds[now] = 1;
    for(auto p : edge[now]) {
        if(!ds[p]) {
            dfs(p , now);
        }
    }
}
int tar;
unordered_map<int,bool> vis;
int dfss(int now) {
    int ret = 0 ;
    vis[now] = 1;
    if(!ds[color[now]] && tim[color[i]] <= tar)
        ds[color[now]]=1 , ret += color[now];
    for(const auto &p : edge[now]) {
        if(pa[p] == now && !vis[p] ) {
            ret += dfss(p);
        }
    }
    return ret;
}


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(i = 1 ; i <= n ; i++) {
        cin >> color[i];
        tim[color[i]] ++;
    }
    for(i = 1 ; i < n ; i++) {
        cin >> tmp1 >> tmp2;
        edge[tmp1].pb(tmp2);
        edge[tmp2].pb(tmp1);
    }
    dfs(1 , 0);

    for(i = 1 ; i <= n ; i++ ) {
        ds.clear();
        vis.clear();
        tar = tim[color[i]];
        cout << dfss(i) << ' ';
    }
}