#include <bits/stdc++.h>
using namespace std;
#define ishowspeed ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0);
#define INF (int)1e18
struct node{
    int v, u, c;
};
void solve() {
    int n, x, y; cin >> n >> x >> y;
    vector<int> dis(n+1, INF);
    vector<node> edge;
    int a , b , c;
    for(int i = 0 ; i < x ; i++) {
        cin >> a >> b >> c;
        edge.push_back({a , b , c});
    }
    for(int i = 0 ; i < y ; i++) {
        cin >> a >> b >> c;
        edge.push_back({b , a , -c});
    }
    bool ans = 0;
    dis[1] = 0;
    for(int i = 1 ; i <= n ; i++) {
        bool re = false;
        for(auto &tmp : edge) {
            if(dis[tmp.v] != INF)
            if(dis[tmp.v] + tmp.c < dis[tmp.u]) {
                dis[tmp.u] = dis[tmp.v] + tmp.c;
                re = true;
            }
        }
        if(i == n && re) ans = 1;
    }
    if(ans) {
        cout << -1 << endl;
        return ;
    }
    if(dis[n] == INF) {
        cout << -2 << endl;
        return ;
    }
    cout << dis[n] << endl;
    return;
}
int32_t main() {
    ishowspeed
    int t ; cin >> t;
    while(t--) {
        solve();
    }
}