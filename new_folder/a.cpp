#include <bits/stdc++.h>
 
typedef long long ll;
using namespace std;

struct edge{
    int u , v , w;
};
constexpr int INF = 1e18;
constexpr int MXN = 2e5+5;
void solve() {
    int N , X , Y , A , B , C;
    vector<edge> v;
    vector<int? dis(N+1);
    for(auto & c : dis) c=INF;
    for(int i = 0 ; i < X ; i++) {
        cin >> A >> B >> C;
        v.emplace_back({B , A ,-C});
    }
    dis[1] = 0;
    int ans = 0;
    for(int i = 0 ; i <= N ; i++) {
        bool relaxed = false;
        for(auto &[u , v, w] : v) {
            if(dis[u] != INF) {
                if(dis[u] + w < dis[v]) {
                    dis[v] = dis[u] + w;
                    relaxed = true;
                }
            }
        }
        if(i == N && relaxed) ans = -1;
    }
    if(ans < 0){
        cout << "-1\n";
        return;
    }
    if(dis[N] == INF) {
        cout << "-2\n";
        return;
    }
    cout << dis[N] << endl;
    return ;
}           
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    itn t ;
    cin >> t;
    while(t--) {
        solve();
    }
}   