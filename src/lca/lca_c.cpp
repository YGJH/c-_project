#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define int long long 
#define pb push_back
constexpr int MXN = 2e5 + 5;
int anc[MXN][25];
int ancsum[MXN][25];
int t = 0;
vector<pair<int,int>> edges[MXN];
int in[MXN] , out[MXN];
bool isanc(int u , int v) {
    return ((in[u] <= in[v]) && (out[v] <= out[u]));
}
void initancs(int n) {
    for ( int i = 1 ; i < 20 ; i++) {
        for(int j = 1 ; j <= n ; j++) {
            anc[j][i] = anc[anc[j][i-1]][i-1];
            ancsum[j][i] = max(ancsum[anc[j][i-1]][i-1] , ancsum[j][i-1]);
        }
    }
}
void dfstime(int u , int f) {
    in[u] = t++;
    for (auto [c,v] : edges[u]) {
        if(c != f) {
            dfstime(c , u);
            ancsum[c][0] = v;
            anc[c][0] = u;
        }
    }
    out[u] = t++;
}
int n , q , e;

void solve() {
    int u , v , a;
    t = 0;
    for(int i = 0 ; i <= n+5 ; i++) {
        edges[i] = vector<pair<int,int>>();
    }
    for(int i = 0 ; i < 20 ; i++) {
        for(int j = 0 ; j <= n + 5 ; j++) {
            anc[j][i] = 0;
            ancsum[j][i] = 0;
        }
    }
    for(int i = 0 ; i < n -1 ; i++) {
        cin >> u >> v >> a;
        edges[u].push_back({v , a});
        edges[v].push_back({u, a});
    }
    anc[1][0] = 1;
    dfstime(1,1);
    initancs(n);
    cin >> q;
    int b;
    while(q--) {
        cin >> a >> b;
        int x = a;
        int ans = 0;
        if(isanc(a , b)) {
            int x = b;
            for (int i = 19 ; i >= 0 ; --i) {
                if(!isanc(anc[x][i] , a)) {
                    ans = max(ans , ancsum[x][i]);
                    x = anc[x][i];
                }
            }
            ans = max(ans , ancsum[x][0]);
            cout << ans << '\n';
            continue;
        }
        if(isanc(b,a)) {
            swap(a ,b);
            int x = b;
            for(int i = 19 ; i >= 0 ; --i) {
                if(!isanc(anc[x][i] , a)) {
                    ans = max(ans , ancsum[x][i]);
                    x = anc[x][i];
                }
            }
            ans = max(ans , ancsum[x][0]);
            cout << ans << '\n';
            continue;
        }
        while(1) {
            for ( int i = 19 ; i >= 0 ; i--) {
                if(!isanc(anc[x][i] , b)) {
                    ans = max(ans , ancsum[x][i]);
                    x = anc[x][i];
                }
            }
            if(isanc(anc[x][0] , b)) {
                ans = max(ans , ancsum[x][0]);
                break;
            }
        }
        swap(a , b);
        x = a;
        while(1) {
            for(int i = 19 ; i >= 0 ; i--) {
                if(!isanc(anc[x][i] , b)) {
                    ans = max(ans , ancsum[x][i]);
                    x = anc[x][i];
                }
            }
            if(isanc(anc[x][0] , b)) {
                ans = max(ans , ancsum[x][0]);
                break;
            }
        }
        cout << ans << '\n';
    }
}
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(cin >> n)
        if(n) solve();
    return 0;    
}