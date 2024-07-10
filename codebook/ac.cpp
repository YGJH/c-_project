#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<ll , int , int> node;
typedef pair<int,int> pii;
vector<pii> G[2000];
ll E[20000];
priority_queue<node , vector<node> , greater<node>> dijk;
bitset<200005> vis;
ll dis[20000] ;
vector<int> ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n , m ; cin >> n >> m;
    for(int i = 1 , u , v ; i <= m ; i ++) {
        cin >> u >> v >> E[i];
        G[u].emplace_back(i, v);
        G[v].emplace_back(i, u);
    }
    memset(dis , 0x3f , sizeof(dis));
    dis[1] = 0;
    for ( const auto &nn : G[1]) {
        dijk.emplace(E[nn.first] , nn.second , nn.first);
    }
    while(dijk.size()) {
        auto {d , cur, ci} = dijk.top();
        dijk.pop();
        if(vis[cur]) continue;
        vis[cur] = 1;
        ans.push_back(ci);
        for ( const auto &[i , nxt] : G[cur]) {
            if(vis[nxt]) continue;
            if(d + E[i] < dis[nxt]) {
                dis[nxt] = d + E[i];
                dijk.emplace(d + E[i] , nxt , i);
            }
        }
    }
    for ( const auto & i : ans) cout << i << ' ';
    return 0;
}
