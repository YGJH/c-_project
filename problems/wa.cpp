#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
constexpr int N = 1e5+1;
int n , i , tmp1 , tmp2;
#define max(a,b) (a>b)?a:b
vector<vector<int>> edge(N);
vector<int> color(N);
vector<ll> ans(N);
map<int ,ll> sz[N]; 
map<ll ,ll> appear[N];
void dfs(int now , int fa) {
    int mx_cnt = 0  , sn = 0;
    for(auto &p : edge[now]) {
        if(p==fa) continue;
        dfs(p , now);
        if(mx_cnt < appear[p].size()) {
            mx_cnt = appear[p].size() , sn = p;
        }
    }
    if(sn) {
        swap(appear[now] , appear[sn]);
        swap(sz[now] , sz[sn]);
    }
    // appear key = color , appear times;
    // size key = times , ans ;
    appear[now][color[now]]++;
    sz[now][appear[now][color[now]]] += color[now];
    for(auto &p : edge[now]) {
        if( p == fa || p == sn) continue;
        for(const auto &[a ,b] : appear[p] ) {
            appear[now][a] += b;
            sz[now][appear[now][a]] += a;
        }
    }
    ans [ now ] = (prev(sz[now].end()))->second;
    return;
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
    dfs(1 , 1);
    for( i = 1 ; i <= n ; i++) {
        cout << ans[i] << ' ';
    }
    return 0;

}