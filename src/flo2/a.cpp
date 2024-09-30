#include <bits/stdc++.h>
using namespace std;
#define SZ(X) (long long)(X).size()
#define PB push_back
#define int long long
constexpr int MXN = 2000;
constexpr long long INF = 1e9;

vector<int> dp(1000 , 1);
vector<int> arr(1000);
struct Dinic{
  struct Edge{ int v,f,re; };
  int n,s,t,level[MXN];
  vector<Edge> E[MXN];
  void init(int _n, int _s, int _t){
    n = _n; s = _s; t = _t;
    for (int i=0; i<n; i++) E[i].clear();
  }
  void add_edge(int u, int v, int f){
    E[u].PB({v,f,SZ(E[v])});
    E[v].PB({u,0,SZ(E[u])-1});
  }
  bool BFS(){
    for (int i=0; i<n; i++) level[i] = -1;
    queue<int> que;
    que.push(s);
    level[s] = 0;
    while (!que.empty()){
      int u = que.front(); que.pop();
      for (auto it : E[u]){
        if (it.f > 0 && level[it.v] == -1){
          level[it.v] = level[u]+1;
          que.push(it.v);
    } } }
    return level[t] != -1;
  }
  int DFS(int u, int nf){
    if (u == t) return nf;
    int res = 0;
    for (auto &it : E[u]){
      if (it.f > 0 && level[it.v] == level[u]+1){
        int tf = DFS(it.v, min(nf,it.f));
        res += tf; nf -= tf; it.f -= tf;
        E[it.v][it.re].f += tf;
        if (nf == 0) return res;
    } }
    if (!res) level[u] = -1;
    return res;
  }
  int flow(int res=0){
    while ( BFS() )
      res += DFS(s,2147483647);
    return res;
} }flow, flow2;
vector<int> mx_node;
vector<int> tmp;
#define endl '\n'
int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n ;
    cin >> n;
    if(n==1) {
        cout << 1 << endl << 1 << endl << 1 << endl;
        return 0;
    }
    for(int i = 1 ; i <= n ; i++) {
        cin >> arr[i];
    }
    int mx = 1;
    for(int i = 1 ; i <= n ; i++) {
        for(int j = i+1 ; j <= n ; j++) {
            if(arr[i] <= arr[j]) {
                dp[j] = max(dp[i] + 1 , dp[j]);
                mx = max(mx , dp[j]);
            }
        }

    }
    for(int i = 1 ; i <= n ; i++) {
        if(dp[i] == 1) {
            tmp.push_back(i);
        }
        if(mx == dp[i]) {
            mx_node.push_back(i);
        }
    }
    cout << mx << endl;
    flow.init(n+n+45 , 0 , n+n+1);
    for(auto a : tmp) {
        flow.add_edge(0 , a , 1);
    }
    for(auto a : mx_node) {
        flow.add_edge(a+n , n + n+1 , 1);
    }
    for(int i = 1 ; i <= n ; i++) {
        flow.add_edge(i , i + n , 1);
        for(int j = i + 1; j <= n ; j++) {
            if(arr[i] <= arr[j] && dp[i] + 1 == dp[j]) {
                flow.add_edge(i+n , j, 1);
            }
        }
    }
    int ans2 = flow.flow();
    cout << ans2 << endl;
    flow2.init(n+n+45, 0 , n+n + 1);
    for(auto a : tmp) {
        if(a == 1) {
            flow2.add_edge(0 , a , INF);
        }else {
            flow2.add_edge(0 , a , 1);
        }
    }
    for(auto a : mx_node) {
        if(a == n){
            flow2.add_edge(a+n , n+n+1 , INF);
        }
        else {
            flow2.add_edge(a+n , n+n+1 , 1);
        }
    }
    for(int i = 1 ; i <= n ; i++) {
        if(i == 1 || i == n)
            flow2.add_edge(i  , i + n  , INF);
        else 
            flow2.add_edge(i  , i + n  , 1);
        for(int j = i + 1 ; j <= n ; j++) {
            if(arr[i] <= arr[j] && dp[i] + 1 == dp[j]) {
                // if(i == n) {
                //     flow2.add_edge(i+n , j, INF);
                // }
                // else {
                    flow2.add_edge(i+n , j, 1);
                // }
            }
        }
    }
    ans2 = 0;
    ans2 = flow2.flow();
    cout << ans2 << endl;

    return 0;

}