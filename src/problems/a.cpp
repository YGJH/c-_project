#include <bits/stdc++.h>
using namespace std;
#define mxn 20010
#define mxe 5000


vector<int> E[mxe];
vector<int> E2[mxe];
vector<int> in(mxe);
vector<int> in2(mxe);
// vector<int> sz(mxe , 1);
struct node{
    int val;
    bool em;
    node(){em=false;};
    node(int _val , bool _em){val=_val,em=_em;};
};
vector<node> t(mxe);
vector<node> t2(mxe);
// vector<int> fa(mxe);
// int find(int x) {
//     return (x == fa[x])?x : fa[x] = find(fa[x]);
// }
// void merge(int a, int b) {
//     int aa = find(a);
//     int bb = find(b);
//     if(aa == bb) {
//         return ;
//     }
//     sz[aa] += sz[bb];
//     fa[bb] = aa;
//     return;
// } 
bitset<mxe> vis;
bool fla = 0;
int df(int x) {
    int ret = 0;
    // cerr << x << ' ' << t[x].val << ' ' << t[x].em << endl;
    if(t[x].em==0) return t[x].val;
    if(E[x].empty()) return 1;
    for(auto &a : E[x]) {
        ret += df(a);
    }
    // cerr << x << ' ' << ret << endl;
    if(t[x].val == 0) t[x].val = ret;
    return t[x].val;
}

node dfs(int x) {
    if(vis[x])return node(0,0);
    vis[x] = 1;
    if(E[x].empty()) return node(1,0);
    node tmp ;
    for(auto &v : E[x]) {
        tmp = dfs(v);
        t[x].em |= tmp.em;
        t[x].val += tmp.val;
    }
    if(t[x].val == 0) t[x].em=1;

    return t[x].val == 0 ? node(1,t[x].em) : node(t[x].val+1,t[x].em); 
}


int df2(int x) {
    int ret = 0;
    // cerr << x << ' ' << t[x].val << ' ' << t[x].em << endl;
    if(t2[x].em==0) return t2[x].val;
    if(E2[x].empty()) return 1;
    for(auto &a : E2[x]) {
        ret += df2(a);
    }
    cerr << x << ' ' << ret << endl;
    // if(t2[x].val == 0) t2[x].val = ret;
    t2[x].val = max(ret , t2[x].val);
    return t2[x].val;
}

node dfs2(int x) {
    if(vis[x])return node(0,0);
    vis[x] = 1;
    if(E2[x].empty()) return node(1,0);
    node tmp ;
    for(auto &v : E2[x]) {
        tmp = dfs2(v);
        t2[x].em |= tmp.em;
        t2[x].val += tmp.val;
    }
    if(t2[x].val == 0) t2[x].em=1;

    return t2[x].val == 0 ? node(1,t2[x].em) : node(t2[x].val+1,t2[x].em); 
}



signed main() {
    cin.tie(0)->sync_with_stdio(0);
    // iota(fa.begin() , fa.end() , 0);
    int a , b , n , m;
    cin >> a >> b >> n >> m;
    int u , v;
    for(int i = 0 ; i < m ; i++) {
        cin >> u >> v;
        E[u].push_back(v);
        E2[v].push_back(u);
        in[v]++;
        in2[u]++;
    }

    vector<int> root;
    for(int i = 0 ; i < n ; i++) if(in[i]==0) root.push_back(i);

    vis.reset();
    for(auto &aa : root) dfs(aa);

    for(auto &aa : root) df(aa);
    
    for(int i = 0 ; i < n ; i++) cout << t[i].val << ' ';
    
    root.clear();
    vis.reset();
    for(int i = 0 ; i < n ; i++) if(in2[i]==0)root.push_back(i);
    cout << endl;

    for(auto &aa : root) dfs2(aa);

    for(auto &aa : root) df2(aa);
    for(int i = 0 ; i < n ; i++) cout << t2[i].val << ' ';
    


    return 0;
}