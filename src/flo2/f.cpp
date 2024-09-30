#include <bits/stdc++.h>
using namespace std;
#define int long long
#define SZ(X) (int)(X).size()
#define PB push_back
constexpr int MXN = 1e5+4;
constexpr int INF = 1e18;
struct Dinic
{
    struct Edge
    {
        int v, f, re;
    };
    int n, s, t, level[MXN];
    vector<Edge> E[MXN];
    void init(int _n, int _s, int _t)
    {
        n = _n;
        s = _s;
        t = _t;
        for (int i = 0; i < n; i++)
            E[i].clear();
    }
    void add_edge(int u, int v, int f)
    {
        E[u].PB({v, f, SZ(E[v])});
        E[v].PB({u, 0, SZ(E[u]) - 1});
    }
    bool BFS()
    {
        for (int i = 0; i < n; i++)
            level[i] = -1;
        queue<int> que;
        que.push(s);
        level[s] = 0;
        while (!que.empty())
        {
            int u = que.front();
            que.pop();
            for (auto it : E[u])
            {
                if (it.f > 0 && level[it.v] == -1)
                {
                    level[it.v] = level[u] + 1;
                    que.push(it.v);
                }
            }
        }
        return level[t] != -1;
    }
    int DFS(int u, int nf)
    {
        if (u == t)
            return nf;
        int res = 0;
        for (auto &it : E[u])
        {
            if (it.f > 0 && level[it.v] == level[u] + 1)
            {
                int tf = DFS(it.v, min(nf, it.f));
                res += tf;
                nf -= tf;
                it.f -= tf;
                E[it.v][it.re].f += tf;
                if (nf == 0)
                    return res;
            }
        }
        if (!res)
            level[u] = -1;
        return res;
    }
    int flow(int res = 0)
    {
        while (BFS())
            res += DFS(s, 2147483647);
        return res;
    }
} flow;

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n , m;
    cin >> n >> m;
    int wei[n];
    int tar = n + n + 1;
    constexpr int source = 0;
    flow.init(n + n + 3 , source , tar);
    for(int i = 1 ; i <= n ; i++) {
        cin >> wei[i];
        flow.add_edge(source , i , -wei[i]);
    }
    
    for(int i = 0 ; i < m ; i++) {
        int u , v , w;
        cin >> u >> v >> w;
        flow.add_edge(u , v , w);
    }
    for(int i = 1 ; i <= n ; i++) {
        flow.add_edge(i , tar , 1);
    }
    int ans = flow.flow();
    cout << ans << endl;

    return 0;
}