#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ishowspeed ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define ll long long
const int N = (ll)2e5 + 2;
vector<int> in(N , 0);
vector<vector<int>> anc(N , vector<int>( 19 , 0));
vector<int> out(N);
vector<vector<int>> con(N);
inline bool is_ancsent(int x , int y) { // x is y parent
    return (in[x] <= in[y] && out[x] >= out[y]);
}
int klo;
int timee = 1;
inline void dfs( int root ) {
    in[root] = timee++;
    for(auto i : con[root]) {
        dfs(i);
    }
    out[root] = timee++;
}

inline void f(int n) {
    for(int i = 1 ; i <= klo ; i++) {
        for(int j = 1 ; j <= n ; j++ ) {
            anc[j][i] = anc[anc[j][i-1]][i-1]; 
        }
    }
}
inline int getlca(int x, int y){
    if(is_ancsent(x, y))return x; // 如果 u 為 v 的祖先則 lca 為 u
    if(is_ancsent(y, x))return y; // 如果 v 為 u 的祖先則 lca 為 u
    for(int i=klo;i>=0;i--){    // 判斷 2^logN, 2^(logN-1),...2^1, 2^0 倍祖先
        if(!is_ancsent(anc[x][i], y) ) {
            if(anc[x][i])
                x = anc[x][i];
        } 
    }
    return anc[x][0]; // 回傳此點的父節點即為答案
}

void solve() {
    int n , q;
    cin >> n >> q;
    int tmp ;
    for (int i = 2; i <= n ;i++) {
        cin >> tmp;
        con[tmp].pb(i);
        anc[i][0] = tmp;
    }
    klo = log2(n);
    dfs(1);
    f(n);
    for(int i = 0 ; i <= n ; i++ ) { 
        for(int j = 0 ; j <= klo ; j++) {
            cerr << anc[i][j] << " \n"[j==klo];
        }
    }
    int a , b;
    while(q--) {
        cin >> a >> b;
        cout << getlca(a , b) << endl;
    }
}



signed main() {
    ishowspeed
    solve();

    return 0;
}