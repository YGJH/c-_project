#include <iostream>
#include <map>
#include <vector>
#define pb push_back
using namespace std;
#define ll long long
const int MXN = 1e5 + 1;
ll ans[MXN];
int color[MXN];
vector<vector<int>> edge(MXN);
map<ll , ll> sz[MXN];
map<int ,ll> bx[MXN];
int n, tmp1 , tmp2 , i ;
void dfs ( int now ,  int fa ) {
    int mx = 0 , sn = 0;
    for(auto &u : edge[now]) {
        if( u == fa ) continue;
        dfs( u , now );
        if( bx[ u ].size() > mx ) {
            mx = bx[ u ].size();
            sn = u;
        }
    }
    if( sn ) { swap (bx[now] , bx[sn]) , swap (sz[now] , sz[sn]); }
    bx[now][color[now]]++;
    sz[now][bx[now][color[now]]]+=color[now];
    for(auto &p : edge[now]) {
        if(p == sn || p == fa) continue;
        for(const auto &[a , b] : bx[p]) {
             bx[now][a] += b;
             sz[now][bx[now][a]]+=a;
        }
    }
    ans [ now ] = (prev(sz[now].end())) -> second; 
    return ;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(i = 1 ; i <= n ; i++) {
        cin >> color[i];
    }
    for(i = 1 ; i < n ; i++) {
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