#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
#define mk make_pair
#define endl '\n'
const int N = 2e5+100;
vector<vector<int>> edg(N);
int arr[N];
int n , q , i , tmp1 , tmp2 , tmp3 , timing = 1;
int in[N];
int val[N];
int out[N];
unordered_map<int,bool> vis;
#define lowbit(x)  x&-x
struct Binary_Indexed_Tree{
    int n;
    vector<long long> bit;

    void init(int _n){
        n = _n+1;
        bit = vector<long long>(n,0);
    }
    void update(int x,int v){
        for(; x<n; x+=lowbit(x)){
            bit[x] += v;
        }
    }
    long long query(int x){
        long long ret = 0;
        for(; x>0; x-=lowbit(x)){
            ret += bit[x];
        }
        return ret;
    }
}BIT;
void dfs(int u){
    vis[u]=1;
    val[u] = arr[u];
    in[u] = ++timing;//這時進入u
    BIT.update(in[u] , arr[u]);
    for(int nxt : edg[u]){//跑過所有孩子
        if(!vis[nxt])
            dfs(nxt);
    }
    out[u] = timing;
    BIT.update(out[u]+1, -val[u]);
}


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for( i = 1  ; i <= n ; i++) {
       cin >> arr[i];
    }
    for( i = 1 ; i < n ; i++) {
        cin >> tmp1 >> tmp2;
        edg[tmp1].pb(tmp2);
        edg[tmp2].pb(tmp1);
    }
    BIT.init(n+100);
    BIT.update(1 , 0);
    dfs(1);
    for(int i = 1 ; i <= n ; i++) {
        cerr << i << ": " << in[i] << ' ' << out[i] << endl;
    }
    // for(int i = 1 ; i <= n ; i++) {
    //     cout << i << ": " << BIT.query(in[i]) << endl;
    // }
    for (i = 0 ; i < q ; i++) {
        cin >> tmp1;
        if(tmp1 == 1) {
            cin >> tmp2 >> tmp3;
            BIT.update(in[tmp2]  , -val[tmp2] + tmp3);
            // BIT.update(in[tmp2]  , tmp3);
            BIT.update(out[tmp2] + 1,val[tmp2] - tmp3);
            val[tmp2] = tmp3;
            // BIT.update(out[tmp2] + 1, -tmp3);
        }
        else {
            cin >> tmp2;
            cout << BIT.query(in[tmp2]) << endl;
        }
        // for(int i = 1 ; i <= n ; i++) {
        //     cout << i << ": " << BIT.query(in[i]) << endl;

        // }
    }
     return 0;
}