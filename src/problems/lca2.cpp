#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define ishowspeed ios_base::sync_with_stdio(0);cin.tie(0);
#define pb push_back
#define mk make_pair
#define pii pair<int,int>
#define ll long long
const int N = (ll)1e5+2; 
vector<vector<pii>> con(N);
unordered_map<int,bool> vis;
const int N2 = log2(N);
int anc[N][N2];
int dis[N][N2];
int logN;
vector<int> in(N);
vector<int> out(N);
int ans = 0;
int timing = 1;
inline void timing_tag(int now) {
    in[now] = timing++;
    vis[now] = 1;
    for(auto i : con[now]) {
        if(i.first != now && !vis[i.first])
            timing_tag(i.first);
    }    
    out[now] = timing++;
}
inline bool is_ancestor(int x , int y) { // if x is y's ancestor
    return (in[x] <= in[y] && out[x] >= out[y]);
}
void dfs(int now,int fa){
    anc[now][0]=fa;
    for(auto [nxt,val]:con[now]){
        if(nxt == fa)continue;
        dfs(nxt, now);
        dis[nxt][0]=val;
    }
}
inline int getlca(int x, int y){
    if(is_ancestor(x, y))return x; // 如果 u 為 v 的祖先則 lca 為 u
    if(is_ancestor(y, x))return y; // 如果 v 為 u 的祖先則 lca 為 u
    for(int i=logN;i>=0;i--){    // 判斷 2^logN, 2^(logN-1),...2^1, 2^0 倍祖先
        if(!is_ancestor(anc[x][i], y) ) {
            if(anc[x][i])
                x = anc[x][i];
        } 
    }
    return anc[x][0]; // 回傳此點的父節點即為答案
}

inline void addlca(int x, int y){
    for(int i=logN;i>=0 && x != y ; i--){    // 判斷 2^logN, 2^(logN-1),...2^1, 2^0 倍祖先
        if(is_ancestor(y , anc[x][i])) {
            ans = max ( ans , dis[x][i] );
            x = anc[x][i];
            // i = logN;
        }
    }
} 
inline void make_chart(int N) {
    for(int j=1;j<=logN;j++){
        for(int i=1;i<=N;i++){
            anc[i][j]=anc[anc[i][j-1]][j-1];
            if(dis[i][j])
                dis[i][j] = min(dis[i][j] , dis[i][j-1] + dis[anc[i][j-1]][j-1]);
            else
                dis[i][j]= dis[i][j-1] + dis[anc[i][j-1]][j-1] ;
        }
    }
}
vector<int> k(N, 0); // 入度
void solve() {
    int n;
    cin >> n;
    logN = log2(n);
    int tmp1 , tmp2 , tmp3;
    int minn_index = 1 , record_min{INT32_MAX};
    for(int i = 1 ; i < n ; i++) {
        cin >> tmp1 >> tmp2 >> tmp3;
        con[tmp1].pb(mk(tmp2 , tmp3));
        k[tmp2]++;
        if(anc[tmp2][0]) {
            int k = tmp1;
            tmp1 = tmp2;
            tmp2 = k;
        }
        anc[tmp2][0] = tmp1;
        dis[tmp2][0] = tmp3;
    }
    int min_index {INT32_MAX}, minn {INT32_MAX};
    for(int i = 1 ; i <= n ; i++) {
        if(minn > k[i]) {
            min_index = i;
            minn = k[i];
        }
    }
    for(int i = 1 ; i <= n ; i++ ) {
        for(auto j : con[i]) {
            dfs(j.first  , i) ;
        }
    }
    timing_tag(minn_index);
    make_chart(n);
    int q;
    cin >> q;
    while(q--) {
        cin >> tmp1 >> tmp2;
        int lca = getlca(tmp1 , tmp2);
        addlca(tmp1 , lca);
        addlca(tmp2 , lca);
        cout << ans << endl;
        ans = 0;
    }
}

signed main() {
    ishowspeed
    solve();
    return 0;
}