#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct Edge{
    int u , v , rd;
    ll w;
    Edge() : u(-1) , v(-1) , w(0) {}
    Edge(int _u , int _v , int _w , int _rd) : u(_u) , v(_v), rd(_rd) , w(_w) {}
    friend bool operator<(const Edge &a , const Edge &b) {
        return a.w > b.w;
    }
};


constexpr int MXN = 3e5;
vector<Edge> adj[MXN];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
    int n , m;
    cin >> n >> m;
    for (int i = 0 ; i < m ; i++) {
        int a , b , c;
        cin >> a >> b >> c; a-- , b--;
        adj[a].emplace_back(a , b , c , i);
        adj[b].emplace_back(b , a , c , i);
    }
    priority_queue<Edge> pq;
    vector<ll> dis(n , 1e18);
    vector<bool> vis(n , false);
    vector<int> ans;
    dis[0] = 0;
    pq.emplace(0 , 0 , 0 , -1);
    while(!pq.empty()) {
        auto cur = pq.top() ; pq.pop();
        if(vis[cur.v]) continue;
        vis[cur.v] = true;
        ans.push_back(cur.rd);
        for(auto &next: adj[cur.v]) {
            if(dis[next.v] > dis[next.u] + next.w) {
                dis[next.v] = dis[next.u] + next.w;
                pq.emplace(next.u , next.v , dis[next.v] , next.rd);
            }
        }
    }
    for( int i = 1 ; i < ans.size() ; i++) {
        cout << ans[i] + 1 << ' ';
    }
    
}